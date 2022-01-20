#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

#define DG(x) (cout << "Debug:" << #x << "=" << x << "\n")
#define ERROR    (cout << "ERROR\n")

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

template<int N>
struct LCT {
	struct Node { int fa, tg, Ch[2], Qt[2]; }
	Node Tr[N];
#define F(x)   Tr[x].fa
#define T(x)   Tr[x].tg
#define C(x,y) Tr[x].Ch[y]
#define Q(x,y) Tr[x].Qt[y]

#define W(x)  (x == C(F(x),1))
#define Is(x) (x != C(F(x),0) && x != C(F(x),1))

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }
	void UpS(int x) { Q(x, 0) = Q(C(x,0), 0) + Q(C(x,1), 0) + Q(x, 1) + 1; }

	void SpS(int x) {
		if(T(x)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			kjkjkjkj
			T(x) = 0;
		}
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); SpS(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
		Cn(C(x,p^1), u, p); Cn(u, x, p^1); 
		UpS(u);
	}
	void Sy(int x) {
		Sp(x);
		for(int y; y = F(x), !Is(x); Rot(x)) 
			if(!Is(y)) Rot(W(x) == W(y) ? y : x);
		UpS(x);
	}

	void Acc(int x) {
		for(int y = 0; x; x = F(y=x)) 
			Sy(x), Q(x, 1) += Q(C(x,1),0) - Q(y,0), C(x,1) = y, UpS(x);
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F(x)==y && !C(x,1)) F(x) = C(y,0) = 0;
		else                   ERROR;
//		UpS(y); 
	}
	void Link(int x, int y) {
		Split(x, y);
		if(!F(x)) Q(y,1) += Q(x,0), F(x) = y;
		else      ERROR;
//		UpS(y);
	}
	Node* operator[](const int& x) { return &Tr[x]; }
};

const int N_ = 1e5 + 7;

LCT<N_> Tr;
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	IR(i, 1, m) {
		char opt = getchar(); 
		int u, v; IN >> u >> v;

		if(opt == 'A') Tr.Link(u, v);
		else {
			Tr.Cut(u, v);
			Tr.CgRt(u); Tr.CgRt(v);
			cout << Tr[u]->Qt[0] * Tr[v]->Qt[0] << "\n";
			Tr.Link(u, v);
		}
	}

	return 0;
} /**/























