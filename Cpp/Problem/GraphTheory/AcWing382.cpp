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

const int N_ = 50 + 2;
const int INF = 0x3f3f3f3f;
const int K_ = 10 + 2;

template<typename T, int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], I[N], Hd[N]; int cnt;
	T W[M << 1], C[M << 1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(W, 0); FL(C, 0); FL(I, 0); FL(Hd, 0); cnt = 1; }
	void AdI(int u, int v, int c, int w) { 
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u] = cnt] = w; 
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v] = cnt] = -w;
	}
};

Edge<int, N_*N_<<1, N_*N_<<2> G;
int P[N_*N_<<1], Wy[2][2] { 1,0, 0,1, }, Far[N_*N_<<1];
int n, k, bc, ans, t, s;
bool Vq[N_*N_<<1], Vv[N_*N_<<1];

bool Spfa();
int H(int x, int y);
int Dic(int x, int fl);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
//	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> k; 
	bc = n * n; s = 1;
	IR(i, 1, n) IR(v, 1, n) {
		int x; IN >> x;
		G.AdI(H(i, v), H(i, v)+bc, 1, x);
		G.AdI(H(i, v), H(i, v)+bc, k-1, 0);
	}

	IR(i, 1, n) IR(v, 1, n) Ir(p, 0, 2) {
		int xt = i + Wy[p][0], yt = v + Wy[p][1];
		if(xt < 1 || xt > n || yt < 1 || yt > n) continue;
		G.AdI(H(i, v)+bc, H(xt, yt), k, 0);
	}
	s = 1;
	t = H(n, n) + bc;

	while(Spfa())
		FL(Vv, 0), Dic(1, k);

	cout << ans << "\n";

	return 0;
} /**/

int H(int x, int y) { return (x - 1) * n + y; }

bool Spfa() {
	queue<int> Q;  Q.push(s); 

	FL(Far, 0xc0); Far[s] = 0;
	FL(Vq, 0);     Vq[s] = 1;
	G.Hd[s] = G.I[s];

	while(!Q.empty()) {
		int tp = Q.front(); Q.pop();
		Vq[tp] = 0;

		ER(i, v, G, tp, I) 
			if(Far[v] < Far[tp] + G.W[i] && G.C[i]) {
				Far[v] = Far[tp] + G.W[i]; 
				G.Hd[v] = G.I[v];
				if(!Vq[v]) Q.push(v), Vq[v] = 1;
			}
	}

	return Far[t] != (-INF-1);
}

int Dic(int x, int fl) {
	if(x == t) return fl;
	int res = fl; Vv[x] = 1;
	for(int &i = G.Hd[x], v = G.To[i]; i; i = G.Nt[i], v = G.To[i]) {
		if(Far[v] == Far[x] + G.W[i] && G.C[i] && !Vv[v]) {

			int k = Dic(v, min(fl, G.C[i]));
			G.C[i] -= k, G.C[i^1] += k; res -= k;
			ans += k * G.W[i];

			if(!res) return fl;
			if(!k) Far[v] = 0;
		}
	}
	Vv[x] = 0;
	return fl - res;
}










