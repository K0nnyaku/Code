#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
}IN;

const int N_ = 1e5 + 7;

struct Node {
	int v, c;
	Node(int v_ = 0, int c_ = 0) { v = v_; c = c_; }
};
vector<Node> I[N_];
void AdI(int u, int v, int c) { I[u].push_back(Node(v, c)); }

struct { int u, v, c; } E[N_];
int Ep[N_], n, m, k;
bool Vv[N_];

int Spfa() {
	queue<int> Q; Q.push(1);
	FL(Ep, 0xcf); Ep[1] = 0;

	while(Q.size()) {
		int x = Q.front(); Q.pop();
		Vv[x] = 0;
		for(auto e: I[x]) if(Ep[e.v] < Ep[x] + e.c) {
			Ep[e.v] = Ep[x] + e.c;
			if(!Vv[e.v] && (Vv[e.v] = 1)) Q.push(e.v);
		}
	}
	return Ep[n];
}

int Pos[N_], Ans[N_];
int mx, ans;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/shortest/shortest1.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/shortest/shortest1.out", "w", stdout);
#endif
	srand(time(0));

	IN >> n >> m >> k;

	Ir(i, 0, m) { IN >> E[i].u >> E[i].v >> E[i].c; }

	IR(i, 1, m) Pos[i] = i; 

	srand(time(0));
	IR(v, 0, k) IR(i, 1, 1) {
		random_shuffle(Pos+1, Pos+m+1);

		IR(i, 1, n) I[i].clear();

		IR(q, v+1, m) {
			int p = Pos[q]-1;
			AdI(E[p].u, E[p].v, E[p].c);
			AdI(E[p].v, E[p].u, E[p].c);
		}

		int ep = Spfa();
		if(ep >= 0 && ep > mx) {
			mx = ep; ans = v;
			IR(i, 1, v) Ans[i] = Pos[i];
		}
	}

	cout << ans << "\n";
//	IR(i, 1, ans) 
//		cout << Ans[i] << "\n";

	return 0;
} /**/

















