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

const int _N = 20 + 10;
const int _L = 20 + 10;

long long Len[_N], F[_N];
long long n, idx;

long long Calc();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#else
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
#endif
	IN >> n; 
	char clo = getchar();
	while(clo != 'Q') {
		int x; IN >> x;
		Len[++idx] = x + 1;
		clo = getchar();
	}

	IR(i, Len[1], n) F[i] = 1; 
	long long ans = 0;
	IR(i, 2, idx) SR(v, n, 0) {
		if(v - Len[i] >= 0) 
			F[v] += F[v - Len[i]],
			cout << F[v] << "\n";
	}

	IR(i, 0, n) 
		ans += F[i];

	cout << ans << '\n';

	return 0;
} /**/








