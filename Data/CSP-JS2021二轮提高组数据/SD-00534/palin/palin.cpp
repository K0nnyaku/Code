#include <bits/stdc++.h>

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


struct Qingyu_Timer
{
	int _;
	Qingyu_Timer() { _ = clock(); }
	~Qingyu_Timer() {
		fprintf(stderr, "Time used = %.6f seconds", (clock() - _) * 1.0 / CLOCKS_PER_SEC);	
	}
} qwqwqwq;

const int N = 2e6 + 50;

int n, a[N], b[N], c[N][2], nosame[N];
int f[N], left[N], right[N], total_cost;
bool vis[N];

inline int is_prime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;	
}

const int mod = 1e7 + 19;

struct Qhash_table {
	int head[mod], nxt[N], id[N], cnt, tot;
	long long ver[N];
	Qhash_table() {
		memset(head, 0, sizeof head);	
		cnt = tot = 0;
	}
	inline void clear() {
		for (int i = 1; i <= cnt; ++i)
			head[ver[i] % mod] = 0;	
		tot = 0;
	}
	void add(long long x) {
		int t = x % mod;
		nxt[++cnt] = head[t];	
		ver[cnt] = x;
		id[cnt] = ++tot;
		head[t] = cnt;
	}
	int access(long long x) {
		int t = x % mod;
		for (int i = head[t]; i; i = nxt[i])
			if (ver[i] == x)
				return id[i];
		add(x);
		return id[cnt];
	}
	int access(int l, int r) {
		long long O = 10000000ll * l + r;
		int result = access(O);
		return result;
	}
} HT;

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	auto get_alt = [&](int p) { 
		return c[a[p]][p == c[a[p]][0]];
	};
	auto attached = [&](int l, int r, int p) {
		return ((l - 1 == p) || (r + 1 == p));
	};
	std::function<bool(int, int)> dp = [&](int l, int r) {
		if (r - l + 1 == n) return r < nosame[l];
		if (r - l + 1 < n) throw;
		int lr = HT.access(l, r);
		if (f[lr] != -1) return f[lr] == 1;
		f[lr] = 0;
		if (l == 1 && r == 2 * n) {
			int l1r = HT.access(l + 1, r);
			int lr1 = HT.access(l, r - 1);
			left[l1r] = right[l1r] = get_alt(l);
			left[lr1] = right[lr1] = get_alt(r);
			f[lr] |= dp(l + 1, r);
			f[lr] |= dp(l, r - 1);
		}
		else {
			int L = left[lr], R = right[lr];
			int pl = get_alt(l), pr = get_alt(r);
			if (attached(L, R, pl)) {
				int l1r = HT.access(l + 1, r);
				left[l1r] = std::min(L, pl);
				right[l1r] = std::max(R, pl);
				f[lr] |= dp(l + 1, r);	
			}
			if (attached(L, R, pr)) {
				int lr1 = HT.access(l, r - 1);
				left[lr1] = std::min(L, pr);
				right[lr1] = std::max(R, pr);
				f[lr] |= dp(l, r - 1);	
			}
		}
		++total_cost;
		return f[lr] == 1;
	};
	std::vector<int> elements;
	std::function<void(int, int)> construct = [&](int l, int r) {
		if (r - l + 1 <= n) {
			int L = l, R = r;
			std::reverse(elements.begin(), elements.end());
			for (int i = 0; i < n; ++i) {
				if (a[L] == elements[i]) {
					++L;
					putchar('L');
				}
				else if (a[R] == elements[i]) {
					--R;
					putchar('R');
				}
				else throw;
			}
			putchar('\n');
			return;
		}
		int lr = HT.access(l, r);
		bool ok1 = (l == 1 && r == 2 * n) || attached(left[lr], right[lr], get_alt(l));
		bool ok2 = (l == 1 && r == 2 * n) || attached(left[lr], right[lr], get_alt(r));
		if (ok1 && dp(l + 1, r)) {
			elements.push_back(a[l]);
			putchar('L');
			construct(l + 1, r);
		}
		else if (ok2 && dp(l, r - 1)) {
			elements.push_back(a[r]);
			putchar('R');
			construct(l, r - 1);
		}
		else throw;
	};
	auto solve = [&]() {
		elements.clear();
		construct(1, 2 * n);	
	};
	while (T--) {
		total_cost = 0;
		n = read();
		for (int i = 1; i <= n; ++i)
			c[i][0] = c[i][1] = 0;
		for (int i = 1; i <= 2 * n; ++i) {
			a[i] = read();
			if (c[a[i]][0]) c[a[i]][1] = i;
			else c[a[i]][0] = i;
		}
		for (int i = 1; i <= 2 * n; ++i) {
			if (i < get_alt(i))
				nosame[i] = get_alt(i);
			else
				nosame[i] = 2 * n + 1;
		}
		for (int i = 2 * n - 1; i >= 1; --i) {
			nosame[i] = std::min(nosame[i], nosame[i + 1]);
		}
		if (n == 1) {
			puts("LL");	
		}
		else {
			memset(f, -1, sizeof f);
			memset(left, -1, sizeof left);
			memset(right, -1, sizeof right);
			if (dp(1, 2 * n)) {
				solve();
			}
			else {
				puts("-1");	
			}
		}
	}
}
