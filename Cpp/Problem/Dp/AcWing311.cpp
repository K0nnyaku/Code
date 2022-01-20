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

const int _L = 10 + 2;
const int _V = 90 + 2;

long long F[_L][_V][_V][_V];
int l, r;

void Pre();
long long 

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	Pre();
	cout << F[1][2][1][1] << "\n";

	return 0;
} /**/

void Pre() {
	F[0][0][0][0] = 1;
	IR(i, 1, _L-1) IR(v, 1, 9 * i) IR(k, 1, v) IR(l, 0, k-1) {
		long long tmp = 0;
		IR(p, 0, min(v, 9)) {
			long long t = (l - (p % k * Qp(10, i-1, k) % k) + k) % k;
			tmp += F[i-1][v-p][k][t];
		}
		F[i][v][k][l] = tmp;
	}
}
















