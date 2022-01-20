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
const int M_ = 3e5 + 2;
const int E_ = 20 + 2;
const long long INF = 0x7f7f7f7f7f7f7f7f;

struct Edge {
	int next, to, val;
	Edge(int next_ = 0, int to_ = 0, long long val_ = 0) {
		next = next_, to = to_, val = val_; }
} E[M_ << 1];
int Head[N_];
int cnt;
void Add(int from, int to, long long val) {
	E[++cnt] = Edge(Head[from], to, val);
	Head[from] = cnt; 
}
#define T(i) E[i].to
#define V(i) E[i].val

struct Adj {
	int x, y;
	long long val;
	Adj(int x_ = 0, int y_ = 0, long long val_ = 0) {
		x = x_, y = y_, val = val_; }
	friend bool operator<(const Adj &x, const Adj &y) {
		return x.val < y.val; }
} Te[M_];

struct UnionAndFind {
	int Fa[N_];

	UnionAndFind() {
		Ir(i, 1, N_) Fa[i] = i; }

	int Find(int x) {
		return Fa[x] = Fa[x] == x ? x : Find(Fa[x]); }

	bool Ask(int x, int y) {
		return Find(x) == Find(y); }

	void Union(int x, int y) {
		Fa[Find(x)] = Find(y); }
} Uf;

long long F[N_][E_][2];
long long sum;
int n, m;
int Dep[N_], P[N_][E_];
bool Vis[M_];

pair<long long, long long> Mx(long long x, long long y);
void Pre(int x, int last);
void MakeP();
void MakeF();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	Ir(i, 0, m) {
		int u, v; long long w; 
		IN >> u >> v >> w;
		Te[i] = Adj(u, v, w);
	}

	sort(Te, Te + m);

	Ir(i, 0, m) {
		int x = Te[i].x, y = Te[i].y;
		long long val = Te[i].val;

		if(Uf.Ask(x, y)) continue;

		Uf.Union(x, y);

		sum += val; Vis[i] = 1;
		Add(x, y, val); Add(y, x, val);
	}

	Pre(1, 0);

	MakeP();
	MakeF();

	long long ans = INF;
	Ir(i, 0, m) if(!Vis[i]) {
		int x = Te[i].x, y = Te[i].y;
		long long val = Te[i].val;
		pair<long long, long long> p = Mx(x, y);
		long long mx = p.first, mxx = p.second;	

//		printf("x = %d, y = %d, mx = %lld, mxx = %lld\n", x, y, mx, mxx);
//		cout << -INF << "\n";
//		cout << (mxx == -INF) << "\n";

		if(val > mx)		ans = min(ans, sum + val - mx);
		else if(val == mx && mxx != -INF)  ans = min(ans, sum + val - mxx);
	}

	cout << ans;

	return 0;
} /**/

void Pre(int x, int last) {
	ER(i, x) if(T(i) != last) 
		Dep[T(i)] = Dep[x] + 1,
		F[T(i)][0][0] = V(i), P[T(i)][0] = x,
		Pre(T(i), x);
}

void MakeP() {
	Ir(e, 1, E_) IR(i, 1, n) if(P[i][e-1])
		P[i][e] = P[P[i][e-1]][e-1];
}

void MakeF() {
	Ir(e, 1, E_) IR(i, 1, n) if(P[i][e]) 
		F[i][e][0] = max(F[i][e-1][0], F[P[i][e-1]][e-1][0]),
		F[i][e][1] = F[i][e-1][0] != F[P[i][e-1]][e-1][0] ?
						min(F[i][e-1][0], F[P[i][e-1]][e-1][0]) : max(F[i][e-1][1], F[P[i][e-1]][e-1][1]);
}

pair<long long, long long> Mx(long long x, long long y) {
	long long mx = -INF, mxx = -INF;
	if(Dep[x] < Dep[y]) swap(x, y);

	SR(e, E_ - 1, 0) if(P[x][e] && Dep[P[x][e]] >= Dep[y]) {
		long long u = F[x][e][0], v = F[x][e][1];

		if(u > mx) mxx = mx, mx = u;
		if(u > mxx && u != mx) mxx = u;
		else if(v > mxx) mxx = v;

		x = P[x][e];
	}

	if(x == y) return make_pair(mx, mxx);
	cout << "!!!" << "\n";

	SR(e, E_ - 1, 0) if(P[x][e] != P[y][e]) {

		long long T[4] = { F[x][e][0], F[y][e][0], F[x][e][1], F[y][e][1] };
		sort(T, T+4); 
		int idx = unique(T, T+4) - T;

		Ir(i, 0, idx) {
			mx = max(mx, T[i]);
			if(T[i] != mx) mxx = max(mxx, T[i]);
		}

		x = P[x][e]; y = P[y][e];
	}

	long long u = F[x][0][0], v = F[y][0][0];
	mx = max(mx, max(u, v));
	if(u != mx) mxx = max(mxx, u);
	if(v != mx) mxx = max(mxx, v);

	return make_pair(mx, mxx);
}












