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

const int _N = 1e2 + 2;
const int INF = 0x3f3f3f3f;

long long F[_N][_N], V[_N][_N], Way[_N][_N];
int n, m;

void Output(int kind, int pos);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> m >> n;
	IR(i, 1, m) IR(v, 1, n) IN >> V[i][v];

	memset(F, 0xcf, sizeof F);
	memset(F[0], 0, sizeof F[0]);
	long long mx = -INF;
	IR(i, 1, n) IR(v, i, n-m+i) {
		mx = -INF;
		IR(k, i-1, v-1) if(F[i-1][k] > mx) 
			mx = F[i-1][k], Way[i][v] = k;
		F[i][v] = mx + V[i][v];
	}

	long long ans = -INF, t;
	IR(i, 1, n) if(F[m][i] > ans) 
		ans = F[m][i], t = i;
	cout << ans << "\n";

	Output(m, t);

	return 0;
} /**/

void Output(int kind, int pos) {
	if(kind > 1) Output(kind-1, Way[kind][pos]);
	cout << pos << " ";
}









