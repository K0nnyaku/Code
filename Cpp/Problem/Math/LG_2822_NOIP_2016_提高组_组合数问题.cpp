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
long long t, k;

long long Q[_N][_N], C[_N][_N];

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> t >> k;
	Pre();
	while(t--) {
		int n, m; IN >> n >> m;
		cout << Q[n][m] << "\n";
	}

	return 0;
} /**/

void Pre() {
	IR(i, 0, _N-1) C[i][0] = 1;

	IR(i, 1, _N-1) IR(v, 1, i)
		C[i][v] = (C[i-1][v] % k + C[i-1][v-1] % k) % k;

	IR(i, 1, _N-1) IR(v, 1, i)
		Q[i][v] = C[i][v] == 0;

	IR(i, 1, _N-1) IR(v, 1, _N-1)
		Q[i][v] = Q[i-1][v] + Q[i][v-1] + Q[i][v] - Q[i-1][v-1];
//		printf("Q[%d][%d] = %d\n", i, v, Q[i][v]);

}






