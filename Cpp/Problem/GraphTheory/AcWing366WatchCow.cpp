#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int  i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 1e4 + 2;
const int M_ = 5e4 + 2;

template<typename T, int N>
struct Stack {
	T A[N]; int tp, sum;

	Stack() { FL(A, 0); tp = sum = 0; }

	T Tp() { return A[tp]; }
	int Num() { return sum; }
	void Ph(const T &x) { A[sum = ++tp] = x; }
	void Pp() { sum = --tp; }
};

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N];
	int cnt;
	
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
};

Edge<N_, M_> G;
Stack<int, M_ << 1> Sk;
int n, m;

void Euler(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) { int u, v; IN >> u >> v; G.Add(u, v); G.Add(v, u); }

	Euler(1);

	cout << 1 << "\n";
	while(Sk.Num()) cout << Sk.Tp() << "\n", Sk.Pp();

	return 0;
} /**/

void Euler(int x) {
	for(int i = G.Hd[x], v = G.To[i]; i; i = G.Hd[x], v = G.To[i])
		G.Hd[x] = G.Nt[i], Euler(v), Sk.Ph(v);
}














