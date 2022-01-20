#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
#define ll long long
using namespace std;
int n,k; 
const int mod=1e9+7;
char s[1000];
char p[1000];
int ans;
stack<int>st;//0*  1(    2ok
bool check(){
	//for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
	while(st.size())st.pop();
	int num=0;int tag=0;
	for(int i=1;i<=n;i++){
		if(p[i]=='*')num++;
		else num=0;if(num>k)return false;
		if(p[i]=='*'){
			if(st.empty())return false;
			if(st.top()==0)continue;
			else st.push(0);
		}else if(p[i]=='('){
			st.push(1);tag++;
		}else{
			if(!tag)return false;tag--;
			int ls=st.top();st.pop();
			if(ls==1){
				st.push(2);
				continue;
			}
			int pre=-1;
			while(st.size()){		
				if(st.top()==1)break;
				pre=st.top();
				st.pop();
			}
			if(pre==ls and ls==0)return false;
			st.push(2);
		} 		
	}
	int w=st.top();
	int pr=-1;st.pop();
	while(st.size()){
		pr=st.top();st.pop();
	}
	if(w==0 or pr==0 or tag)return false;
	//for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
	return true;
}
void dfs(int step){
	
	if(step==n+1){
		if(check())ans++;
		return;
	}
	if(s[step]=='(' or s[step]=='*' or s[step]==')'){
		p[step]=s[step];
		dfs(step+1);
	}else{
		p[step]='(';
		dfs(step+1);
		p[step]='*';
		dfs(step+1);
		p[step]=')';
		dfs(step+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	dfs(1);cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

