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

template<int N>
struct LCT {
	struct Node { int vl, fa, clo, Tg[3], Ch[2]; }
	Node Tr[N];
#define V(x) Tr[x].vl
#define F(x) Tr[x].fa
#define T(x,y) Tr[x].Tg[y]
#define C(x,y) Tr[x].Ch[y]

#define W(x)  (x == C(F(x),1))
#define Is(x) (C(F(x),0) != x && C(F(x),1) != x)

	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }
	void UpV(int x) {
		T(x,0) = T(C(x,1),0); 
		T(x,1) = T(C(x,1),1);
		if(!T(x,0)) T(x,0) = vl != 1 ? x : T(C(x,0),0);
		if(!T(x,0)) T(x,0) = vl != 2 ? x : T(C(x,0),0);
	}
	void UpA(int x, int v) {
		vl ^= 
	}
	void UpS(int x) {
		if(T(x,2)) 
			UpA(C(x,0), T(x,2)), UpA(C(x,1), T(x,2));
		T(x,2) = 0;
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); UpS(x); }
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	return 0;
} /**/
