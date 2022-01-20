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

const int _N = 1e5 + 10;
const int P = 5000011;

#define S(x, y) (((x % P) + (y % P)) % P)

int F[_N][2];
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
#endif
	IN >> n >> m;

	F[1][1] = F[1][0] = 1;
	IR(i, 2, n) 
		F[i][0] = S(F[i-1][0], F[i-1][1]),
		F[i][1] = (i - m - 1 >= 1 ? S(F[i-m-1][0], F[i-m-1][1]) : 1);
	
	cout << F[n][0] + F[n][1] << "\n";

	return 0;
} /**/












