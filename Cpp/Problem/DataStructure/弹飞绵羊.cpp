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

const int N_ = 2e5 + 7;

template<int N>
struct LCT {
	struct Node {
		int qt, fa, tg, ch[2];
		Node(int qt_ = 1) { qt = qt_; fa = tg = ch[0] = ch[1] = 0; }
	};
	Node Tr[N];
	LCT() { Tr[0].qt = 0; }

#define T(x) Tr[x].tg
#define Q(x) Tr[x].qt
#define F(x) Tr[x].fa
#define C(x, y) Tr[x].ch[y]

#define W(x)   (x == C(F(x), 1))
#define Is(x)  (C(F(x),0) != x && C(F(x),1) != x)

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }

	void UpV(int x) { Q(x) = Q(C(x,0)) + Q(C(x,1)) + 1; }
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

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y); 
		if(F(x) == y && !C(x,1)) C(y, 0) = F(x) = 0, UpV(y);
	}

	void Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
	}
	
	Node* operator[](const int &x) { return &Tr[x]; }
};
LCT<N_> Tr;

int W[N_];
int n, m, sk;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/P3203_1.in", "r", stdin);
//	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	sk = n+1;

	IR(i, 1, n) {
		IN >> W[i];
		if(i+W[i] <= n) Tr.Lk(i, i+W[i]); 
		else Tr.Lk(i, sk);
	}

	IN >> m;
	IR(i, 1, m) {
		int opt, x, y;
		IN >> opt >> x;
		x++;
		if(opt == 1)  Tr.CgRt(x), Tr.Acc(sk), Tr.Sy(sk), cout << Tr[sk]->qt - 1 << "\n";
		else {
			if(x + W[x] <= n) Tr.Cut(x, x+W[x]);
			else              Tr.Cut(x, sk);
			IN >> W[x];
			if(x + W[x] <= n) Tr.Lk(x, x+W[x]); 
			else              Tr.Lk(x, sk);
		}
	}

	return 0;
} /**/












