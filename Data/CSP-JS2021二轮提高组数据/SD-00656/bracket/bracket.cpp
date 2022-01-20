#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef long long ll;
const int maxn = 500 + 9, inf = 2e9;
const ll INF = 1e18, mod = 1e9 + 7;

int read() {
	int x = 0, f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	return f ? -x : x; 
}

void read(ll &x) {
	int f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	x = f ? -x : x;
}

int n, m;
ll f[maxn][maxn][2][2], g[maxn][maxn]; 

inline void add(ll &x, ll y) {
	((x += y) >= mod) ? (x -= mod) : 0;
}

char s[maxn];

int sum[maxn][3];

inline bool chk(int x, char a) {
	return (s[x] == a) || (s[x] == '?');
}

inline bool chk(int l, int r, int x) {
	if (l > r) return 1;
	return sum[r][x] - sum[l - 1][x] == r - l + 1;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", s + 1);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		sum[i][0] = sum[i - 1][0] + chk(i, '(');
		sum[i][1] = sum[i - 1][1] + chk(i, '*');
		sum[i][2] = sum[i - 1][2] + chk(i, ')'); 
	}
	for (int len = 1; len <= n; ++len) {
		for (int i = 1, j = i + len - 1; j <= n; ++j, ++i) {
			if (len >= 2 && len <= m + 2 && chk(i, '(') && chk(j, ')') && chk(i + 1, j - 1, 1))
				add(f[i][j][0][0], 1), add(g[i][j], 1);
			if (len <= m && chk(i, j, 1))
				add(f[i][j][1][1], 1);
			if (chk(i, '(') && chk(j, ')') && len >= 2) {
				add(f[i][j][0][0], f[i + 1][j - 1][0][1]);
				add(f[i][j][0][0], f[i + 1][j - 1][1][0]);
				add(f[i][j][0][0], f[i + 1][j - 1][0][0]);
				add(g[i][j], f[i + 1][j - 1][0][1]);
				add(g[i][j], f[i + 1][j - 1][1][0]);
				add(g[i][j], f[i + 1][j - 1][0][0]);	
			}
			for (int k = i; k < j; ++k) {
				for (int p2 = 0; p2 <= 1; ++p2)
				for (int p3 = 0; p3 <= 1; ++p3)
					add(f[i][j][0][p3], g[i][k] * f[k + 1][j][p2][p3] % mod);
				if (k - i + 1 <= m && chk(i, k, 1))
					for (int p3 = 0; p3 <= 1; ++p3)
						add(f[i][j][1][p3], f[k + 1][j][0][p3]);
			}
		}
	}
//	for (int i = 1; i <= n; ++i)
//		for (int j = i + 1; j <= n; ++j)
//			printf("%d %d %d %d %d %d\n", i, j, f[i][j][0][0], f[i][j][0][1], f[i][j][1][0], f[i][j][1][1]);
	printf("%lld\n", f[1][n][0][0]);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
10 2
???(*??(?)

*/
