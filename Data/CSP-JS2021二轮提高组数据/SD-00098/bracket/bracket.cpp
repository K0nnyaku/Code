#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#define fi first
#define se second
#define mp std::make_pair
#define pb emplace_back
typedef long long ll;
typedef double ld;
const ll mod = 1000000007;
ll Add(ll x, ll y) { return (x + y >= mod) ? (x + y - mod) : (x + y); }
ll cadd(ll &x, ll y) { return x = (x + y >= mod) ? (x + y - mod) : (x + y); }
ll Mul(ll x, ll y) { return x * y % mod; }
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vpii;
template<typename T> T Max(T x, T y) { return x > y ? x : y; }
template<typename T> T Min(T x, T y) { return x < y ? x : y; }
template<typename T>
T &read(T &r) {
	r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') w = ch == '-' ? 1 : w, ch = getchar();
	while(ch >= '0' && ch <= '9') r = r * 10 + ch - '0', ch = getchar();
	return r = w ? -r : r;
}
const int N = 510;
int n, K, xing[N];
ll f[N][N][4], g[N][N], h[N][N];
char ch[N];
bool check(int l, int r) {
	if(r-l+1<=0) return 0;
	return xing[r] - xing[l-1] == r-l+1 && r-l+1 <= K;
}
signed main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n); read(K);
	scanf("%s", ch+1);
	for(int i = 1; i <= n; ++i) xing[i] = xing[i-1] + (ch[i] == '*' || ch[i] == '?');
	for(int i = 1; i < n; ++i) {
		if(ch[i] == '(' || ch[i] == '?')
			if(ch[i+1] == ')' || ch[i+1] == '?')
				g[i][i+1] = h[i][i+1] = 1;
	}
	for(int len = 3; len <= n; ++len)
		for(int i = 1; i <= n; ++i) {
			int j = i + len - 1;
			if(j > n) break ;
			if(ch[i] == '(' || ch[i] == '?')
				if(ch[j] == ')' || ch[j] == '?') {
					if(check(i+1, j-1)) cadd(g[i][j], 1), cadd(h[i][j], 1);
					cadd(g[i][j], f[i+1][j-1][0]);
					cadd(g[i][j], f[i+1][j-1][1]);
					cadd(g[i][j], f[i+1][j-1][2]);
					cadd(g[i][j], g[i+1][j-1]);
					cadd(h[i][j], f[i+1][j-1][0]);
					cadd(h[i][j], f[i+1][j-1][1]);
					cadd(h[i][j], f[i+1][j-1][2]);
					cadd(h[i][j], g[i+1][j-1]);
				}
			for(int k = i; k <= j; ++k) {
				cadd(g[i][j], h[i][k] * g[k+1][j] % mod);
				cadd(f[i][j][0], g[i][k] * f[k+1][j][1] % mod);
				cadd(f[i][j][1], check(i, k) * f[k+1][j][0]);
				cadd(f[i][j][1], check(i, k) * g[k+1][j]);
				cadd(f[i][j][2], g[i][k] * f[k+1][j][3] % mod);
				cadd(f[i][j][2], g[i][k] * check(k+1, j));
				cadd(f[i][j][3], check(i, k) * f[k+1][j][2]);
			}
		}
	ll ans = 0;
	cadd(ans, f[1][n][0]);
	cadd(ans, g[1][n]);
	printf("%lld\n", ans);
	return 0;
}
