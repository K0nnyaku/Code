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

const int N_ = 10 + 7;
const int M_ = 10 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
	int u, v, w;
	Node(int u_ = 0, int v_ = 0, int w_ = 0) { u = u_; v = v_; w = w_; }
};

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T C[M];
	void Cl() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) { Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c; }
};

Edge<long long, N_, M_<<1> I;
Node A[M_];
long long Far[N_], n, m, d, ans;
bool Vv[N_];

long long Spfa(int x, int y) {
	deque<int> Q; Q.push_back(x);
	FL(Far, 0x3f); Far[x] = 0;

	while(Q.size()) {
		int x = Q.front(); Q.pop_front();
		ER(i,v,I,x,I) if(Far[v] > Far[x] + I.C[i]) {
			Far[v] = Far[x] + I.C[i];
			if(!Vv[v] && (Vv[v] = 1)) 
				if(Q.size() && Far[Q.front()] > Far[v]) Q.push_front(v);
				else									Q.push_back (v);
		}
	}
	return Far[y];
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> d;
	IR(i, 1, m) {
		long long u, v, w; IN >> u >> v >> w;
		I.AdI(u, v, w); I.AdI(v, u, w);
	}

	IR(i, 1, d) {
		long long tmp = Spfa(i, n-i+1);
		if(tmp == INF) { cout << "-1\n"; return 0; }
		ans += tmp;
	}

	cout << ans << "\n";

	return 0;
} /**/








