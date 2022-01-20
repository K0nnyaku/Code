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

const int _N = 2e3 + 10;
const int _V = 3e3 + 10;
const int INF = 0x3f3f3f3f;
#define double long double

int E[_V][_V], C[_N], D[_N];
int n, m, v, e;
double K[_N], ans = INF, tmp;

int Part(int x);
int Count(int x);
void Floyd();
void Wk(int pos, int x, double k);

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
	IR(i, 0, _V-1) E[i][i] = 0;
	E[0][C[1]] = E[0][D[1]] = 0;

	IR(i, 1, e) {
		int u, v, w; IN >> u >> v >> w;
		E[u][v] = E[v][u] = min(E[u][v], w);
	}

	Floyd();

	IR(i, 0, (1<<n)-1) {
		if(Count(i) <= m) {

			tmp = 0,
			Wk(1, i, 1),
//			cout << tmp << "\n",
			ans = min(ans, tmp);
		}
	}

	printf("%.2Lf", ans);

	return 0;
} /**/

void Floyd() {
	IR(k, 1, v) IR(i, 1, v) IR(j, 1, v) 
		E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
}

int Count(int x) {
	int res = 0;
	IR(i, 0, n-1) {
		res += ((x & (1 << i)) != 0);
	}
	return res;
}

int Part(int x) {
	int res = 0;
	int last = 0;
	IR(i, 1, n) 
		if(x & (1 << (i-1)) ) 
			res += E[last][D[i]],
			last = D[i];
		else
			res += E[last][C[i]],
			last = C[i];
	return res;
}

void Wk(int pos, int x, double k) {
	if(pos == v+1) {

		/*
		cout << "----------------------\n";
		IR(i, 0, n-1) 
			cout << ((x & (1 << i)) != 0) << " ";
		printf("Part = %d\n", Part(x));
		printf("k = %.2lf\n", k);
		cout << tmp << "\n";
		cout << "\n----------------------\n";
		*/

		tmp += Part(x) * k;

		return ;
	}

	if(x & (1 << pos-1))
		Wk(pos+1, x, k * K[pos]),
		Wk(pos+1, x ^ (1 << pos-1), k * (1 - K[pos]));
	else
		Wk(pos+1, x, k);
}











