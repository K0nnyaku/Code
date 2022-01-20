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

const int N_ = 5e3 + 10;
const int INF = 0x3f3f3f3f;

struct UnionAndFind {
	int Fa[N_];
	UnionAndFind() {
		Ir(i, 1, N_) Fa[i] = i; }
	int Find(int x) {
		return Fa[x] = x == Fa[x] ? x : Find(Fa[x]); }
	void Union(int x, int y) {
		Fa[Find(x)] = Find(y); return ; }
} Uf;

struct Edge {
	int next, to;
	Edge(int next_ = 0, int to_ = 0) {
		next = next_, to = to_; }
} E[N_ << 1];
int Head[N_];
int cnt;
void Add(int from, int to) {
	E[++cnt] = Edge(Head[from], to);
	Head[from] = cnt;
}
#define T(i) E[i].to 

vector<int> Q[N_], Id[N_], Lf;
int Dep[N_], W[N_], Lca[N_ << 1], Fa[N_ << 1];
int tot, n;
bool Vis[N_];

void Pre(int x, int last);
void Leaf(int x, int last);
void Tarjan(int x, int last);
void Mark(int x, int ed, int val);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> W[i];
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		Add(u, v); Add(v, u);
	}

	Leaf(1, 0);
	Ir(i, 0, Lf.size()) Ir(v, i+1, Lf.size()) {
		int x = Lf[i], y = Lf[v];

		Q[x].push_back(y), Q[y].push_back(x),
		Id[x].push_back(++tot), Id[y].push_back(tot);
	}

	Pre(1, 0);
	Tarjan(1, 0);
	
	Ir(i, 0, n) {
		int idx = 1;
		int ans = 0;
		Ir(p, 0, Lf.size()) Ir(q, p+1, Lf.size()) {
			int x = Lf[p], y = Lf[q];
			int lca = Lca[idx++];
			int tmp = INF;

			memset(Vis, 0, (n+10) * sizeof(int));
			Mark(x, lca, i); Mark(y, lca, i);

			IR(k, 0, n+1) if(!Vis[k])
				tmp = min(tmp, k);
			ans = max(tmp, ans);
		}
		cout << ans << " ";
	}

	return 0;
} /**/

void Pre(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Dep[T(i)] = Dep[x] + 1, Fa[T(i)] = x,
		Pre(T(i), x);
}

void Tarjan(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Tarjan(T(i), x);

	Ir(i, 0, Q[x].size()) 
		Lca[Id[x][i]] = Uf.Find(Q[x][i]);
		
	Uf.Union(x,  last ? last : x);
}

void Leaf(int x, int last) {
	bool flag = 0;
	ER(i, x) if(T(i) != last) 
		flag = 1, Leaf(T(i), x);

	if(!flag) Lf.push_back(x);
}

void Mark(int x, int ed, int val) {
	Vis[n ? (W[x] + val) % n : W[x]] = 1;
	if(x == ed) return ;

//	printf("x = %d, Fa[x] = %d, val = %d, ed = %d\n", 
//			x, Fa[x], val, ed);
	Mark(Fa[x], ed, val);
}


















