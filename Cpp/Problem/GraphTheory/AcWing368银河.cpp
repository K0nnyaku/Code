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

const int N_ = 2e5 + 2;
const int M_ = 2e5 + 2;

#define int long long

template<typename T, int N>
struct Stack {
	T A[N]; int tp, num;
	Stack() { FL(A, 0); tp = num = 0; }

	T Tp() { return A[tp]; }
	void Ph(const T &x) { A[num = ++tp] = x; }
	void Pp() { num = --tp; }
};

template<typename T, int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; int cnt;
	T Val[M << 1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v, T w) { Nt[++cnt] = Hd[u]; Val[cnt] = w; To[Hd[u] = cnt] = v; }
};

struct Node {
	int x, y;
	Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
};

Stack<int, N_> Sk;
Edge<int, N_, M_> G, S;
vector<int> Scc[N_];
int Far[N_], Low[N_], Dfn[N_], Mscc[N_], Sscc[N_];
int n, m, ns, pos, cnt;
bool Vv[N_], Vsk[N_];

void Tarjan(int x);
template<typename T, int N, int M>
void Spfa(const Edge<T, N, M>& G, int s);

signed main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) {
		int opt, a, b; IN >> opt >> a >> b;
		switch(opt) {
			case 1: G.Add(b, a ,0); G.Add(a, b, 0); break;
			case 2: G.Add(a, b, 1); break;
			case 3: G.Add(b, a, 0); break;
			case 4: G.Add(b, a, 1); break;
			case 5: G.Add(a, b, 0); break;
		}
	}
	IR(i, 1, n) G.Add(0, i, 1);

	Tarjan(0);

	IR(i, 0, n) ER(v, k, G, i) 
		if(Mscc[i] != Mscc[k]) 
			S.Add(Mscc[i], Mscc[k], G.Val[v]);
		else Sscc[Mscc[i]] += G.Val[v];

	IR(i, 1, cnt) if(Sscc[i] > 0 && Scc[i].size() > 1) { cout << "-1\n"; return 0; }

	Spfa(S, Mscc[0]);

	int ans = 0;
	IR(i, 1, cnt) 
		ans += Far[i] * Scc[i].size();

	cout << ans << "\n";

	return 0;
} /**/

void Tarjan(int x) {
	Low[x] = Dfn[x] = ++pos;
	
	Sk.Ph(x); Vsk[x] = 1;
	ER(i, v, G, x) 
		if(!Dfn[v]) Tarjan(v), Low[x] = min(Low[x], Low[v]);
		else if(Vsk[v])		   Low[x] = min(Low[x], Dfn[v]);

	if(Dfn[x] == Low[x]) {
		cnt++;
		int y;
		do {
			y = Sk.Tp();		    Sk.Pp();
			Scc[cnt].push_back(y);
			Mscc[y] = cnt;			Vsk[y] = 0;
		}while(y != x);
	}
}

template<typename T, int N, int M>
void Spfa(const Edge<T, N, M> &G, int s) {
	queue<int> Q; Q.push(s); 
	FL(Vv, 0);	   Vv[s] = 1;
	FL(Far, 0xcf); Far[s] = 0;

	while(Q.size()) {
		int tp = Q.front(); Q.pop();
		Vv[tp] = 0;

		ER(i, v, G, tp) if(Far[v] < Far[tp] + G.Val[i]) {
			if(!Vv[v]) Q.push(v), Vv[v] = 1;
			Far[v] = Far[tp] + G.Val[i];
		}
	}
}










