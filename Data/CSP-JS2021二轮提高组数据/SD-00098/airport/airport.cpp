#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define fi first
#define se second
#define mp std::make_pair
#define pb emplace_back
typedef long long ll;
typedef double ld;
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
const int N = 100010;
int n, m1, m2, ct1, ct2, c1[N], c2[N], pos[N], s1[N], s2[N];
pii a[N<<1], b[N<<1];
#define ls tree[x].lson
#define rs tree[x].rson
#define tl tree[x].l
#define tr tree[x].r
struct SGT {
	int trnt;  
	struct Node {
		int l, r, lson, rson, sum, tag;
	}tree[N<<1];
	inline void pushup(int x) { tree[x].sum = tree[ls].sum + tree[rs].sum; }
	inline void pushdown(int x) {
		if(tree[x].tag) {
			int p = tree[x].tag; tree[x].tag = 0;
			if(ls) tree[ls].sum += (tree[ls].r - tree[ls].l + 1) * p;
			if(rs) tree[rs].sum += (tree[rs].r - tree[rs].l + 1) * p;
			if(ls) tree[ls].tag += p; if(rs) tree[rs].tag += p;
		}
	}
	int build(int l, int r) {
		int x = ++trnt; tl = l; tr = r; tree[x].sum = tree[x].tag = 0;
		int mid = (tl + tr) >> 1; if(l == r) { tree[x].sum = l; return x; }
		ls = build(l, mid); rs = build(mid+1, r);
		pushup(x);
		return x;
	}
	void modify(int x, int l, int r, int v) {
		if(tl >= l && tr <= r) {
			tree[x].sum += (tr - tl + 1) * v;
			tree[x].tag += v;
			return ;
		}
		int mid = (tl + tr) >> 1;
		pushdown(x);
		if(mid >= l) modify(ls, l, r, v);
		if(mid < r) modify(rs, l, r, v);
		pushup(x); return ;
	}
	int query(int x) {
		if(!tree[x].sum) return -1;
		if(tl == tr) return tl;
		pushdown(x); int s = 0;
		if(tree[ls].sum) s = query(ls);
		else s = query(rs); pushup(x); return s;
	}
}tr1;
#undef ls
#undef rs
#undef tl
#undef tr
signed main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	for(int i = 1; i <= m1; ++i) {
		int x, y; read(x); read(y);
		a[++ct1] = mp(x, i);
		a[++ct1] = mp(y, -i);
	}
	std::sort(a + 1, a + ct1 + 1);
	for(int i = 1; i <= m2; ++i) {
		int x, y; read(x); read(y);
		b[++ct2] = mp(x, i);
		b[++ct2] = mp(y, -i);
	}
	std::sort(b + 1, b + ct2 + 1);
	tr1.trnt = 0; tr1.build(1, n);
	for(int i = 1; i <= ct1; ++i) {
		if(a[i].se > 0) {
			int p = tr1.query(1);
			pos[a[i].se] = p;
			if(p >= 0) {
				++s1[p]; tr1.modify(1, p, n, -1);
			}
		}
		else {
			if(pos[-a[i].se] >= 0) {
				tr1.modify(1, pos[-a[i].se], n, 1);
			}
		}
	}
	tr1.trnt = 0; tr1.build(1, n);
	for(int i = 1; i <= ct2; ++i) {
		if(b[i].se > 0) {
			int p = tr1.query(1); pos[b[i].se] = p;
			if(p >= 0) {
				++s2[p]; tr1.modify(1, p, n, -1);
			}
		}
		else {
			if(pos[-b[i].se] >= 0) {
				tr1.modify(1, pos[-b[i].se], n, 1);
			}
		}
	}
	for(int i = 1; i <= n; ++i) s1[i] += s1[i-1];
	for(int i = 1; i <= n; ++i) s2[i] += s2[i-1];
	int ans = 0;
	for(int i = 0; i <= n; ++i) ans = Max(ans, s1[i] + s2[n-i]);
	printf("%d\n", ans);
	return 0;
}
