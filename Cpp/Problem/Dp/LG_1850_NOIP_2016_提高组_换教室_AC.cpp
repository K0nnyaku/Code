#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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
} IN;

const int _V = 3e2 + 2;
const int _N = 2e3 + 2;
const int _M = 2e3 + 2;
const int INF = 0x7f7f7f7f;

int C[_N], D[_N], E[_N][_N]; 
int n, m, v, e;
double K[_N], F[_N][_M][2];

void Floyd();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> n >> m >> v >> e;
	IR(i, 1, n) IN >> C[i];
	IR(i, 1, n) IN >> D[i];
	IR(i, 1, n) cin >> K[i];

	memset(E, 0x3f, sizeof E);
	IR(i, 0, _V) E[i][i] = E[0][i] = 0;
	IR(i, 1, e) {
		int u, v, w; IN >> u >> v >> w;
		E[u][v] = E[v][u] = min(E[u][v], w);
	}

	Floyd();

//	memset(F, 0xcf, sizeof F);
//	cout << F[1][0][0] << "\n";
//	memset(F, 0x3f, sizeof F);
//	cout << F[1][0][0] << "\n";

	IR(i, 0, _N-1) IR(v, 0, _M-1) IR(k, 0, 1)
		F[i][v][k] = INF;

	F[1][0][0] = 0;
	F[1][1][1] = 0;
	IR(i, 2, n) IR(v, 0, min(i, m)) {
		F[i][v][0] = min(F[i-1][v][0] + E[C[i-1]][C[i]], 
						 F[i-1][v][1] + E[D[i-1]][C[i]] * K[i-1] + E[C[i-1]][C[i]] * (1 - K[i-1]));
		if(v) 
			/*
			F[i][v][1] = F[i][v-1][0] * (1 - K[i]) + 
						 min( F[i-1][v-1][0] + E[C[i-1]][D[i]], 

							  F[i-1][v-1][1] + E[D[i-1]][D[i]] * K[i-1] 
											 + E[C[i-1]][D[i]] * (1-K[i-1])	) * K[i];
											 */
			F[i][v][1] = min( 
						(F[i-1][v-1][0] + E[C[i-1]][D[i]]) * K[i] + (F[i-1][v-1][0] + E[C[i-1]][C[i]]) * (1-K[i]),

						(F[i-1][v-1][1] + E[C[i-1]][D[i]]) * K[i] * (1-K[i-1]) + 
						(F[i-1][v-1][1] + E[C[i-1]][C[i]]) * (1-K[i]) * (1-K[i-1]) + 

						(F[i-1][v-1][1] + E[D[i-1]][D[i]]) * K[i] * K[i-1] +
						(F[i-1][v-1][1] + E[D[i-1]][C[i]]) * K[i-1] * (1-K[i])   );
	}
//
//	IR(i, 1, n) IR(v, 0, m) IR(k, 0, 1)
//		printf("F[%d][%d][%d] = %lf\n", i, v, k, F[i][v][k]);

	double ans = INF;
	IR(i, 0, m) 
		ans = min(ans, 
				  min(F[n][i][0], F[n][i][1]) );
	
	printf("%.2lf\n", ans);

	return 0;
} /**/

void Floyd() {
	IR(k, 1, v) IR(i, 1, v) IR(v_, 1, v) 
		E[i][v_] = min(E[i][v_], E[i][k] + E[k][v_]);
}














