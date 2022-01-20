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

const int N_ = 1e5 + 2;

struct Edge {
	int next, to, val;
	Edge(int next_ = 0, int to_ = 0, int val_ = 0) {
		next = next_, to = to_, val = val_;
	}
}E[N_ << 1];
int Head[N_];
int cnt;
void Add(int from, int to, int val) {
	E[++cnt] = Edge(Head[from], to, val);
	Head[from] = cnt;
}
#define T(x) E[x].to
#define V(x) E[x].val

struct Node {
	int u, v;
	Node(int u_ = 0, int v_ = 0) {
		u = u_; v = v_;
	}
	friend bool operator<(const Node &x, const Node &y) {
		return x.u == y.u ? x.v < y.v : x.u < y.u;
	}
};

map<Node, bool> Mp;
int Pre[N_], F[N_], D[N_];
int n, tp, tq, dia, k;
bool Vis[N_];

void Ddf(int x, int last, int dis);
void Dds(int x);
int Dp(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> n >> k;
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		Add(u, v, 1); Add(v, u, 1);
	}

	Vis[1] = true;
	Ddf(1, 0, 0);
	tq = tp;
	memset(Vis, 0, sizeof Vis);
	Vis[tq] = true;
	Ddf(tp, Pre[tp], 0);

	Dds(tp);

	if(k == 1) {
		cout << 2 * (n-1) - dia + 1 << "\n";
		return 0;
	}

	Dp(1, 0);
	IR(i, 2, n) F[1] = max(F[1], F[i]);

	cout << 2 * (n-1) - dia - F[1] + 2 << "\n";

	return 0;
} /**/

void Ddf(int x, int last, int dis) {
	if(dis >= dia) dia = dis, tp = x;
	Pre[x] = last;
	ER(i, x) if(!Vis[T(i)] && (Vis[T(i)] = true)) 
		Ddf(T(i), x, dis+1);
}

void Dds(int x) {
	Mp[Node(x, Pre[x])] = 1;	
	Mp[Node(Pre[x], x)] = 1;	
	if(x == tq) return ;
	Dds(Pre[x]);
}

int Dp(int x, int last) {
	ER(i, x) if(T(i) != last) {
		int ver = Mp[Node(x, T(i))] ? -V(i) : V(i);
		int tmp = Dp(T(i), x) + ver;
		F[x] = max(F[x], D[x] + tmp);
		D[x] = max(D[x], tmp);
	}
	return D[x];
}




















