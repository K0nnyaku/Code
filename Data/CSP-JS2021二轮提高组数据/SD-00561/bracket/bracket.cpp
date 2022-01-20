#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int p=1e9 +7;
int n,k,ans;
char s[510],dp[510];
void dfs(int x,int z){
	if(x>n){
		int num[510]={};
		stack <int> st,ts,su;
		for(int i=1;i<=n;i++){
			if(dp[i]=='('){
				if(!ts.empty()){
					ts.pop();
				}
				st.push(i);
				num[i]=1;
			}
			else if(dp[i]=='*'){
				if(ts.empty()){
					if(i!=1){
						ts.push(i);
						continue;
					}else{
						return;
					}
				}
				num[ts.top()]++;
				if(num[ts.top()]>k){
					return ;
				}
			}
			else if(dp[i]==')'){
				if(st.empty()){
					return;
				}
				
				while(!su.empty()&&su.top()>st.top()){
					if(!ts.empty()){
					if(su.top()<ts.top()){
						ts.pop();	
					}
				}su.pop();
				}
				su.push(st.top());
				st.pop();
			}
		}
		if(st.empty()&&ts.empty()&&dp[n]==')'){
			ans++;ans%=p;
			//printf("%s\n",dp+1);
			return ;
		}
		
		
		return;
	}
	if(s[x]!='?'){
		dp[x]=s[x];
		if(s[x]=='(')
		dfs(x+1,z+1);
		else dfs(x+1,z);
		return ;
	}
	if(!z){
		dp[x]='(';
		dfs(x+1,z+1);
		return;
	}
	dp[x]='(';
	dfs(x+1,z+1);
	dp[x]='*';
	dfs(x+1,z);
	dp[x]=')';
	dfs(x+1,z-1);
	return ;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int zz=0;
	if(s[1]=='(')zz++;
	dfs(1,zz);
	
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
7 3
(*??*??
*/
