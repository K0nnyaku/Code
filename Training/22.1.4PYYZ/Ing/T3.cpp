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

const int N_ = 50 + 7;
const int M_ = 50 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

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

Edge<long long, N_*M_> I;
long long Far[N_*M_];
long long ans;
int og, sk, n, m;
bool Vv[N_*M_];

bool Spfa() {
	FL(Vv, 0); FL(Far, 0x3f);
	Far[og] = 0;
	queue<int> Q; Q.push(og);

	memcpy(I.H, I.I, sizeof I.I);

	while(Q.size()) {
		int x = Q.front(); Q.pop();
		Vv[x] = 0;

		ER(i,v,I,x,I) if(I.C[i] && Far[v] > Far[x]+I.W[i]) {
			Far[v] = Far[x] + I.W[i];
			if(!Vv[v] && (Vv[v] = 1)) Q.push(v);
		}
	}
	return Far[sk] != INF;
}

long long Dic(long long fl, int x) {
	if(x == sk) return fl;
	long long res = fl;

	Vv[x] = 1;
	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[v] == Far[x]+I.W[i]) {
			long long k = Dic(min(res, I.C[i]), v);
		
			I.C[i] -= k; I.C[i^1] += k;
			ans += k * I.W[i];
			I.H[x] = i;  res -= k;

			if(!res) { Vv[x] = 0; return fl; }
			if(!k)     Far[v] = 0;
		}
	Vv[x] = 0;
	return fl - res;
}

priority_queue<int> X[39], Y[39];

int n, m;
bool Vx[30], Vy[30];

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IR(v, 1, m) {
		int x; IN >> x;
		X[i].push(x);
		Y[v].push(x);
	}



	return 0;
} /**/






















