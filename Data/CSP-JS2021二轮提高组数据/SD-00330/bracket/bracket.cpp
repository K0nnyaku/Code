#include <bits/stdc++.h>
typedef long long ll;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar('0' ^ (x % 10));
}
const int N = 505;
const int mod = 1e9 + 7;
void Add(ll &x, const ll &y) { x += y; x = x >= mod ? x - mod : x; }
int n, K;
char ch[N];
ll f[N][N], pre[N][N], suf[N][N];
bool qwq[N][N];
bool check(int x) { return ch[x] == '*' || ch[x] == '?'; }
bool chk(int l, int r) { return (ch[l] == '(' || ch[l] == '?') && (ch[r] == ')' || ch[r] == '?'); }
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), K = read();
	scanf("%s", ch + 1);
	for (int i = 1; i < n; ++i) {
		if (chk(i, i + 1)) {
			f[i][i + 1] = 1;
		}
	}
	for (int l = 1; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			if (r - l + 1 > K || !check(r)) break;
			qwq[l][r] = 1;
		}
	}
	for (int len = 3; len <= n; ++len) {
		for (int l = 1; l <= n; ++l) {
			ll tmp = 0;
			int r = l + len - 1;
			for (int k = l; k <= r; ++k) {
				if (!qwq[l][k]) break;
				tmp = (tmp + f[k + 1][r]) % mod;
			}
			pre[l][r] = tmp;
			tmp = 0;
			for (int k = r; k >= l; --k) {
				if (!qwq[k][r]) break;
				tmp = (tmp + f[l][k - 1]) % mod;
			}
			suf[l][r] = tmp;
			tmp = 0;
			for (int k = l + 1; k <= r - 2; ++k) { // AB
				tmp = (tmp + f[l][k] * f[k + 1][r]) % mod;
			}
			for (int k = l + 2; k <= r - 2; ++k) { // ASB
				tmp = (tmp + f[l][k - 1] * pre[k][r]) % mod;
			}
			if (chk(l, r)) {
				tmp = (tmp + f[l + 1][r - 1]) % mod; // (A)
				tmp = (tmp + qwq[l + 1][r - 1]) % mod; // (S)
				tmp = (tmp + pre[l + 1][r - 1]) % mod; // (SA)
				tmp = (tmp + suf[l + 1][r - 1]) % mod; // (AS)
			}
			f[l][r] = tmp;
		}
	}
	printf("%lld\n", f[1][n]);
	return 0;
}
