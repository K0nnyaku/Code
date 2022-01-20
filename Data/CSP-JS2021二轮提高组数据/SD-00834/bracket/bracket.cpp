//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<stack>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e9+7;
int n,k,ans;
string s;
bool check(){
	int lst=0;
	stack<int> q;
	for(int i=0;i<n;i++){
		if(s[i]=='(') q.push(i),lst=i;
		else if(s[i]==')') {
			if(lst!=q.top()&&(s[q.top()+1]=='*'&&s[i-1]=='*')) return 0;
			q.pop();
			lst=i;
		}
	}
	return 1;
}
void dfs(int now,int len,int num){
	if((double)clock()/CLOCKS_PER_SEC>0.95){
		ans=0;
		return;
	}
	if(s[0]=='*'||s[n-1]=='*') return;
	if(now==n){
		if(num==0&&check()){
			ans++;
		}
		if(ans>=mod) ans-=mod;
		return;
	}
	if(n-now<num) return;
	if(s[now]=='(') dfs(now+1,0,num+1);
	if(s[now]==')'){
		if(!num) return;
		dfs(now+1,0,num-1);
	}
	if(s[now]=='*'){
		if(len+1>k) return;
		dfs(now+1,len+1,num);
	}
	if(s[now]=='?'){
		s[now]='(';
		dfs(now+1,0,num+1);
		if(num) s[now]=')',dfs(now+1,0,num-1);
		if(len+1<=k) s[now]='*',dfs(now+1,len+1,num);
		s[now]='?';
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k>>s;
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

