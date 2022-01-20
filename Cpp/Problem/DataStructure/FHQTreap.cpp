#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 1e6 + 7;

template<typename T, int N>
struct FHQ {
	struct Node {
		int qt, wg, l, r;
		T vl;
		Node(T vl_ = 0, int qt_ = 0, int wg_ = 0, int l_ = 0, int r_ = 0) { vl = vl_; qt = qt_; wg = wg_; l = l_; r = r_; }
	};
	Node Tr[N];
	int cnt, rt;
	FHQ() { cnt = 0; rt = 0; }

#define L Tr[x].l
#define R Tr[x].r
#define V(x) Tr[x].vl
#define Q(x) Tr[x].qt
#define W(x) Tr[x].wg
	void Up(int x) { Q(x) = Q(L) + Q(R) + 1; }
	int New(T v) { Tr[++cnt] = Node(v, 1, rand()); return cnt; }
	void Cut(int x, T v, int& lr, int& rl) {
		if(!x) { lr = rl = 0; return ; }
		if(V(x) <= v) lr = x, Cut(R, v, R, rl);
		else          rl = x, Cut(L, v, lr, L);
		Up(x);
	}
	void Split(int x, int k, int& lr, int& rl) {
		if(!x) { lr = rl = 0; return ; }
		if(Q(L) >= k) rl = x, Split(L, k, lr, L);
		else          lr = x, Split(R, k-Q(L)-1, R, rl);
		Up(x);
	}
#undef L
#undef R
#define L(x) Tr[x].l
#define R(x) Tr[x].r
	void Merge(int x, int y, int& ch) {
		if(!x || !y) { ch = x + y; return ; }
		if(W(x) <= W(y)) ch = x, Merge(R(x), y, R(x));
		else             ch = y, Merge(x, L(y), L(y));
		Up(ch);
	}

	void Ins(int x) { 
		int p, q;
		Cut(rt, x-1, p, q);
		Merge(p, New(x), rt);
		Merge(rt, q,     rt);
	}
	void Del(int x) {
		int u, v, w;
		Cut(rt, x, u, v);
		Split(u, Q(u)-1, u, w);
		Merge(u, v, rt);
	}

	int Rk(int x) {
		int p, q, res;
		Cut(rt, x-1, p, q); res = Q(p) + 1; Merge(p, q, rt);
		return res;
	}

	void Test(int x) {
		if(!x) return ;
		printf("x = %d, L = %d, R = %d\n", x, V(L(x)), V(R(x)));
		printf("!!x.qt = %d!!\n\n", Q(x));
		Test(L(x)); Test(R(x));
	}

	int Kth(int x) {
		int u, v, w, res;
		Split(rt, x, u, v); Split(u, x-1, u, w);
		res = V(w);
		Merge(u, w, u);     Merge(u, v, rt);
		return res;
	}

	int Pre(int x) {
		int p, q, res, tp;
		Cut(rt, x-1, p, q);
		tp = p; res = V(p);
		while(R(tp)) res = V(R(tp)), tp = R(tp);
		Merge(p, q, rt);
		return res;
	}
	int Nxt(int x) {
		int p, q, res, tq;
		Cut(rt, x, p, q); 
		tq = q; res = V(q);
		while(L(tq)) res = V(L(tq)), tq = L(tq);
		Merge(p, q, rt);
		return res;
	}
#undef L 
#undef R 
#undef V
#undef Q
#undef W
};
FHQ<int, N_<<1> Tr;

int n, m, last, ans;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	srand(19260817);

	IN >> n >> m;
	while(n--) { int x; IN >> x; Tr.Ins(x); }

	while(m--) {
		int opt, x; IN >> opt >> x;
		x ^= last;
		switch(opt) {
			case 1: Tr.Ins(x); break;
			case 2: Tr.Del(x); break;
			case 3: x = Tr.Rk(x); break;
			case 4: x = Tr.Kth(x); break;
			case 5: x = Tr.Pre(x); break;
			case 6: x = Tr.Nxt(x); break;
		}
		if(opt >= 3 && opt <= 6) ans ^= x, last = x;
	}

	cout << ans << "\n";

	return 0;
} /**/
