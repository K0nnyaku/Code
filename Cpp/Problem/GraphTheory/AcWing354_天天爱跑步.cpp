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

const int N_ = 3e5 + 2;
const int M_ = 3e5 + 2;
const int V_ = N_ + 10;

struct UnionAndFind {
	int Fa[N_];
	UnionAndFind() {
		Ir(i, 1, N_) Fa[i] = i; }

	int Find(int x) {
		return Fa[x] = Fa[x] == x ? x : Find(Fa[x]); }

	void Union(int x, int y) {
		Fa[Find(x)] = Find(y); }
} Uf;

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

struct Node {
	int x, y; 
	Node(int x_ = 0, int y_ = 0) {
		x = x_; y = y_; }
} M[M_];

vector<int> Ad_On[M_], Del_On[M_], Ad_Do[M_], Del_Do[M_], Q[N_], Id[N_];
long long D[N_], W[N_], Lca[M_], Fa[N_], C_On[M_+V_], C_Do[M_ + V_], Ans[N_];
long long n, m, ans;

void MakeD(int x, int last);
void Tarjan(int x, int last);
void Solve(int x, int last);

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

	IR(i, 1, n) IN >> W[i];

	IR(i, 1, m) {
		int s, t; IN >> s >> t;
		M[i] = Node(s, t);
		Q[s].push_back(t); Q[t].push_back(s);
		Id[s].push_back(i); Id[t].push_back(i);
	}

	MakeD(1, 0);

	Tarjan(1, 0);

	IR(i, 1, m) {
		int x, y, lca, fa;
		x = M[i].x, y = M[i].y, lca = Lca[i], fa = Fa[lca];

		Ad_On[x].push_back(D[x] + V_), Del_On[fa].push_back(D[x] + V_);
		Ad_Do[y].push_back(D[x] - 2 * D[lca] + V_), Del_Do[lca].push_back(D[x] - 2 * D[lca] + V_);
	}

	Solve(1, 0);

	IR(i, 1, n) 
		cout << Ans[i] << " ";

	return 0;
} /**/

void MakeD(int x, int last) {
	ER(i, x) if(T(i) != last) 
		D[T(i)] = D[x] + 1, Fa[T(i)] = x, 
		MakeD(T(i), x);
}

void Solve(int x, int last) {
	long long fcnt = C_On[W[x] + D[x] + V_], scnt = C_Do[W[x] - D[x] + V_];

	Ir(i, 0, Ad_On[x].size()) C_On[Ad_On[x][i]]++;
	Ir(i, 0, Del_On[x].size()) C_On[Del_On[x][i]]--;

	Ir(i, 0, Ad_Do[x].size()) C_Do[Ad_Do[x][i]]++;
	Ir(i, 0, Del_Do[x].size()) C_Do[Del_Do[x][i]]--;

	ER(i, x) if(T(i) != last) 
		Solve(T(i), x); 

	Ans[x] = C_On[W[x] + D[x] + V_] - fcnt + 
		     C_Do[W[x] - D[x] + V_] - scnt;
}

void Tarjan(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Tarjan(T(i), x);

	Ir(i, 0, Q[x].size())
		Lca[Id[x][i]] = Uf.Find(Q[x][i]);

	Uf.Union(x, last ? last : x);
}









