#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

const int N_ = 1e5 + 5;
const int M_ = 2e5 + 5;

struct Edge {
	int next, to;
	Edge(int next_ = 0, int to_ = 0) {
		next = next_; to = to_;
	}
} E[N_ << 1];
int Head[N_];
int cnt;
void Add(int from, int to) {
	E[++cnt] = Edge(Head[from], to);
	Head[from] = cnt;
}
#define T(i) E[i].to

struct UnionAndFind {
	int Fa[N_];
	UnionAndFind() {
		Ir(i, 1, N_) Fa[i] = i; }

	void Union(int x, int y) {
		Fa[Find(x)] = Find(y); }

	int Find(int x) {
		return Fa[x] = Fa[x] == x ? x : Find(Fa[x]); }
} Uf;

struct Node {
	int x, y;
	Node(int x_ = 0, int y_ = 0) {
		x = x_; y = y_; }
}T[M_];

vector<int> Q[N_], Id[N_];
int W[N_], Lca[M_];
int n, m, ans;

int Solve(int x, int last);
void Tarjan(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		Add(u, v); Add(v, u);
	}
	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		T[i] = Node(u, v);
		Q[u].push_back(v); Q[v].push_back(u);
		Id[u].push_back(i); Id[v].push_back(i);
	}

	Tarjan(1, 0);

	IR(i, 1, m) {
		int x = T[i].x, y = T[i].y, lca = Lca[i];
		W[x]++, W[y]++, W[lca] -= 2;
	}

	Solve(1, 0);

	cout << ans << "\n";

	return 0;
} /**/

void Tarjan(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Tarjan(T(i), x);

	Ir(i, 0, Q[x].size()) 
		Lca[Id[x][i]] = Uf.Find(Q[x][i]);

	Uf.Union(x, last != 0 ? last : x);
}

int Solve(int x, int last) {
	ER(i, x) if(T(i) != last) 
		W[x] += Solve(T(i), x);

	if(x == 1) return 0;

	if(!W[x]) ans += m;
	else ans += W[x] == 1;

	return W[x];
}




















