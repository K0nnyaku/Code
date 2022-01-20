#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

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

template<typename T, int N>
struct Dinic {

	struct Edge { 
		int v, r; T c; 
		Edge(int v_ = 0, int r_ = 0, T c_ = 0) { v = v_; r = r_; c = c_; }
	};

	void AdI(int u, int v, T c) {
		I[u].push_back(Edge(v, I[v].size()  , c));				
		I[v].push_back(Edge(u, I[u].size()-1, 0));
	}

	bool BFS(int og, int sk) {
		FL(H, 0);   FL(Ep, 0); 
		Ep[og] = 1; Q.push(og);

		while(Q.size()) {
			int x = Q.front(); Q.pop();	
			for(auto e: I[x]) if(e.c && !Ep[e.v]) 
				Ep[e.v] = Ep[x] + 1, Q.push(e.v);
		}
		return Ep[sk] != 0;
	}

	T DFS(int x, int sk, T fl) {
		if(x == sk) return fl;	
		T res = fl; auto &E = I[x];

		for(auto e = E.begin() + H[x]; e != E.end(); e++, H[x]++) 
			if(e->c && Ep[e->v] == Ep[x] + 1) {
				T k = DFS(e->v, sk, min(e->c, res));

				e->c -= k; I[e->v][e->r].c += k; res -= k;	

				if(!res) return fl;
			}
		return fl - res;
	}

	T Solve(int og, int sk, T inf) {
		T res = 0;
		while(BFS(og, sk)) 
			res += DFS(og, sk, inf);
		return res;
	}

	vector<Edge> I[N]; queue<int> Q;
	int H[N], Vv[N], Ep[N];
};

const int N_  = 2e2 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

Dinic<long long, N_> I;
int n, m, og, sk;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> og >> sk;

	IR(i, 1, m) { 
		int u, v; long long c; 
		IN >> u >> v >> c; I.AdI(u, v, c); 
	}

	cout << I.Solve(og, sk, INF);

	return 0;
} /**/








