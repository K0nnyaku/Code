//Fuck CCF forever! 
#include <bits/stdc++.h>
using std::min; using std::max; using std::swap; using std::log; using std::abs; using std::sqrt; using std::sort; using std::unique; using std::pair; using std::make_pair;
using std::queue; using std::stack; using std::deque; using std::vector; using std::map; using std::set;
#define rep(_vr, _st, _ed) for(int _vr=(_st); (_vr)<=(_ed); (_vr)++)
template <class _Tp>
inline void read(_Tp &x) {
	int ch; do { ch=getchar(); } while (ch<'0' || ch>'9');
	x=0;
	while (ch>='0' && ch<='9') {
		x=(x*10)+(ch^48); ch=getchar();
	}
}
const int maxn=5e5, maxN=1e6;
int n, N;
int a[maxN+20]={0}, b[maxn+20]={0};
char ans[maxN+20]={0};
bool flag, TLE=0;
bool check(int pl, int pr) {
	rep (i, n+1, N) {
		if (b[N-i+1]==a[pl]) pl++, ans[i]='L';
		else if (b[N-i+1]==a[pr]) pr--, ans[i]='R';
		else return 0;
	}
	rep (i, 1, N) putchar(ans[i]);
	putchar('\n');
	return 1;
}
bool vis[maxn+20]={0};
void dfs(int dep, int pl, int pr) {
	if (dep==n+1) {
		if (check(pl, pr)) flag=1;
		return;
	}
	if (clock() > 900) { TLE=1; return; }
	if (!vis[a[pl]]) { vis[a[pl]]=1; ans[dep]='L'; b[dep]=a[pl]; dfs(dep+1, pl+1, pr); vis[a[pl]]=0; }
	if (flag || TLE) return;
	if (!vis[a[pr]]) { vis[a[pr]]=1; ans[dep]='R'; b[dep]=a[pr]; dfs(dep+1, pl, pr-1); vis[a[pr]]=0; }
	ans[dep]=0;
}
inline void dispatcher() {
	if (!TLE) {
		memset(vis, 0, sizeof(vis));
		flag=0;
		dfs(1, 1, N);
		if (!flag) printf("-1\n"); 
	} else printf("-1\n");
}
int main()
{
	freopen("palin.in", "r", stdin); freopen("palin.out", "w", stdout);
	int T; read(T);
	while (T--) {
		read(n); N=n<<1;
		rep (i, 1, N) read(a[i]);
		dispatcher();
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
