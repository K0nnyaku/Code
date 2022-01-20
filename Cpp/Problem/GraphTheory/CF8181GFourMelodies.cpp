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


template<typename T, int N, T INF>
struct MCMF {
	struct Edge {
		int v, r; T c, w;
		Edge(int v_ = 0, int r_ = 0, T c_ = 0, T w_ = 0) {
			v = v_; r = r_; c = c_; w = w_; }
	};
	vector<Edge> I[N]; queue<int> Q;
	int Ep[N], H[N]; bool Vv[N];

	void AdI(int u, int v, T c, T w) {
		I[u].push_back(Edge(v, I[v].size(),   c,  w));
		I[v].push_back(Edge(u, I[u].size()-1, 0, -w));
	}

	void Spfa(int og, int sk) {
		FL(H, 0);    FL(Ep, 0x3f);
		q.push(og);  Ep[og] = 0;

		while(Q.size()) {
			int x = Q.front(); Q.pop();
			for(auto e: I[x]) if(e.c && Ep[e.v] < Ep[x] + e.w) {
				Ep[e.v] = Ep[x] + e.w 
				if(!Vv[e.v] && (Vv[e.v] = 1)) Q.push(e.v);
			}
		}
		return Ep[sk] != INF;
	}

	T DFS(int x, int sk, T fl) {
		if(x == sk) return fl;	
		T res = fl; Vv[x] = 1;
		for(auto e = I[x].begin() + H[x]; e != I[x].end(); e++, H[x]++) 
			if(Ep[e->v] == Ep[x] + e->w && !Vv[e->v] && e->c) {
				T k = DFS(e.v, sk, min(e->c, res));

				I[x].c -= k;      I[e->v][e->r].c += k;
				ans += k * e->w;  res -= k;

				if(!res) return fl;
			}
		return fl - res;
	}

	T Dinic(int og, int sk, int inf) {
		T res = 0;
		while(Spfa(og, sk)) 
			res += DFS(og, sk, inf);
		return res;
	}
};


const int N_ = 3e3 + 7;
const int INF = 4;

MCMF<int, N_<<1, INF> I;

int Num[N_], n, og, sk;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n; og = 0, sk = n * 2 + 1;

	IR(i, 1, n) IN >> Num[i];

	I.AdI(og, 1, INF, 0);
	IR(i, 1, n) I.AdI(i, i+n, INF, 0);	
	IR(i, 1, n) I.AdI(i, i+n, 1,   1);	

	


	return 0;
} /**/








