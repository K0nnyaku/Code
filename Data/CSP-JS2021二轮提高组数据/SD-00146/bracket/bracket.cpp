#include<bits/stdc++.h>
using namespace std;
int n,k;
int zuo,xin,zong;
char q[505];
int ans;
void dfs(char x,int m){
	if(m>n-1){
		zuo--;
		zuo=abs(zuo);
		if(zuo%2==0)
		cout<<ans/(zuo/2);
		else cout<<ans/(zuo/2+1);
		return;
	}
	if(x=='?'){
		zong=ans;ans=0;
		if(xin<k){
			xin++;
			ans++;
		}
		else xin=0;
		if(zuo>0){
			zuo--;
			ans++;
		}
		zuo++;
		ans++;
		if(zong!=0) ans*=zong;
		dfs(q[m+1],m+1);
		return;
	}
	if(x=='*'){
		if(xin==k){
			ans--;
			xin==1;
			dfs(q[m+1],m+1);
			return;
		}
		else{
			xin++;
			dfs(q[m+1],m+1);
			return;
		}
	}
	if(x=='('){
		zuo++;
		xin=0;
		dfs(q[m+1],m+1);
		return;
	}
	if(x==')'){
		xin=0;
		if(zuo>0){
			zuo--;
			dfs(q[m+1],m+1);
			return;
		}
		else{
			ans--;
			dfs(q[m+1],m+1);
			return;
		}
	}
	
	
}
int main(){
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==0) cout<<0;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	if(q[n]=='?')	ans++;
	if(q[1]=='*'||q[1]==')'||q[n]=='*'||q[n]=='('){
		cout<<"0";
		return 0;
	}
	if(q[1]=='?'){
		ans++;
		zuo++;
		dfs(q[2],2);
	}
	else dfs(q[1],1);
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;	
}
//21!9-324@emb
