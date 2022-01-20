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

const int N_ = 5e4 + 7;
const int M_ = 1e5 + 7;
const int L_ = 60 + 3;

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T W[M];
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); cnt = 1; }
	void Add(int u, int v, T w) { Nt[++cnt] = I[u]; To[cnt] = v; W[I[u]=cnt] = w; }
};

template<int N>
struct LinearBasic {
	long long A[N];
	LinearBasic() { FL(A, 0); }
	void Ins(long long x) {
		Sr(i, L_, 0) {
			if(!(x >> i)) continue;
			if(!A[i]) { A[i] = x; return ; }
			x ^= A[i];
		}
	}
	long long Max(long long x) {
		Sr(i, L_, 0) if((x ^ A[i]) > x) 
			x ^= A[i];
		return x;
	}
};

Edge<long long, N_, M_<<1> I;
LinearBasic<L_> B;
long long Val[N_];
int n, m;
bool Vv[N_];

void MkLp(int x, long long res);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) {
		int u, v; long long w;
		IN >> u >> v >> w;
		I.Add(u, v, w); I.Add(v, u, w);
	}

	Vv[1] = 1; MkLp(1, 0);

	cout << B.Max(Val[n]);

	return 0;
} /**/

void MkLp(int x, long long val) {
	Val[x] = val;
	ER(i,v,I,x,I) 
		if(!Vv[v] && (Vv[v] = 1)) MkLp (v, val^I.W[i]);
		else                      B.Ins(val^Val[v]^I.W[i]);
}













