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

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T C[M];
	Edge()    { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void Cl() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c; 
		Nt[++cnt] = I[v]; To[cnt] = u; C[I[v]=cnt] = 0; 
	}
};

Edge<int, N_*M_<<1, N_*M_<<2> I;
int Far[N_*M_];
int og, sk, n, m;
bool Vv[N_*M_<<1];

bool Pre(int og, int sk) {
	FL(Far, 0); Far[og] = 1;
	queue<int> Q; Q.push(og);

	memcpy(I.H, I.I, sizeof I.I);

	while(Q.size()) {
		int x = Q.front(); Q.pop();

		ER(i,v,I,x,I) if(I.C[i] && !Far[v]) 
			Far[v] = Far[x] + 1, Q.push(v);
	}

	return Far[sk];
}

long long Dic(long long fl, int x) {
	if(x == sk) return fl;

	long long res = fl;
	ER(i,v,I,x,H) 
		if(I.C[i] && Far[v] == Far[x]+1) {
			int k = Dic(min(res, I.C[i]), v);
		
			I.C[i] -= k; I.C[i^1] += k;
			I.H[x] = i;  res -= k;

			if(!res) return fl;
			if(!k)   Far[v] = 0;
		}
	return fl - res;
}

struct Tower {
	int x, y, z, pos;
	Tower(int x_ = 0, int y_ = 0, int w_＝ 0, int pos_ = 0) {
		x = x_; y = y_; w = w_; pos = pos_;
	}
};

Tower T[N_*M_];
int Pm[N_*M_], Mp[N_][M_];
int n, m, act, tct;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IR(v, 1, m) {
		IN >> Mp[i][v], Pt[i][v] = ++act;
		if(Mp[i][v] < 0) T[++tct] = Tower(i, v, Mp[i][v], ++act);
	}




} /**/










