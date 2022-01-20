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

const int N_ = 1e2 + 10;

long long E[N_][N_], Cnt[N_][N_];
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;	

	FL(E, 0x3f);
	IR(i, 1, m) {
		int u, v, w; IN >> u >> v >> w;
		E[u][v] = E[v][u] = w;
		Cnt[u][v] = Cnt[v][u] = 1;
	}
	IR(i, 1, n) E[i][i] = 0;

	IR(k, 1, n) IR(i, 1, n) IR(v, 1, n) {
		if(k == i || k == v || i == v) continue;

		long long tmp = E[i][k] + E[k][v];
		if(tmp < E[i][v])		 E[i][v] = tmp, Cnt[i][v] = (Cnt[i][k] * Cnt[k][v]);
		else if(tmp == E[i][v])				    Cnt[i][v] += (Cnt[i][k] * Cnt[k][v]);
	}

//	IR(i, 1, n) IR(v, 1, n)
//		if(Cnt[i][v]) printf("Cnt[%d][%d] = %lld\n", i, v, Cnt[i][v]);
	
	IR(k, 1, n) {
		double ans = 0;
		IR(i, 1, n) IR(v, 1, n) {
			if(k == i || k == v || i == v) continue;
			ans += (double)(E[i][k] + E[k][v] == E[i][v]) * Cnt[i][k] * Cnt[k][v] / Cnt[i][v];
		}
		printf("%.3lf\n", ans);
	}

	return 0;
} /**/












