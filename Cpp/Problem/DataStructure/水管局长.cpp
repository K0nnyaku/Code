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

const int N_ = 5e5 + 7;
const int M_ = 5e5 + 7;

template<typename T, int N>
struct LCT {
	struct Node { 
		int sm, tg, fa, Ch[2]; 
		T vl;
	};
	Node Tr[N];

#define S(x) Tr[(x)].sm
#define V(x) Tr[(x)].vl
#define F(x) Tr[(x)].fa
#define T(x) Tr[(x)].tg
#define C(x,y) Tr[(x)].Ch[(y)]

#define W(x)  (x == C(F(x),1))
#define Is(x) (C(F(x),0) != x && C(F(x), 1) != x)

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }

	void UpS(int x) {
		if(T(x)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x) = 0;
		}
	}
	void UpV(int x) { 
		S(x) = x;
		if(V(S(C(x,0))) > V(S(x))) S(x) = S(C(x,0)); 
		if(V(S(C(x,1))) > V(S(x))) S(x) = S(C(x,1));
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); UpS(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
		Cn(C(x,p^1), u, p); Cn(u, x, p^1);
		UpV(x);				 UpV(u);
	}
	void Sy(int x) {
		Sp(x);
		for(int y; y = F(x), !Is(x); Rot(x)) 
			if(!Is(y)) Rot(W(x) == W(y) ? y : x); 
		UpV(x);
	}
	
	void Acc(int x) {
		for(int y = 0; x; x = F(y=x)) 
			Sy(x), C(x, 1) = y, UpV(x);
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F(x)==y && !C(x,1)) F(x) = C(y,0) = 0, UpV(y);
		else                   cout << "Fuck\n";
	}
	void Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
	}
	bool Chk(int x, int y) {
		Split(x, y);
		while(C(y,0)) y = C(y, 0);
		return x == y;
	}

	Node* operator[](const int &x) { return &Tr[x]; }
#undef V
#undef S
#undef T
#undef F
#undef C

#undef W
#undef Is
};

struct Qs { 
	int u, v, w; 
	friend bool operator<(const Qs &x, const Qs &y) { return x.w < y.w; }
	Qs(int u_ =0, int v_ = 0, int w_ =0) { u = u_; v = v_; w = w_; }
};

#define F first
#define S second
#define MP(x,y) make_pair(x,y)

LCT<int, N_> Tr;
Qs Q[M_+N_], E[M_+N_];

map<pair<int,int>, int> Ps;

int W[M_+N_], Ans[M_+N_];
bool Ve[M_+N_];

int n, m, q, ect, act;

void Link(int u, int v) {
	int w = Ps[MP(u,v)];
	Tr.Lk(u, w); Tr.Lk(w, v);
	Tr.Sy(w);	 Tr[w]->vl = W[w-n]; Tr[w]->sm = w;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/P4172_2.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> q;
	IR(i, 1, m) {
		int u, v, w; IN >> u >> v >> w;
		if(u > v) swap(u, v);
		Ps[MP(u,v)] = ++ect + n; W[ect] = w;
		E[ect] = Qs(u, v, w);
	}

	IR(i, 1, q) {
		IN >> Q[i].u >> Q[i].v >> Q[i].w;
		if(Q[i].v > Q[i].w) swap(Q[i].v, Q[i].w);
		if(Q[i].u == 2)     Ve[Ps[MP(Q[i].v, Q[i].w)]] = 1;
	}

	sort(E+1, E+ect);
	IR(i, 1, m) {
		int u = E[i].u, v = E[i].v;
		if(Ve[Ps[MP(u, v)]]) continue;
		if(!Tr.Chk(u, v)) Link(u, v);
	}

#define MX Tr[v]->sm
	SR(i, q, 1) {
		int op = Q[i].u, u = Q[i].v, v = Q[i].w;

		if(op == 1) 
			Tr.Split(u, v), Ans[++act] = Tr[MX]->vl;
		else {
			int tps = Ps[MP(u,v)], w = W[tps-n];

			Tr.Split(u, v); 
			int mx = MX;

			if(Tr[mx]->vl > w) {
				Tr.Sy(mx);

				Tr[Tr[mx]->Ch[0]]->fa = Tr[Tr[mx]->Ch[1]]->fa = 0;

				Tr.Lk(u, tps); Tr.Lk(tps, v);

				Tr.Sy(tps);
				Tr[tps]->vl = w;  Tr[tps]->sm = tps;

				Tr.Split(1, 4);
			}
		}
	}

	SR(i, act, 1) cout << Ans[i] << "\n";

	return 0;
} /**/













