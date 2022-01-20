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

const int N_ = 1e3 + 2;
const int M_ = 20 + 2;
const int INF = 0x3f3f3f3f;

int F[N_][M_], C[M_];
int n, m, fg;
bool Vs[N_][M_];

void Dij();
int Abs(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
//	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) IN >> C[i], fg = !C[i] ? i : fg; 

	Dij();

	int ans = INF;
	IR(i, 1, m) ans = min(ans, F[n][i]);

	cout << (ans != INF ? ans : -1) << "\n";

	return 0;
} /**/

struct Node {
	int x, y, v;
	Node(int x_ = 0, int y_ = 0, int v_ = 0) { x = x_; y = y_; v = v_; }
	friend bool operator<(const Node &x, const Node &y) { return x.v > y.v; }
};

void Dij() {
	FL(F, 0x3f); FL(Vs, 0);
	priority_queue<Node> Q; Q.push(Node(1, fg, 0));
	F[1][fg] = 0;

	while(Q.size()) {
		int x, y, v;
		do {
			x = Q.top().x, y = Q.top().y, v = Q.top().v,
			Q.pop();
		}
		while(Vs[x][y] && Q.size());
		
		Vs[x][y] = 1;

		IR(i, 1, m) {
			int to = x + C[i];
			if(to < 1 || to > n || !C[i] || i == y) continue;

			if( F[to][i] > F[x][y] + Abs(i - y) + Abs(2 * C[i]) ) 
				F[to][i] = F[x][y] + Abs(i - y) + Abs(2 * C[i]),
				Q.push(Node(to, i, F[to][i]));
		}

		int k = x, s = 0;
		while(k > 0 && k <= n && C[y]) {
			k = k + C[y]; s += Abs(2 * C[y]);
			if(k > 0 && k <= n && F[k][y] > F[x][y] + s)   
				F[k][y] = F[x][y] + s,
				Q.push(Node(k, y, F[k][y]));
		}
	}
}

int Abs(int x) { return x < 0 ? -x : x; }















