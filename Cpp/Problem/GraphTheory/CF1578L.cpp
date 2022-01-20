//---------------------Tem For Cpp-------------------------//
#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;

//Edge
struct Edge {
	int next, to, val;
	Edge(int _next = 0, int _to = 0, int _val = 0) {
		next = _next; to = _to; val = _val;
	}
}E[MAXN<<1];
int Head[MAXN];
int cnt;

void Add(int from, int to, int w) {
	E[++cnt] = Edge(Head[from], to, w);
	Head[from] = cnt;
}

//Tree
struct EdgeForTree{
	int u, v, w;
	EdgeForTree(int _u = 0, int _v = 0, int _w = 0) {
		u = _u; v = _v; w = _w;
	}
	friend bool operator<(const EdgeForTree &x, const EdgeForTree &y) {
		return x.w > y.w;
	}
} TE[MAXN];

//UnionAndFind
int Fa[MAXN];
void Init();
int FindFa(int x);
void Union(int x, int y);

//Main
int W[MAXN], Efa[MAXN];
int n, m, ans = INF;
void Pre(int x, int w, int last); 
void Solve(int x, int w); 

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif

	IN >> n >> m;
	IOR(i, 1, n+1) 
		IN >> W[i];

	IOR(i, 0, m) 
		IN >> TE[i].u >> TE[i].v >> TE[i].w;
	sort(TE, TE + m);

	Init();
	IOR(i, 0, m) {
		int u = TE[i].u, v = TE[i].v, w = TE[i].w;
		int xFa = FindFa(u), yFa = FindFa(v);
		if(xFa ^ yFa) {
			Union(xFa, yFa);
			Add(u, v, w);
			Add(v, u, w);
		}
	}

	Pre(1, 0, 0);

	Solve(1, 0);

//	IOR(i, 1, n+1) 
//		printf("i = %d, W = %d\n", i, W[i]);

	cout << ( ans > 0 ? ans : -1);

	return 0;
} /**/

int FindFa(int x) {
	return Fa[x] == x ? x : Fa[x] = FindFa(Fa[x]);
}

void Union(int x, int y) {
	int xFa = FindFa(x), yFa = FindFa(y);
	Fa[xFa] = yFa;
}

void Init() {
	IOR(i, 0, MAXN) Fa[i] = i;
}

void Pre(int x, int w, int last) {
	W[x] += w;
	
	EOR(i, x) {
		if(T(i) == last) continue;
		Pre(T(i), W[x], x);
	}
}

void Solve(int x, int last) {
	EOR(i, x) {
		if(T(i) == last) continue;
		ans = min(ans, V(i) - W[x]);
		Solve(T(i), x);
	}
}
















