#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
const int mod=1e9+7;
int n,k;
int a[505];
char s[505];
string c;
unsigned long long ans;
int read(){
	int f=1,x=0;
	char c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return f*x;
}
void dfs(int now,int x,int l,int r,string c,int b){
	if(l>r+a[now]) return;
	if(now==n+1&&l==r) ans=(ans+1)%mod;
	if(s[now]=='*'){
		if(x==k) return;
		dfs(now+1,x+1,l,r,c+"*",b);
		return;
	}
	if(s[now]=='('){
		if(l+1>r+a[now+1]) return;
		if(s[now-1]=='*') dfs(now+1,0,l+1,r,c+"(",1);
		else dfs(now+1,0,l+1,r,c+"(",0);
		return;
	}
	if(s[now]==')'){
		if(l<=r) return;
		if(b==2) return;
		if(b==1&&s[now+1]=='*') dfs(now+1,0,l,r+1,c+")",2);
		else dfs(now+1,0,l,r+1,c+")",0);
		return;
	}
	if(now==1&&l+1<=r+a[now+1]){
		dfs(now+1,0,l+1,r,c+"(",0);
		return;
	}
	if(now==n){
		if(l!=r+1) return;
		if(b==2) return;
		dfs(now+1,0,l,r+1,c+")",0);
		return;
	}
	if(x!=k) dfs(now+1,x+1,l,r,c+"*",b);
	if(l>r&&b!=2){
		if(b==1&&s[now+1]=='*') dfs(now+1,0,l,r+1,c+")",2);
		else dfs(now+1,0,l,r+1,c+")",0);
	}
	if(l+1<=r+a[now+1]){
		if(s[now-1]=='*') dfs(now+1,0,l+1,r,c+"(",1);
		else dfs(now+1,0,l+1,r,c+"(",0);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("brachet.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i>=1;i--){
		if(s[i]=='?'||s[i]==')') a[i]=a[i+1]+1;
		else a[i]=a[i+1];
	}
	if(s[1]=='*'||s[1]==')'){
		cout<<0;
		return 0;
	}
	if(s[n]=='*'||s[n]=='('){
		cout<<0;
		return 0;
	}
	dfs(1,0,0,0,"",0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
