#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 1e2 + 7;
const int M_ = 1e2 + 7;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T C[M], W[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); FL(W, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u]=cnt] =  w;
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v]=cnt] = -w;
	}
};

Edge<int, N_+M_, N_*M_*2 + N_ + M_> I;
int Far[M_+N_], In[M_+N_], Out[M_+N_], X[N_], Y[M_];
int n, m, sk, og, ks, go, ans, k, cnt;
bool Vv[N_+M_], Mp[N_][M_];

bool Spfa(int og, int sk) {
	FL(Far, 0x3f); Far[og] = 0;
	queue<int> Q; Q.push(og);

	memcpy(I.H, I.I, sizeof I.I);
	
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		Vv[x] = 0;
		ER(i,v,I,x,I) if(I.C[i] && Far[v] > Far[x] + I.W[i]) {
			Far[v] = Far[x] + I.W[i];
			if(!Vv[v] && (Vv[v] = 1)) Q.push(v);
		}
	}

	return Far[sk] != INF;
}

int Dic(int fl, int x, int sk) {
	if(x == sk) return fl;
	int res = fl; 

	Vv[x] = 1;
	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[v] == Far[x] + I.W[i]) {
			int k = Dic(min(res, I.C[i]), v, sk);

			I.C[i] -= k;  I.C[i^1] += k;
			ans += k * I.W[i];
			I.H[x] = i;   res -= k;

			if(!res) { Vv[x] = 0; return fl; }
			if(!k) Far[v] = INF;
		}
	Vv[x] = 0;
	return fl - res;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> k;

	IR(i, 1, n) X[i] = ++cnt;
	IR(i, 1, m) Y[i] = ++cnt;

	og = 0,    sk = cnt+1;
	go = sk+1, ks = go+1;

	IR(i, 1, n) {	
		int x; IN >> x;
		ans += x; Out[og] += x; In[X[i]] += x;
		I.AdI(og, X[i], INF-x, 1);
	}

	IR(i, 1, m) {
		int x; IN >> x;
		Out[Y[i]] += x; In[sk] += x;
		I.AdI(Y[i], sk, INF-x, 0);
	}

	IR(i, 1, k) { int u, v; IN >> u >> v; Mp[u][v] = 1; }

	IR(i, 1, n) IR(v, 1, m) 
		if(!Mp[i][v]) I.AdI(X[i], Y[v], 1, 0);

	IR(i, 0, cnt+1) 
		if(In[i] > Out[i]) I.AdI(go, i, In[i]-Out[i], 0);
		else    
		if(Out[i] > In[i]) I.AdI(i, ks, Out[i]-In[i], 0);

	I.AdI(sk, og, INF, 0);

	while(Spfa(go, ks)) 
		Dic(INF, go, ks);

	ER(i,v,I,go,I) { if(I.C[i]) { cout << "No Solution\n"; return 0; } }

	cout << ans << "\n";

	return 0;
} /**/




