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

const int N_ = 1e3 + 3;

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T W[M];
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); cnt = 1; }
	void Add(int u, int v, T w) { Nt[++cnt] = I[u]; To[cnt] = v; W[I[u]=cnt] = w; }
};

Edge<int, N_<<1, N_*3> I;
int X[N_*N_], Y[N_*N_], Z[N_*N_];
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n >> m;
	IR()<++>

	return 0;
} /**/










