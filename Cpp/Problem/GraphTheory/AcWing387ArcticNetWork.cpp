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

const int N_ = 5e2 + 2;

template<int N>
struct Uaf {
	int Fa[N];
	Uaf() { Ir(i, 1, N) Fa[i] = i; }
	int Fd(int x) { return Fa[x] = x == Fa[x] ? x : Fd(Fa[x]); }
	void Un(int x, int y) { Fa[Fd(x)] = Fd(y); }
	void Cl() { Ir(i, 1, N) Fa[i] = i; }
};

struct Node {
	int x, y; 
	Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
};

struct Adj {
	int u, v;
	double w;
	Adj(int u_ = 0, int v_ = 0, double w_ = 0) { u = u_; v = v_; w = w_; }
	friend bool operator<(const Adj &x, const Adj &y) { return x.w < y.w; }
};

Uaf<N_*N_> U;
Node P[N_];
Adj E[N_*N_], T[N_*N_];
int n, s, cnt, idx, t;
bool Vv[N_];

double Fr(int x, int y, int a, int b);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> t;

	while(t--) {
		FL(P, 0);  FL(Vv, 0);  cnt = idx = 0;
		FL(T, 0);  FL(E, 0);		  U.Cl();

		IN >> s >> n;
		IR(i, 1, n) IN >> P[i].x >> P[i].y;
		if(s >= n) { printf("%.2lf\n", 0.00); continue; }

		s = n - s;

		IR(i, 1, n) IR(v, 1, n) 
			E[cnt++] = Adj(i, v, Fr(P[i].x, P[i].y, P[v].x, P[v].y) );

		sort(E, E+cnt);

		Ir(i, 0, cnt) {
			int xFa = U.Fd(E[i].u), yFa = U.Fd(E[i].v);
			if(xFa != yFa) {
				s--;	U.Un(xFa, yFa);
				if(!s) { printf("%.2lf\n", E[i].w); break; }
			}
		}
	}
		
	return 0;
} /**/

double Fr(int x, int y, int a, int b) {
	return sqrt(pow(x-a, 2) + pow(y-b, 2));
}









