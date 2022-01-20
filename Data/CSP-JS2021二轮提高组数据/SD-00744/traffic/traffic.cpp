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
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
}
const int N=500+5;
int n, m, q, k, ans, v[N], t[N], id[N], c[N][N], h[N][N], col[N][N];
inline int getx(int qwq){
	if(qwq<=m) return 1;
	if(qwq>=m+n+1&&qwq<=m+m+n) return n;
	if(qwq>=m+1&&qwq<=m+n) return qwq-m;
	return n-(qwq-m-m-n)+1;
}
inline int gety(int qwq){
	if(qwq<=m) return qwq;
	if(qwq>=m+n+1&&qwq<=m+m+n) return m-(qwq-m-n)+1;
	if(qwq>=m+1&&qwq<=m+n) return m;
	return 1;
}
inline void dfs(int x, int y){
	if(x==n+1){
		int sum=0;
		for(int i=1; i<n; ++i)
			for(int j=1; j<=m; ++j)
				sum+=c[i][j]*(col[i][j]!=col[i+1][j]);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<m; ++j)
				sum+=h[i][j]*(col[i][j]!=col[i][j+1]);
		for(int i=1; i<=k; ++i)
			sum+=v[i]*(t[i]!=col[getx(id[i])][gety(id[i])]);
		ans=min(ans, sum);
		return ;
	}
	col[x][y]=0; dfs((y==m)?(x+1):(x), y%m+1);
	col[x][y]=1; dfs((y==m)?(x+1):(x), y%m+1);
	col[x][y]=0;
}
int main(){
	File();
	n=read(), m=read(), q=read();
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			c[i][j]=read();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			h[i][j]=read();
	while(q--){
		k=read(), ans=INF; memset(col, 0, sizeof col);
		for(int i=1; i<=k; ++i) v[i]=read(), id[i]=read(), t[i]=read();
		dfs(1, 1);
		printf("%d", ans);
	}
	return 0;
}

