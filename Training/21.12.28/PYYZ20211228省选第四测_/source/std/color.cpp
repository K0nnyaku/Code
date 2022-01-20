#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define PER(i, a, b) for (int i = (a); i > (b); --i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 150010;
int n, m, L[N], R[N], fa[N], dep[N], sze[N];
int info[N], nxt[N * 2], go[N * 2];
ll d[N], ds[N];
struct node {
	node *fa, *lc, *rc;
	int sal;
	inline bool isRoot() const {
		if (!fa) return true;
		return fa->lc != this && fa->rc != this;
	}
	inline bool which() const {
		return fa->rc == this;
	}
} used[N], *pool = used, *t[N];

inline void SetE(const int &x, const int &y) {
	static int amo = 0;
	nxt[++amo] = info[x]; go[info[x] = amo] = y;
	nxt[++amo] = info[y]; go[info[y] = amo] = x;
}

inline void Rotate(node *x) {
	node *y = x->fa, *z = y->fa, *b = y->lc == x ? x->rc : x->lc;
	if (!y->isRoot()) (z->lc == y ? z->lc : z->rc) = x;
	x->fa = z; y->fa = x; b ? b->fa = y : 0;
	if (y->lc == x) x->rc = y, y->lc = b;
	else x->lc = y, y->rc = b;
}

inline void Splay(node *x) {
	while (!x->isRoot()) {
		if (!x->fa->isRoot()) {
			if (x->which() == x->fa->which()) Rotate(x->fa);
			else Rotate(x);
		}
		Rotate(x);
	}
}

inline void insert(ll *f, int x, const ll &delta) {
	for (; x <= n; x += x & -x) f[x] += delta;
}

inline ll query(ll *f, int x) {
	ll res = 0;
	for (; x > 0; x -= x & -x) res += f[x];
	return res;
}

inline void modify(const int &l, const int &r, const int &delta) {
	insert(d, l, delta);
	insert(d, r + 1, -delta);
	insert(ds, l, (ll)delta * l);
	insert(ds, r + 1, (ll)(r + 1) * -delta);
}

inline ll calc_sum(const int &l, const int &r) {
	ll res = 0;
	res += query(d, r) * (r + 1);
	res -= query(d, l - 1) * l;
	res -= query(ds, r);
	res += query(ds, l - 1);
	return res;
}

inline void Access(node *x) {
	node *z;
	for (node *y = NULL; x; y = x, x = x->fa) {
		Splay(x);
		if (x->rc) {
			for (z = x->rc; z->lc; z = z->lc);
			modify(L[z->sal], R[z->sal], 1);
		}
		if (y) {
			for (z = y; z->lc; z = z->lc);
			modify(L[z->sal], R[z->sal], -1);
		}
		x->rc = y;
	}
}

inline void lct_init() {
	REP(i, 0, n) {
		t[i] = pool++;
		t[i]->sal = i;
	}
}

inline void tree_init() {
	static int ql, que[N];
	que[ql = 1] = 0;
	memset(fa, -1, sizeof(fa));
	FOR(i, 1, ql) {
		int x = que[i]; sze[x] = 1;
		for (int k = info[x], y; y = go[k], k; k = nxt[k])
			if (!sze[y]) que[++ql] = y, fa[y] = x, dep[y] = dep[x] + 1, t[y]->fa = t[x];
	}
	ROF(i, ql, 2) {
		int x = que[i], y = fa[x];
		sze[y] += sze[x];
	}
	L[0] = 1;
	FOR(i, 1, ql) {
		int x = que[i], s = L[x];
		R[x] = L[x] + sze[x] - 1;
		for (int k = info[x], y; y = go[k], k; k = nxt[k])
			if (fa[x] != y) L[y] = s + 1, s += sze[y];
	}
	REP(i, 0, n) modify(L[i], L[i], dep[i]);
}

char ch;
inline int read() {
	while (ch = getchar(), ch < '0' || ch > '9');
	int res = ch - 48;
	while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
	return res;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
  
	n = read();
	lct_init();
	REP(i, 1, n) SetE(read(), read());
	tree_init();
	m = read();
	while (m--) {
		char type;
		while (type = getchar(), type != 'q' && type != 'O');
		int u = read();
		if (type == 'q') printf("%.9lf\n", (double)calc_sum(L[u], R[u]) / sze[u]);
		else Access(t[u]);
	}
	return 0;
}
