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

const int N_ = 2e2 + 2;
const int M_ = 1e3 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], I[M << 1]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u] = cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
};

Edge<N_, M_> I;
int Ada[M_];
int n, m, k;
bool Vv[M_];

bool Aug(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	while(1) {
		IN >> n; 
		if(!n) return 0;

		I.Cl(); FL(Ada, 0);

		IN >> m >> k;
		IR(i, 1, k) { 
			int u, v, pos; IN >> pos >> u >> v; 
			if(!u || !v) continue;
			I.Ad(u, v+m+n); 
		}

		int ans = 0;
		IR(i, 1, n) 
			FL(Vv, 0), ans += Aug(i);

		cout << ans << "\n";
	}
	return 0;
} /**/

bool Aug(int x) {
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v] = 1) && (!Ada[v] || Aug(Ada[v])) ) return Ada[v] = x;
	return 0;
}













