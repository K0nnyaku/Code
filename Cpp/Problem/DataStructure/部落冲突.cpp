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

template<int N>
struct LCT {
	struct Node { int fa, tg, Ch[2]; };
	Node Tr[N];

#define F(x) Tr[x].fa
#define T(x) Tr[x].tg
#define C(x,y) Tr[x].Ch[y]

#define W(x)  (x == C(F(x), 1))
#define Is(x) (C(F(x),0) != x && C(F(x),1) != x)

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y,p) = x; }
	void Up(int x) {
		if(T(x)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x) = 0;
		}
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); Up(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
		Cn(C(x,p^1), u, p); Cn(u, x, p^1);
	}

	void Sy(int x) {
		Sp(x);
		for(int y; y=F(x), !Is(x); Rot(x)) 
			if(!Is(y)) Rot(W(x) == W(y) ? y : x);
	}

	void Acc(int x) {
		for(int y = 0; x; x = F(y=x))
			Sy(x), C(x,1) = y;
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F(x)==y && !C(x,1)) F(x) = C(y,0) = 0;
	}
	void Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
	}
	Node* operator[](const int &x) { return &Tr[x]; }
};
LCT<N_> Tr;
int n, m;

struct Node {
	int u, v; 
	Node(int u_ = 0, int v_ = 0) { u = u_; v = v_; }
};

Node W[M_];
int cnt;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/P3950_1.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
//	double st = clock();
	IN >> n >> m;

	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		Tr.Lk(u, v);
	}

	IR(i, 1, m) {
		char opt = getchar();
		while(opt != 'U' && opt != 'C' && opt != 'Q')
			opt = getchar();

		int x, y;
		if(opt == 'U') 
			IN >> x, Tr.Lk(W[x].u, W[x].v);
		else 
		if(opt == 'C') 
			IN >> x >> y, Tr.Cut(x, y), W[++cnt] = Node(x, y);
		else {
			IN >> x >> y;
			Tr.Split(x, y);
			while(Tr[y]->Ch[0]) y = Tr[y]->Ch[0];	
			if(y == x) cout << "Yes\n";
			else       cout << "No\n";
		}
	}

//	cout << clock() - st << "\n";
	return 0;
} /**/









