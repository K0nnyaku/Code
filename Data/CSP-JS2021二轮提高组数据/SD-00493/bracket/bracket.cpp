//Fuck all sb workers in China Cheating Foundation(CCF)!
#include <bits/stdc++.h>
using std::min; using std::max; using std::swap; using std::log; using std::abs; using std::sqrt; using std::sort; using std::unique; using std::pair; using std::make_pair;
using std::queue; using std::stack; using std::deque; using std::vector; using std::map; using std::set;
#define rep(_vr, _st, _ed) for(int _vr=(_st); (_vr)<=(_ed); (_vr)++)
typedef long long ll;
inline int readch() {
	int ch; do { ch=getchar(); } while (!isgraph(ch));
	return ch;
}
template <class _Tp>
inline void read(_Tp &x) {
	int ch; do { ch=getchar(); } while (ch<'0' || ch>'9');
	x=0;
	while (ch>='0' && ch<='9') {
		x=(x*10)+(ch^48); ch=getchar();
	}
}
const ll MOD=1e9+7;
int n, k;
char a[600]={0};
ll ans=0;
int eqrange=0;
typedef short i16;
stack<int> s;
void dfs(i16 dep, i16 br, i16 cpp) {
	if (br<0 || cpp>k) return;
	if (dep==n+1) {
		if (!cpp && br==0) {
			ans=(ans+1)%MOD;
		}
		return;
	}
	if (clock() > 900) return; 
	if (a[dep]=='(') dfs(dep+1, br+1, 0);
	else if (a[dep]==')') dfs(dep+1, br-1, 0);
	else if (a[dep]=='*') dfs(dep+1, br, cpp+1);
	else {
		a[dep]='('; dfs(dep+1, br+1, 0);
		a[dep]=')'; dfs(dep+1, br-1, 0);
		a[dep]='*'; dfs(dep+1, br, cpp+1);
		a[dep]='?';
	}
}
int main()
{
	freopen("bracket.in", "r", stdin); freopen("bracket.out", "w", stdout);
	read(n); read(k);
	rep (i, 1, n) a[i]=readch();
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
//Fuck you CCF!!!
