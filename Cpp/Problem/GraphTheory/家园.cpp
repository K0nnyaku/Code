linclude<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
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

template<int N>
struct UAF {
	int Fa[N];
	UAF() { Ir(i, 1, N) Fa[i] = i; }

	int  Fd (int x)        { return Fa[x] = x == Fa[x] ? x : Fd(Fa[x]); }
	void Un (int x, int y) { Fa[Fd(x)] = Fd(y); }
	bool Chk(int x, int y) { return Fd(x) == Fd(y); }
};

const int N_ = 13 + 7;
const int M_ = 20 + 7;
const int K_ = 50 + 7;

UAF   <N_> U;
Dinic <int, N_*K_> I;
vector<int> Sp[M_];
int C[M_], n, m, k;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/P2754_2.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> k;
	IR(i, 1, m) {
		int x, y; IN >> C[i] >> x;
		while(x--) {
			IN >> y; 
			if(y == -1) y = n+2;
			else        y++;
			Sp[i].push_back(y);
		}
	}

	IR(i, 1, m) Ir(v, 1, Sp[i].size()) 
		U.Un(Sp[i][0], Sp[i][v]);

	n += 2;
	if(!U.Chk(1, n)) { cout << 0 << "\n"; return 0; }
	
	int res = 0;
	I.AdI(0, 1, k);
	for(int i = 1; ; i++) {
		IR(v, 1, m) {
			auto T = Sp[v];
			I.AdI(T[(i-1) % T.size()] + n*(i-1), T[i % T.size()] + n*i, C[v]);
		}

		IR(v, n*(i-1)+1, n*i) I.AdI(v, v+n, k);

		res += I.Solve(0, n * (i+1), k);

		if(res >= k) { cout << i; break; }
	}

	return 0;
} /**/
















