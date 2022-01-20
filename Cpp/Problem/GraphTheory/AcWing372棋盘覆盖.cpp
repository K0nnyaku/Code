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

const int N_ = 1e2 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
};

Edge<N_*N_, N_*N_> G;
long long Pos[N_][N_], Ada[N_*N_], Way[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int n, t, cnt;
bool Mp[N_][N_], Vv[N_*N_];

bool Aug(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> t;
	IR(i, 1, t) {
		int u, v; IN >> u >> v;
		Mp[u][v] = 1; 
	}

	IR(i, 1, n) IR(v, 1, n) Pos[i][v] = ++cnt;

	IR(i, 1, n) IR(v, 1, n) if(!(Pos[i][v] % 2) && !Mp[i][v] ) 
		Ir(k, 0, 4) {
			int xt = i + Way[k][0], yt = v + Way[k][1];
			if(xt >= 1 && xt <= n && yt >= 1 && yt <= n && !Mp[xt][yt] && Pos[xt][yt] % 2) 
				G.Add(Pos[i][v], Pos[xt][yt]);
		}

	long long ans = 0;
	IR(i, 1, n) IR(v, 1, n) if(!(Pos[i][v] % 2) && !Mp[i][v] ) 
		FL(Vv, 0), ans += Aug(Pos[i][v]);

	cout << ans << "\n";

	return 0;
} /**/

bool Aug(int x) {
	ER(i, v, G, x) if(!Vv[v] && (Vv[v] = 1) && (!Ada[v] || Aug(Ada[v]) ) ) return Ada[v] = x;
	return false;
}


















