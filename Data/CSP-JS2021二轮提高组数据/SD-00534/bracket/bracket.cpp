#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

template <int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch) {
		if (q1 == q2) {
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<1024768> io;

inline int read() {
	int r = 0, neg = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

void write(int x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ') {
	write(x);
	io.pc(ch);
}

const int N = 505;
int n, k, f[N][N], g[N][N], h[N][N], F[N][N], sum[N];
char s[N];


struct Qingyu_Timer
{
	int _;
	Qingyu_Timer() { _ = clock(); }
	~Qingyu_Timer() {
		fprintf(stderr, "Time used = %.6f seconds", (clock() - _) * 1.0 / CLOCKS_PER_SEC);	
	}
} qwqwqwq;

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == '(' || s[i] == ')')
			sum[i] = 1;
	for (int i = 1; i <= n; ++i)
		sum[i] += sum[i - 1];
	auto canbe = [&](char x, char y) {
		return x == '?' || x == y;
	};
	auto is_pairable = [&](char l, char r) {
		return canbe(l, '(') && canbe(r, ')');
	};
	auto all_star = [&](int l, int r) {
		if (r - l + 1 > k) return false;
		return sum[r] - sum[l - 1] == 0;	
	};
	auto solve = [&](int l, int r) {
		// Case 1
		if (l != r && is_pairable(s[l], s[r])) {
			if (l + 1 <= r - 1) {
				f[l][r] = F[l][r] = 
				inc(inc(f[l + 1][r - 1], g[l + 1][r - 1]), inc(all_star(l + 1, r - 1), h[l + 1][r - 1]));
			}
			else f[l][r] = F[l][r] = 1;
		}
		// Case 2
		for (int i = 0; i < k && l + i <= r; ++i) {
			if (!canbe(s[l + i], '*')) {
				break;
			}
			if (l + i < r) {
				upd(g[l][r], f[l + i + 1][r]);
			}
		}
		for (int i = 0; i < k && r - i >= l; ++i) {
			if (!canbe(s[r - i], '*')) {
				break;
			}
			if (l < r - i) {
				upd(h[l][r], f[l][r - i - 1]);
			}
		}
		// Case 3
		for (int i = l; i <= r; ++i) {
			upd(f[l][r], mul(F[l][i], inc(f[i + 1][r], g[i + 1][r])));
		}
	};
	for (int _ = 0; _ <= n; ++_) 
		for (int l = 1; l + _ <= n; ++l){
			int r = l + _;
			solve(l, r);
		}
	printf("%d\n", f[1][n]);
	return 0;
}

