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


const int N = 5e5 + 50;

struct event_t {
	int l, r;
	event_t(int l = 0, int r = 0) : l(l), r(r) {}
	inline bool operator<(const event_t &rhs) const {
		return l < rhs.l;	
	};
} e1[N], e2[N];

int n, m1, m2, c[N], ctot, f1[N], f2[N];
int airport_events[N];

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();	
	for (int i = 1; i <= m1; ++i) {
		c[++ctot] = e1[i].l = read();
		c[++ctot] = e1[i].r = read();
	}
	for (int i = 1; i <= m2; ++i) {
		c[++ctot] = e2[i].l = read();
		c[++ctot] = e2[i].r = read();
	}
	std::sort(c + 1, c + ctot + 1);
	ctot = std::unique(c + 1, c + ctot + 1) - (c + 1);
	auto find = [&](int x) {
		return std::lower_bound(c + 1, c + ctot + 1, x) - c;	
	};
	for (int i = 1; i <= m1; ++i) {
		e1[i].l = find(e1[i].l);
		e1[i].r = find(e1[i].r);
	}
	for (int i = 1; i <= m2; ++i) {
		e2[i].l = find(e2[i].l);
		e2[i].r = find(e2[i].r);	
	}
	auto solve = [&](int *f, event_t *b, int m) {
		std::set<event_t> active;
		for (int i = 1; i <= m; ++i) 
			active.emplace(b[i]);
		int distributed = 0;
		for (int k = 1; k <= n; ++k) {
			int available = -1;
			while (distributed < m) {
				auto p = active.lower_bound(event_t(available, -1));
				if (p == active.end()) break;
				++distributed;
				available = p->r;
				active.erase(p);
			}
			f[k] = distributed;
		}
	};
	solve(f1, e1, m1);
	solve(f2, e2, m2);
	int ans = -1;
	for (int i = 0; i <= n; ++i)
		ans = std::max(ans, f1[i] + f2[n - i]);
	printf("%d\n", ans);
	return 0;
}

