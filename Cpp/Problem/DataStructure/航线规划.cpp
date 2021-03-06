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

const int N_ = 3e5 + 7;
const int M_ = 3e5 + 7;
const int INF = 0x3f3f3f3f;

template<int N>
struct LCT {
	struct Node { 
		int vl, sm, fa, Tg[2], Ch[2]; 
		Node() { vl = sm = fa = Tg[0] = Ch[0] = Tg[1] = Ch[1] = 0; }
	};
	Node Tr[N];

#define Q(x) Tr[x].qt
#define S(x) Tr[x].sm
#define V(x) Tr[x].vl
#define F(x) Tr[x].fa
#define T(x,y) Tr[x].Tg[y]
#define C(x,y) Tr[x].Ch[y]

#define W(x)   (x == C(F(x),1))
#define Is(x)  (C(F(x),0) != x && C(F(x),1) != x)

	void Rv(int x)  { swap(C(x,0), C(x,1)); T(x,1) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }
	void UpV(int x) { 
		S(x) = S(C(x,0)) + S(C(x,1)) + V(x); 
	}
	void SpA(int x) { V(x) = 0; S(x) = 0; T(x,0) = 1; }
	void SpT(int x) {
		if(C(x,0) && T(x,0)) SpA(C(x,0));  
		if(C(x,1) && T(x,0)) SpA(C(x,1));
		if(T(x,1)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x,1) = 0;
		}
		T(x,0) = 0;
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); SpT(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
		Cn(C(x,p^1), u, p); Cn(u, x, p^1);
		UpV(x);             UpV(u);
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

	void CgRt(int x) {	Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
	}

	bool Chk(int x, int y) {
		CgRt(x); Acc(y); Sy(y);
		while(C(y,0)) y = C(y,0);
		return y == x;
	}
	Node* operator[](const int &x) { return &Tr[x]; }
};

struct Qs {
	int opt, u, v;
	Qs(int opt_ = 0, int u_ = 0, int v_ = 0) {
		opt = opt_; u = u_; v = v_;
	}
};

LCT<M_+N_> Tr;
Qs Q[M_];
map<pair<int,int>, int> Mp;
map<pair<int,int>, bool> Vs;
pair<int, int> E[M_];
int Ans[N_+M_];
int n, m, ect, qct, act;
//#define Debug

void Link(int u, int v) {
	int w = Mp[make_pair(u,v)];
#ifdef Debug
	printf("Link %d %d %d\n", u, v, w);
#endif
	Tr.Lk(u, w);   Tr.Lk(w, v);
	Tr.Sy(w); Tr[w]->vl = Tr[w]->sm = 1;
}

void Add(int u, int v) { 
#ifdef Debug
	printf("Add %d %d\n", u, v);
#endif
	Tr.Split(u, v); Tr.SpA(v);
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		if(u > v) swap(u, v);
		
		if(!Mp[make_pair(u,v)]) Mp[make_pair(u,v)] = ++ect + n;
		E[ect] = make_pair(u, v);
	}

	while(1) {
		int opt, u, v; IN >> opt;
		if(opt == -1) break;
		IN >> u >> v;

		if(u > v) swap(u, v);
		Q[++qct] = Qs(opt, u, v);
		if(opt == 0) Vs[make_pair(u,v)] = 1;
	}

	IR(i, 1, ect) 
		if(!Vs[E[i]]) 
			if(Tr.Chk(E[i].first, E[i].second)) Add (E[i].first, E[i].second);
			else								Link(E[i].first, E[i].second); 

	SR(i, qct, 1) {
		int x = Q[i].opt, y = Q[i].u, z = Q[i].v;
		if(x == 0) 
			if(Tr.Chk(y, z)) Add (y, z);
			else			 Link(y, z); 
		else Tr.Split(y, z), Ans[++act] = Tr[z]->sm;
	}

	SR(i, act, 1) cout << Ans[i] << "\n";

	return 0;
} /**/










