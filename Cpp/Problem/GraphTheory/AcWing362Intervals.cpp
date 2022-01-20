#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 5e5 + 10;
const int M_ = 25e5 + 10;
template<typename T, int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; int cnt;
	T Val[M << 1];

	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); FL(Val, 0); cnt = 1; }
	void Add(int u, int v, T w) { Nt[++cnt] = Hd[u]; To[cnt] = v; Val[Hd[u] = cnt] = w; }
};

Edge<int, N_, M_> G;
int Far[N_];
int n, m, mx;
bool Vv[N_];

void Spfa();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) {
		int u, v, w; IN >> u >> v >> w;
		G.Add(u, ++v, w);
		mx = max(mx, max(v+1, u+1));
	}

	IR(i, 0, mx) G.Add(i, i+1, 0);
	IR(i, 1, mx) G.Add(i, i-1, -1);

	Spfa();

	cout << Far[mx] << "\n";

	return 0;
} /**/

void Spfa() {
	queue<int> Q; Q.push(0);
	FL(Far, 0xcf); Far[0] = 0;
	while(Q.size()) {
		int tp = Q.front(); Q.pop();
		Vv[tp] = 0;

		ER(i, v, G, tp) 
			if(Far[tp] + G.Val[i] > Far[v]) {
				Far[v] = Far[tp] + G.Val[i];
				if(!Vv[v]) Q.push(v), Vv[v] = 1;
			}
	}
}

















