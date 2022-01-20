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
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
}
const int N=500000+5;
int n, ext, a[N], b[N], op[N];
inline void dfs(int cur, int l, int r){
	if(ext) return ;
	if(cur==n+n+1){
		for(int i=1; i<=n; ++i) if(b[i]!=b[n+n-i+1]) return ;
		for(int i=1; i<=n+n; ++i) printf("%c", op[i]==1?'L':'R');
		printf("\n");
		ext=1;
		return ; 
	}
	b[cur]=a[l++], op[cur]=1, dfs(cur+1, l, r), --l, op[cur]=0;
	b[cur]=a[r--], op[cur]=2, dfs(cur+1, l, r), ++r, op[cur]=0;
}
int main(){
	File();
	int T=read();
	while(T--){
		n=read(), ext=0;
		for(int i=1; i<=n+n; ++i) a[i]=read();
		dfs(1, 1, n+n);
		if(!ext) printf("-1\n");
	}
	return 0;
}

