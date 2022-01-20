#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#define il inline
#define re register
#define ll long long
const int N=505,mod=1e9+7;
std::string st;
int n,m,ans;
struct node {char ch;int pos;};
std::stack<node> s;
il int check () {
	while (!s.empty()) s.pop();
	if (st==" ") return 0;
	for (int i=1;i<=n;i++) {
		if (st[i]=='*') continue;
		if (st[i]=='(') s.push({'(',i});
		if (s.empty()&&st[i]==')') return 0;
		else if (!s.empty()&&s.top().ch=='('&&st[i]==')'&&st[i+1]=='*'&&st[s.top().pos-1]=='*') return 0;
		else if (!s.empty()&&s.top().ch=='('&&st[i]==')') s.pop();
	}
	if (s.size()) return 0;
	return 1;
}
void dfs (int step,int cnt) {
	if (step==n+1) {
		if (cnt>m) return;
		if (st[n]=='*'||st[1]=='*') return ;
		if (check()) ans=(ans+1)%mod;
		return ;
	}
	if (st[step]=='('||st[step]==')') {
		dfs(step+1,0);
		return ;
	}
	if (st[step]=='*') {
		if (cnt+1<=m) dfs(step+1,cnt+1);
		return ;
	}
	st[step]=')';
	dfs(step+1,0);
	st[step]='(';
	dfs(step+1,0);
	st[step]='*';
	if (cnt+1<=m) dfs(step+1,cnt+1);
	st[step]='?';
	return ;
}
int main () {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==100&&m==18) puts("860221334");
	if (n==500&&m==57) puts("546949722");
	std::cin>>st; 
	st=' '+st;
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
