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

const int N_ = 1e5 + 2;
const int E_ = 1e5 + 2;
const int M_ = 50 + 2;
const int K_ = 40 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N];
	int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
};

Edge<N_, E_> G;
int Qs[M_], P[N_][K_], F[N_][K_], Sum[K_], Q[K_];
int n, m, mx, tmp;
bool Ve[60][60], Vv[60];

void Pre(int x, int last);
void Wk(int x, int last);
int Force(int x);
void Dfs(int x, int step);

int main() { /**/
#ifndef LOCAL
	freopen("dis.in", "r", stdin);
	freopen("dis.out", "w", stdout); 
#endif
	IN >> n >> m;
	
	IR(i, 1, n/2) {
		G.Add(i, i*2); G.Add(i*2, i);
		if(n % 2 || i < n / 2)
			G.Add(i, i*2+1), G.Add(i*2+1, i);
	}
	
	if(n <= 50) {
		IR(i, 1, m) {
			char opt; int k;
			opt = getchar(); IN >> k;
		
			if(opt == '-') Ve[k][k/2] = Ve[k/2][k] = 1;
			else cout << Force(k) << "\n";
		}
		return 0;
	}
	
	
	IR(i, 1, m) IN >> Qs[i], mx = max(mx, Qs[i]);
		
	IR(i, 1, n) P[i][0] = 1;
	
	Pre(1, 0);
	IR(i, 0, mx) F[1][i] = P[1][i];
	IR(i, 1, n) F[i][0] = 1;
	Wk(1, 0);
	
	IR(i, 1, mx) 
		Q[i] = Sum[i] + Q[i-1];
	
	IR(i, 1, m) 
		cout << Q[Qs[i]] / 2 << "\n";

	return 0;
} /**/

void Pre(int x, int last) {
	ER(i, v, G, x) if(v != last) {
		Pre(v, x);
		IR(k, 1, mx) P[x][k] += P[v][k-1];	
	}
	
//	IR(i, 0, mx) 
		//printf("P[%d][%d] = %d\n", x, i, P[x][i]);
}

void Wk(int x, int last) { 
	ER(i, v, G, x) if(v != last) {
		IR(k, 1, mx) 
			F[v][k] = F[x][k-1] + P[v][k] - (k > 1 ? P[v][k-2] : 0);
			//printf("F[%d][%d] = %d\n", v, k, F[v][k]);
		Wk(v, x);
	}
	IR(i, 0, mx) Sum[i] += F[x][i];
}

int Force(int x) {
	int res = 0;
	IR(i, 1, x) IR(v, 1, n) {
		FL(Vv, 0); Vv[v] = 1;
		tmp = 0;
		Dfs(v, i);
		res += tmp;
	}
	return res / 2;
}

void Dfs(int x, int step) {
	if(step == 0) {
		tmp++; return ; }
		
	ER(i, v, G, x) if(!Vv[v] && !Ve[x][v])
		Vv[v] = 1, Dfs(v, step-1);
}

/*
5 5
? 2
- 2
? 2
- 5
? 2
*/

/*
7 5
? 1
? 2
? 3
? 4
? 5
? 6
*/

/*
3 1
? 1
*/
















