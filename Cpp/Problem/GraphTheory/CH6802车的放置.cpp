#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 2e2 + 2;
const int M_ = 2e2 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; int cnt;

	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
};

Edge<N_ + M_, M_ + N_> G;
int Ada[N_ + M_];
int n, m, t;
bool Mp[N_][M_], Vv[N_ + M_];

bool Aug(int x);

int main() { /**/
#ifdef LOCAL
//	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/CH6802/input1", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> t;
	while(t--) { int u, v; IN >> u >> v; Mp[u][v] = 1; }

	IR(i, 1, n) IR(v, 1, m) if(!Mp[i][v]) G.Add(i, v+n);

	int ans = 0;
	IR(i, 1, n) 
		FL(Vv, 0), ans += Aug(i);

	cout << ans << "\n";

	return 0;
} /**/

bool Aug(int x) {
	ER(i, v, G, x) if(!Vv[v] && (Vv[v] = 1) && (!Ada[v] || Aug(Ada[v])) ) return Ada[v] = x;
	return false;
}









