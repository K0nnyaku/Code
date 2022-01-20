#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 5e5 + 2;

template<int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

template<int N>
struct Uaf {
	int Fa[N];
	Uaf() { Ir(i, 1, N) Fa[i] = i; }
	int Fd(int x) { return Fa[x] = x == Fa[x] ? x : Fd(Fa[x]); }
	void Un(int x, int y) { return Fa[Fd(x)] = Fd(y); }
};

struct Question {
	int x, y, z;
	Question(int x_ = 0, int y_ = 0, int z_ = 0) { x = x_; y = y_; z = z_; }
}Qs[N_];

struct Node {
	int x, y; 
	Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
	friend bool operator<(const Node &x, const Node &y) { return x.y < y.y; }
};

Uaf<N_> U; 
Edge<N_, N_> I;
vector<int> Q[N_], Id[N_];
int Lca[N_*3], Dep[N_];
int n, m, cnt;

void AdT(int x, int y) {
	Q[x].push_back(y); Q[y].push_back(x);
	Id[x].push_back(++cnt); Id[y].push_back(++cnt);
}
int Far(int x, int y) {
	return Dep[]<++>
}

void Tarjan(int x, int last, int dep) {
	ER(i,v,I,x,I) if(v != last) 
		Tarjan(v, x, dep+1);

	Dep[x] = dep;
	
	Ir(i, 0, Q[x].size())
		Lca[Id[x][i]] = U.Fd(Q[x][i]);

	U.Un(x, last ? last : x);
}


int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		I.Ad(u, v); I.Ad(v, u);
	}

	IR(i, 1, m) {
		IN >> Qs[i].x >> Qs[i].y >> Qs[i].z;
		AdT(x, y);	AdT(x, z);	AdT(y, z);	
	}

	Tarjan(1, 0, 0);

	IR(i, 1, m) {
		Node T[3] = { Node(Lca[i*3-2], Dep[Lca[i*3-2]]), Node(Lca[i*3-1], Dep[Lca[i*3-1]]), Node(Lca[i*3], Dep[Lca[i*3]]); }
		sort(T+1, T+4);
		cout << T[1].x << " " << Far(T[1].x, Qs[i].x) + Far(T[1].x, Qs[i].y) + Far(T[1].x, Qs[i].z) << "\n";
	}

	return 0;
} /**/












