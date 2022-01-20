#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
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

const int N_ = 1e5 + 2;
const int M_ = 2e5 + 2;
const int E_ = 20 + 2;

template<int N>
struct Uaf {
	int Fa[N];
	Uaf() {
		Ir(i, 1, N) Fa[i] = i; }
	int Fd(int x) {
		return Fa[x] = x == Fa[x] ? x : Fd(Fa[x]); }
	void Un(int x, int y) {
		Fa[Fd(x)] = Fd(y); }
	int& operator[](const int &x) {
		return Fa[x]; }
};

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; 
	int cnt;
	Edge() {
		FL(Nt, 0); FL(To, 0); FL(Hd, 0);	
		cnt = 1; }
	void Add(int u, int v) {
		Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
	void Cl() {
		FL(Nt, 0); FL(To, 0); FL(Hd, 0);	
		cnt = 1; }
};

Edge<N_, M_> G, S;
Uaf<N_> U;
int Dfn[N_], Low[N_], Dcc[N_], F[N_][E_], Dep[N_];
int T, n, m, cnt, sum, q, idx;
bool Bg[M_ << 1], Vis[N_], Mark[N_];

void Tarjan(int x, int last, int pos);
void Fdcc(int x);
void Pre(int x, int last);
void Dp();
int Lca(int x, int y);
int Mk(int u, int v);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	do {
		G.Cl(); S.Cl(); sum = 0;
		FL(Dfn, 0); FL(Low, 0);
		FL(Vis, 0); FL(Bg, 0);
		FL(Mark, 0); cnt = 0;

		IR(i, 1, m) {
			int u, v; IN >> u >> v;
			G.Add(u, v); G.Add(v, u);
		}

		Tarjan(1, 0, 1);

		IR(i, 1, n) if(!Vis[i]) cnt++, Fdcc(i);

		for(int i = 2; i <= G.cnt; i+=2)
			if(Bg[i]) {
				int u = Dcc[G.To[i]], v = Dcc[G.To[i^1]];
				S.Add(u, v); S.Add(v, u);
				sum++;
			}

		Dep[1] = 1;
		Pre(1, 0);
		Dp();
		
		cout << "Case " << ++idx << ":" << "\n";
		IN >> q;
		while(q--) {
			int u, v; IN >> u >> v;
			if(Dcc[u] == Dcc[v]) cout << sum << "\n";
			else cout << (sum -= Mk(Dcc[u], Dcc[v])) << "\n";
		}
		cout << "\n";

		IN >> n >> m;

	} while(n + m);

	return 0;
} /**/

void Tarjan(int x, int last, int pos) {
	Low[x] = Dfn[x] = pos;

	ER(i, v, G, x) if(i != (last ^ 1))
		if(!Dfn[v]) 
			Tarjan(v, i, pos+1), Low[x] = min(Low[x], Low[v]),
			Bg[i] = Bg[i^1] = (Bg[i] | (Dfn[x] < Low[v]));
		else
			Low[x] = min(Low[x], Dfn[v]);
}

void Fdcc(int x) {
	Vis[x] = 1; Dcc[x] = cnt;
	ER(i, v, G, x) if(!Bg[i] && !Vis[v]) Fdcc(v);
}

void Dp() {
	Ir(e, 1, E_) IR(i, 1, n) 
		F[i][e] = F[F[i][e-1]][e-1];
}

int Lca(int x, int y) {
	if(Dep[x] < Dep[y]) swap(x, y);
	SR(e, E_-1, 0) if(Dep[F[x][e]] >= Dep[y]) x = F[x][e];
	if(x == y) return x;

	SR(e, E_-1, 0) if(F[x][e] != F[y][e]) 
		x = F[x][e], y = F[y][e];
	return F[x][0];
}

void Pre(int x, int last) {
	F[x][0] = last;

	ER(i, v, S, x) if(v != last) 
		Dep[v] = Dep[x] + 1, Pre(v, x);
}

int Mk(int u, int v) {
	int res = 0, lca = Lca(u, v);

#ifdef Debug
	cout << "\n=======================\n";
	printf("u = %d, v = %d, lca = %d\n", u, v, lca);
	cout << "\n=======================\n";
#endif

	while(u != lca) {
		res += !Mark[u]; Mark[u] = 1;

		int fa = U.Fd(u);
		if(F[u][0] == lca) break;
		if(fa == u) u = F[u][0], U.Un(fa, u);
		else if(Dep[fa] <= Dep[lca]) break;
		else u = fa;
	}
	while(v != lca) {
		res += !Mark[v]; Mark[v] = 1;

		int fa = U.Fd(v);
		if(F[v][0] == lca) break;
		if(fa == v) v = F[v][0], U.Un(fa, v);
		else if(Dep[fa] <= Dep[lca]) break;
		else v = fa;
	}

	return res;
}





