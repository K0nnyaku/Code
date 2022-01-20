#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
#define uLL unsigned long long
#define INF 0x3f3f3f3f
#define LL long long
inline int read(){
	int s=0, f=1; char c=getchar();
	while(!isdigit(c)) { if(c=='-') f=-f; c=getchar(); }
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c^48), c=getchar();
	return s*f;
}
inline void File(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
}
const int N=500+5, mod=1000000007;
int n, k, ans, sp[N];
char s[N];
inline void dfs(int cur){
	if(cur==n+1){
		if(s[1]!='('||s[n]!=')') return ;
		stack<int> lb; int cnt=0;
		for(int i=1; i<=n; ++i){
			if(s[i]=='('){
				++sp[lb.size()];
				lb.push(i);
				cnt=0;
			}
			if(s[i]==')'){
				if(lb.empty()) return ;
				int tp=lb.top(); lb.pop();
				if(s[i-1]==s[tp+1]&&i-tp-1>=4&&s[i-1]=='*'&&sp[lb.size()]) return ;
				sp[lb.size()]=0;
				cnt=0;
			}
			if(s[i]=='*'){
				++cnt;
				if(cnt>k) return ;
			}
		}
		if(lb.size()) return ;
		++ans;
		if(ans==mod) ans=0;
		return ;
	}
	char t;
	if(s[cur]=='('||s[cur]=='?') t=s[cur], s[cur]='(', dfs(cur+1), s[cur]=t;
	if(s[cur]==')'||s[cur]=='?') t=s[cur], s[cur]=')', dfs(cur+1), s[cur]=t;
	if(s[cur]=='*'||s[cur]=='?') t=s[cur], s[cur]='*', dfs(cur+1), s[cur]=t;
}
int main(){
	File();
	n=read(), k=read();
	scanf("%s", s+1);
	int ccc=0;
	for(int i=1; i<=n; ++i) ccc+=(s[i]=='?');
	if(!ccc) { printf("0"); return 0; }
	dfs(1);
	printf("%d", ans);
	return 0;
}
