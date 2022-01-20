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

const int N_ = 1e5 + 7;
const int M_ = 3e5 + 7;

int n, m;

template<typename T, int N>
struct LCT {
	struct Node {
		int fa, tg, ch[2];
		T vl, sm;
		Node(int vl_ = 0, int fa_ = 0, int tg_ = 0) {
			vl = vl_; sm = vl; fa = fa_; tg = tg_; ch[0] = ch[1] = 0; } 
	};
	Node Tr[N];

#define S(x)   Tr[x].sm
#define V(x)   Tr[x].vl
#define F(x)   Tr[x].fa
#define T(x)   Tr[x].tg
#define C(x,y) Tr[x].ch[y]

#define W(x)   (x == C(F(x),1))
#define Is(x)  (C(F(x),0) != x && C(F(x), 1) != x)

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }

	void UpV(int x) { S(x) = S(C(x, 0)) ^ S(C(x, 1)) ^ V(x); }
	void UpS(int x) {
		if(T(x)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x) = 0;
		}
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); UpS(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
	    Cn(C(x,p^1), u, p); Cn(u, x, p^1);
		UpV(x); UpV(u);
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
	int Fd(int x) {
		Acc(x); Sy(x); 
		while(C(x, 0)) UpS(x=C(x,0));
		Sy(x); 
		return x;
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	bool Cut(int x, int y) {

		Split(x, y);
		if(F(x)==y && !C(x,1)) { F(x) = C(y,0) = 0, UpV(y); return 1; }
		else return 0;
	}

	bool Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) { F(x) = y; return 1; }
		else                  return 0;
	}

	Node* operator[](const int &x) { return &Tr[x]; }
#undef F
#undef Q
#undef C
#undef T

#undef W
#undef Is
}; 

LCT<long long, N_> Tr;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in",  "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IN >> Tr[i]->vl;

	while(m--) {
		int opt, x, y; IN >> opt >> x >> y;
		switch(opt) {
			case 0: Tr.Split(x, y); cout << Tr[y]->sm << "\n"; break;
			case 1: Tr.Lk(x, y);  break;
			case 2: Tr.Cut(x, y); break;
			case 3: Tr.Sy(x), Tr[x]->vl = y; break;
		}
	}

	return 0;
} /**/




