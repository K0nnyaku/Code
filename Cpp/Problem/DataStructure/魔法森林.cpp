#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR cout << "Fuck\n"

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

template<typename T, int N>
struct LCT {
	struct Node { T vl; int sm, fa, tg, Ch[2]; };
	Node Tr[N];

#define S(x) Tr[x].sm
#define V(x) Tr[x].vl
#define F(x) Tr[x].fa
#define T(x) Tr[x].tg
#define C(x,y) Tr[x].Ch[y]

#define W(x) (x == C(F(x),1))
#define Is(x) (C(F(x), 0) != x && C(F(x),1) != x)
	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }

	void UpS(int x) {
		S(x) = x;
		if(V(S(C(x,0))) > V(S(x))) S(x) = S(C(x,0));
		if(V(S(C(x,1))) > V(S(x))) S(x) = S(C(x,1));
	}

	void SpS(int x) {
		if(T(x)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x) = 0;
		}
	}
	void SpT(int x) { if(!Is(x)) SpT(F(x)); SpS(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v; 
		Cn(C(x,p^1), u, p);     Cn(u, x, p^1);
		UpS(u);
	}

	void Sy(int x) {
		SpT(x);
		for(int y; y=F(x), !Is(x); Rot(x))
			if(!Is(y)) Rot(W(x)==W(y) ? y : x);
	}

	void Acc(int x) {
		for(int y = 0; x; x = F(y=x))
			Sy(x), C(x,1) = y, UpS(x);
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F(x)==y && !C(x,1)) F(x) = C(y,0) = 0;
		else                   ERR;
	}
	void Link(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
		else      ERR;
	}

	bool Chk(int x, int y) {
		Split(x, y);
		while(C(y,0)) y = C(y, 0);
		Sy(y);
		return x == y;
	}
	
	Node* operator[](const int &x) { return &Tr[x]; }
};

struct Edge {
	int u, v, p, q, pos;
	Edge(int u_ = 0, int v_ = 0, int p_ = 0, int q_ =0, int pos_ = 0) {
		u = u_; v = v_; p = p_; q = q_; pos = pos_;
	}
	friend bool operator<(const Edge &x, const Edge &y) { return x.p < y.p; }
};

const int N_ = 5e4 + 7;
const int M_ = 1e5 + 7;
const int INF = 0x3f3f3f3f;

LCT<int, N_+M_> Tr;
Edge E[M_];
int n, m, ans;

void Link(int u, int v, int w, int p) {
	Tr.Link(u, w); Tr.Link(w, v);
	Tr.Sy(w);      Tr[w]->vl = p; 
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) {
		int u, v, p, q;
		IN >> u >> v >> p >> q; 
		E[i] = Edge(u, v, p, q, i+n);	
	}

	sort(E+1, E+m+1);

	ans = INF;
	IR(i, 1, m) {
		int u = E[i].u, v = E[i].v, p = E[i].p, q = E[i].q, pos = E[i].pos;
		if(!Tr.Chk(u, v)) Link(u, v, pos, q); 
		else {
			Tr.Split(u, v);
			int mx = Tr[v]->sm;
			if(Tr[mx]->vl > q) {
				Tr.Sy(mx);
				Tr[Tr[mx]->Ch[0]]->fa = Tr[Tr[mx]->Ch[1]]->fa = 0;
				Link(u, v, pos, q);
			}
		}
		if(Tr.Chk(1,n)) 
			Tr.Split(1,n), ans = min(p + Tr[Tr[n]->sm]->vl, ans);
	}

	if(Tr.Chk(1,n))
		cout << ans << "\n";
	else 
		cout << "-1\n";

	return 0;
} /**/













