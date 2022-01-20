#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring> 
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long 
using namespace std;
int t,n,fron,tai,flag=0;
int a[110],b[110];
string ans,temp;
stack<char> q;
stack<char> huanyuan;
int check(){
	for(int i=1;i<=n;i++) if(b[i]!=b[2*n+1-i]) return 0;
	return 1;
}
void dfs(int u){
	if(u==2*n){
		if(check()){
			stack<char> huanyuan;
			flag=1;
			string temp;
			while(!q.empty()){
				temp+=q.top();huanyuan.push(q.top());q.pop();
			}
			if(temp>ans) ans=temp;
			ans=temp;
			while(!huanyuan.empty()) q.push(huanyuan.top()),huanyuan.pop();
		}
		return ;
	}
	q.push('R');b[u+1]=a[tai--];dfs(u+1);tai++;q.pop();
	q.push('L');b[u+1]=a[fron++];dfs(u+1);fron--;q.pop();
	
	
}
void sol(){
	stack<char> final;
	char q[110];ans;
	scanf("%d",&n);fron=1,tai=2*n;
	flag=0;
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	dfs(0);
	if(flag){
		for(int i=ans.length()-1;i>=0;i--) printf("%c",ans[i]);
		printf("\n");
	}
	else printf("-1\n");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--) sol();
	
	
	
	
	
	return 0;
}
