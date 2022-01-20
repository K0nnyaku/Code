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

const int N_ = 1e3 + 10;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N_], Nt[M], To[M], H[N]; int cnt;
	T C[M];
	Edge()    { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(H, 0); FL(C, 0); cnt = 1; }
	void Cl() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(H, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c;
		Nt[++cnt] = I[v]; To[cnt] = u; C[I[v]=cnt] = 0; 
	}
};

Edge<long long, N_, N_*N_<<1> I;
long long A[N_][N_], Pos[N_][N_], Far[N_*N_];
int n, m, og, sk, cnt, sum;
bool Fg[N_][N_];

bool Pre();
long long Dic(long long fl, int x); 

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> m >> n;
	IR(i, 1, m) IR(v, 1, n) IN >> A[i][v], Pos[i][v] = ++cnt, sum += A[i][v];
	IR(i, 1, m) IR(v, 1, n) Fg[i][v] = (i % 2) ^ (v % 2);

	og = 0; sk = cnt + 1;
	IR(i, 1, m) IR(v, 1, n) if(Fg[i][v]) {
		if(i > 1) I.AdI(Pos[i][v], Pos[i-1][v], INF);
		if(i < m) I.AdI(Pos[i][v], Pos[i+1][v], INF);
		if(v > 1) I.AdI(Pos[i][v], Pos[i][v-1], INF); 
		if(v < n) I.AdI(Pos[i][v], Pos[i][v+1], INF); 
	}
	IR(i, 1, m) IR(v, 1, n) 
		if(Fg[i][v]) I.AdI(og, Pos[i][v], A[i][v]);
		else		 I.AdI(Pos[i][v], sk, A[i][v]);

	long long ans = 0;
	while(Pre())
		ans += Dic(INF, og);

	cout << sum - ans << "\n";

	return 0;
} /**/

bool Pre() {
	queue<int> Q; Q.push(og);
	FL(Far, 0);   Far[og] = 1;
	memcpy(I.H, I.I, sizeof I.I);

	while(Q.size()) {
		int tp = Q.front(); Q.pop();
		ER(i,v,I,tp,I) if(!Far[v] && I.C[i]) {
			Far[v] = Far[tp]+1; 
			Q.push(v);
			if(v == sk) return true;
		}
	}
	return false;
}

long long Dic(long long fl, int x) {
	if(x == sk) return fl;

	long long res = fl;
	ER(i,v,I,x,H) if(Far[v] == Far[x] + 1 && I.C[i]) {
		long long k = Dic(min(I.C[i], res), v);

		I.C[i] -= k; I.C[i^1] += k;
		res -= k;    I.H[x] = i;

		if(!res) return fl;
		if(!k) Far[v] = 0;
	}
	return fl - res;
}



















