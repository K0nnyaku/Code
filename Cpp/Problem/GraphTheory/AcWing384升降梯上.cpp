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

const int M_ = 2e5 + 2;
const int N_ = 2e5 + 2;
const int K_ = 50 + 2;

template<typename T, int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N], R[N]; int cnt;
	T W[M << 1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(R, 0); cnt = 1; }
	void AdI(int u, int v, T w) { Nt[++cnt] = I[u]; W[cnt] = w; To[I[u]=cnt] = v; }
	void AdT(int u, int v, T w) { Nt[++cnt] = R[u]; W[cnt] = w; To[R[u]=cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(R, 0); cnt = 1; }
};

Edge<int, N_, M_> I;
long long Far[N_], F[N_][K_];
int n, m, t, s, f, k, P;
bool Vq[N_], Vs[N_][K_];
bool fg;

void Spfa();
long long Wk(int x, int k);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		I.Cl(); FL(F, 0); FL(Vs, 0); fg = 0;
		IN >> n >> m >> k >> P; 
		s = 1, f = n;

		IR(i, 1, m) {
			int u, v, w; IN >> u >> v >> w;
			I.AdI(u, v, w); 
			I.AdT(v, u, w);
		}

		Spfa();

		long long ans = 0;
		F[s][0] = 1;

		IR(i, 0, k && !fg) {
			ans += Wk(f, i), ans %= P;
		}
		if(!k) Wk(f, k+1); 

		if(!fg) cout << ans << "\n";
		else cout << -1 << "\n";
	}

	return 0;
} /**/
