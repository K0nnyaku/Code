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

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T W[M];
	void AdI(int u, int v, T w) { Nt[++cnt] = I[u]; To[cnt] = v; W[I[u]=cnt] = w; }
};

const int N_ = 1e2 + 7;
const int M_ = 5e2 + 7;
const int K_ = 10 + 2;
const int INF = 0x3f3f3f3f;

Edge<int, N_, M_<<1> I;
deque<int> Q;
int F[N_][1<<K_], S[K_], n, m, k;
bool Vv[N_];

void Spfa(int k) {
	while(!Q.size()) {
		int x = Q.front(); Q.pop_front();
		Vv[x] = 0;
		ER(i,v,I,x,I) if(F[x][k] + I.W[i] < F[v][k]) {
			F[v][k] = F[x][k] + I.W[i]; 
			if(!Vv[v] && (Vv[v] = 1)) 
				if(Q.size() && F[Q.front()][k] > F[v][k]) Q.push_front(v);
				else                                      Q.push_back (v);
		}
	}
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n >> m >> k;

	IR(i, 1, m) {
		int u, v, w; IN >> u >> v >> w;
		I.AdI(u, v, w);   I.AdI(v, u, w);
	}

	FL(F, 0x3f);
	Ir(i, 0, k) IN >> S[i], F[S[i]][1<<i] = 0;

	Ir(i, 1, 1<<k+1) {
		IR(v, 1, n) {
			for(int k = i & (i-1); k; k = (k-1) & i) 
				F[v][i] = min(F[v][i], F[v][k] + F[v][i^k]);
			if(F[v][i] != INF) Q.push_front(v), Vv[i] = 1;
		}
		Spfa(i); FL(Vv, 0);
	}

	int ans = INF;

	cout << F[S[0]][(1<<k+1)-1] << "\n";

	return 0;
} /**/























