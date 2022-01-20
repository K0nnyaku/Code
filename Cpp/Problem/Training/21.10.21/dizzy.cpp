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

const int _N = 250 + 10;
const int _M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct Node {
	int mx, val, sum, pos;
	Node(int _mx = INF, int _val = INF, int _pos = 0) {
		mx = _mx; val = _val; sum = mx + val; pos = _pos;
	}
	friend bool operator<(Node x, Node y) {
		return x.sum > y.sum;
	}
}Ans[_N][_N];

struct Edge {
	int next, val, to;
	Edge(int _next = 0, int _val = 0, int _to = 0) {
		next = _next; val = _val; to = _to;
	}
}E[_M << 1];
int Head[_N];
int cnt;
void Add(int from, int to, int val) {
	E[++cnt] = Edge(Head[from], val, to);
	Head[from] = cnt;
}

int W[_N];
int n, m, k;
bool Vis[_N];

void Dijkstra(int s);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else
	freopen("dizzy.in", "r", stdin);
	freopen("dizzy.out", "w", stdout);
#endif
	cout << -1 << "\n";
	return 0;
} /**/

void Dijkstra(int s) {
	priority_queue<Node> Q;
	memset(Vis, 0, sizeof Vis);
	Q.push(Node(W[s], 0, s));

	while(!Q.empty()) {
		Node t = Q.top(); Q.pop();
		if(Vis[t.pos]) continue;
		Vis[t.pos] = 1;

		EOR(i, t.pos) {
			if(Vis[T(i)]) continue;
			int mx = max(t.mx, W[T(i)]);
			if(mx + t.val + V(i) <= Ans[s][T(i)].sum) {
				Ans[s][T(i)] = Node(mx, V(i)+t.val, T(i));
				Q.push(Ans[s][T(i)]);
			}
		}

	}

}











