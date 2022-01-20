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

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N_ = 50 + 7;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T W[M], C[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u]=cnt]=  w;
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v]=cnt]= -w;
	}
};

Edge<long long, (N_*N_)<<1, (N_*N_*N_)<<1> I;
long long Far[(N_*N_)<<1];
long long k, ans;
int Pos[N_][N_];
int n, m, og, sk, cnt;
bool Vv[(N_*N_)<<1];

bool Spfa();
long long Dic(long long fl, int x);
long long Abs(long long x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In(1).in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> k;

	IR(i, 1, n) IR(v, 1, m)
		Pos[i][v] = ++cnt;

	sk = cnt*2+2, og = sk + 1;

	IR(i, 1, m) 
		I.AdI(0, Pos[1][i], 1, 0);

	Ir(i, 1, n) IR(v, 1, m) {
		long long x; IN >> x;
		IR(p, 1, m) 
			I.AdI(Pos[i][v]+cnt, Pos[i+1][p], 1, x + k * Abs(p-v));
	}

	IR(i, 1, m) {
		long long x; IN >> x;
		I.AdI(Pos[n][i]+cnt, sk, 1, x);
	}

	IR(i, 1, n) IR(v, 1, m) 
		I.AdI(Pos[i][v], Pos[i][v]+cnt, 1, 0);

	I.AdI(og, 0, 2, 0);

	while(Spfa())
		memset(Vv, 0, (cnt*2+10)*sizeof(bool)), Dic(2, og);
//		FL(Vv, 0), Dic(INF, og);

	cout << ans << "\n";

	return 0;
} /**/

bool Spfa() {
//	memset(Vv, 0, (cnt*2+10)*sizeof(bool));
//	memset(Far, 0x3f, (cnt*2+10)*sizeof(long long));
//	memcpy(I.H, I.I, (cnt*2+10)*sizeof(int));
	FL(Vv, 0); FL(Far, 0x3f);
	memcpy(I.H, I.I, sizeof I.I);

	Far[og] = 0; 
	deque<int> Q; Q.push_back(og);

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

long long Dic(long long fl, int x) {
	if(x == sk) return fl;
	long long res = fl;

	Vv[x] = 1;
	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[x]+I.W[i] == Far[v]) {
			long long k = Dic(min(I.C[i], res), v);	

			I.C[i] -= k;     I.C[i^1] += k;
			ans += I.W[i] * k;
			I.H[x] = i;		 res -= k;

			if(!res) { Vv[x] = 0; return fl; }
			if(!k) Far[v] = 0;
		}
	Vv[x] = 0;
	return fl - res;
}

long long Abs(long long x) {
	return x < 0 ? -x : x;
}










