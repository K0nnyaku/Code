#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define FLS(x, y, z) memset(x, y, (z+3) * sizeof (int))

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

const int N_ = 40 + 7;
const int M_ = 1e2 + 7;
const int P_ = 8e2 + 7;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T W[M], C[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u]=cnt] =  w;
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v]=cnt] = -w;
	}
};

Edge<int, N_+N_*P_*M_, N_*P_*M_<<1> I;
int Far[N_+N_*P_*M_];
int ans;
int og, sk;
bool Vv[N_+N_*P_*M_];

int P[N_], Tm[M_][N_], Ps[M_][P_];
int n, m, p;

bool Spfa() {
	FLS(Vv, 0, n+n*p*m); FLS(Far, 0x3f, n+n*p*m);
	Far[og] = 0;
	deque<int> Q; Q.push_front(og);

	memcpy(I.H, I.I, (n+n*p*m+3)*sizeof(int));

	while(Q.size()) {
		int x = Q.front(); Q.pop_front();
		Vv[x] = 0;

		ER(i,v,I,x,I) if(I.C[i] && Far[v] > Far[x]+I.W[i]) {
			Far[v] = Far[x] + I.W[i];
			if(!Vv[v] && (Vv[v] = 1)) 
				if(Q.size() && Far[Q.front()] > Far[v]) Q.push_front(v);
				else									Q.push_back (v);
		}
	}
	return Far[sk] != INF;
}

int Dic(int fl, int x) {
	if(x == sk) return fl;
	int res = fl;
	Vv[x] = 1;

	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[v] == Far[x]+I.W[i]) {
			int k = Dic(min(res, I.C[i]), v);
		
			I.C[i] -= k; I.C[i^1] += k;
			ans += k * I.W[i];
			I.H[x] = i;  res -= k;

			if(!res) { Vv[x] = 0; return fl; }
			if(!k)     Far[v] = 0;
		}
	Vv[x] = 0;
	return fl - res;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	IR(i, 1, n) IN >> P[i], p += P[i];
	IR(i, 1, n) IR(v, 1, m) IN >> Tm[v][i];
	
	int cnt = n;	
	IR(i, 1, m) IR(v, 1, p) Ps[i][v] = ++cnt;

	og = 0, sk = n + m*p + 1;

	IR(i, 1, n) I.AdI(og, i, P[i], 0);
	IR(i, 1, n) IR(v, 1, m) IR(k, 1, p) I.AdI(i, Ps[v][k], 1, k * Tm[v][i]);
	IR(i, 1, m) IR(v, 1, p) I.AdI(Ps[i][v], sk, 1, 0);

	while(Spfa())
		Dic(INF, og);

	cout << ans << "\n";

	return 0;
} /**/










