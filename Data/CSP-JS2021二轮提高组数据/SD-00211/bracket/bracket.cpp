#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>

inline void read(int &x) {
	register char ch = 0; register bool w = 0;
	for(; !std::isdigit(ch); w |= ch == '-', ch = getchar());
	for(x = 0; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
}
typedef long long ll;

const int N = 105;
const ll mod = 1e9 + 7;

int n, lim, dp[N][N], pre[N], farx[N];
char ch[N];

inline void add(int &x, int y) {
	x += y; if(x >= mod) x -= mod;
}
inline bool lb(int loc) {
	return (ch[loc] == '(') || (ch[loc] == '?');
}
inline bool rb(int loc) {
	return (ch[loc] == ')') || (ch[loc] == '?');
}
inline bool canx(int l, int r) {
//	printf("canx %d %d\n", l, r);
	if(r - l + 1 > lim) return 0;
	if(l > r) return 1;
	return ((pre[r] - pre[l - 1]) == (r - l + 1));
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n), read(lim);
	scanf("%s", ch + 1);
	for(int i = 1; i <= n; ++i) {
		if(ch[i] == '*' || ch[i] == '?') pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	for(int i = 1; i <= n; ++i) {
		farx[i] = i - 1;
		for(int j = i; j <= n; ++j) {
			if(ch[i] == '(' || ch[i] == ')') break;
			farx[i] = j;
		}
	}
	static int tmp[N];
	for(int len = 2; len <= n; ++len) {
		for(int l = 1; l <= n; ++l) {
			int r = len + l - 1;
			if(r > n) break;
//			printf("st %d %d\n", l, r);
			if(lb(l) && rb(r)) {
				if(canx(l + 1, r - 1)) dp[l][r] = 1;
				add(dp[l][r], dp[l + 1][r - 1]);
				for(int k = 1; k <= std::min(lim, r - l - 1); ++k) {
					int nl = l + 1, nr = l + k;
					if(canx(nl, nr)) add(dp[l][r], dp[nr + 1][r - 1]);
					nl = r - 1, nr = r - k;
					if(canx(nr, nl)) add(dp[l][r], dp[l + 1][nr - 1]);
				}
//				printf("can ! %d\n", dp[l][r]);
			}
			for(int k = l + 1; k < r - 1; ++k) {
				int tmp = 1ll * dp[l][k] * dp[k + 1][r] % mod;
				if(tmp) {
					add(dp[l][r], tmp); break;
				}
			}
//			int cnt = 0;
//			printf("o %d\n", dp[l][r]);
			for(int k = 1; k <= r; ++k) tmp[k] = dp[k][r];
			for(int i = 1; i <= r; ++i) add(tmp[i], tmp[i - 1]);
			for(int i = l + 1; i < r; ++i) {
				// A : [l, i] ;
				int fr = std::min(r - 1, farx[i + 1]);
				fr = std::min(fr, i + lim);
				if(fr > i) {
					int num = tmp[fr + 1] - tmp[i + 1];
//					printf("oh %d %d %d\n", i, fr, num);
					add(num, mod);
					add(dp[l][r], 1ll * num * dp[l][i] % mod);
				}
			}
//			printf("db %d %d %d\n", l, r, dp[l][r]);
		}
	}
	printf("%d\n", dp[1][n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
