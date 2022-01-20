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

const int N_ = 5e4 + 2;
const int E_ = 20 + 2;

struct Edge {
	int next, to; long long val;

	Edge(int next_ = 0, int to_ = 0, long long val_ = 0) {
		next = next_; to = to_; val = val_; 
	}
} E[N_ << 1];
int Head[N_];
int cnt;
#define T(i) E[i].to

void Add(int from, int to, long long val) {
	E[++cnt] = Edge(Head[from], to, val);
	Head[from] = cnt; 
}

long long sum;
int F[N_][E_], Dep[N_], Am[N_], P[N_][E_];
int n, m;

bool Check(long long x);

void Pre(int x, int last);
void Dp();
int Lca(int x, int y);
int Up(int x, int w);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	Ir(i, 1, n) {
		int u, v; long long w; 
		IN >> u >> v >> w;
		Add(u, v, w); Add(v, u, w); 
	}
	IR(i, 1, m) {
		int x; IN >> x;
		Am[x]++; 
	}

	Pre(1, 0);
	Dp();

	long long l = 0, r = sum+1;
	while(l < r) {
		long long mid = (l + r) >> 1;
		if(Check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << (l != sum+1 ? l : -1) << "\n";

	return 0;
} /**/

void Pre(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Dep[T(i)] = Dep[x] + 1, F[T(i)][0] = x,
		Pre(T(i), x);
}

void Dp() {
	Ir(e, 1, E_) IR(i, 1, n) 
		F[i][e] = F[F[i][e-1]][e-1];
}

struct Node {
	int loc; long long res;
	Node(int loc_ = 0, long long res_ = 0) {
		loc = loc_, res = res_; }
	friend bool operator<(const Node &x, const Node &y) {
		return x.res < y.res; }
};

bool Check(long long x) {
	vector<Node> Fr, Ar;
	bool Vis[N_];
	memset(Vis, 0, sizeof Vis);

	IR(i, 1, n) 
		if(Dep[i] >= x) Vis[Up(i, x)] = 1;
		else Fr.push_back( Node(Up(i, x), x - Dep[i] - Up(i, x)) );

	IR(i, 1, n) if(!Vis[i]) Ar.push_back(Node(i, Dep[i]));

	sort(Ar.begin(), Ar.end());
	sort(Fr.begin(), Fr.end());

	int p = -1, q = -1;
	while(p < Fr.size() && ++q < Ar.size())
		while(++p < Fr.size() && Fr[p].res < Dep[Ar[q].loc] + Dep[Fr[p].loc]);

	return q == Ar.size() - 1;
}

int Up(int x, long long w) {
	SR(e, E_ - 1, 0) if(Dep[P[x][e]] - Dep[x] <= w && P[x][e] != rt && P[x][e])
		w -= Dep[P[x][e]] - Dep[x], x = P[x][e]; 
	return x;
}



















