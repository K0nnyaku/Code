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

const int P = 1e4 + 7;
const int _K = 1e6 + 10;

long long Fac[_K], Ie[_K];
long long a, b, k, n, m;

void Pre();
long long C(long long x, long long y);
long long Qp(long long x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> a >> b >> k >> n >> m;
	Pre();
	cout << C(k, n) % P * Qp(a, n) % P * Qp(b, k-n) % P << "\n";

	return 0;
} /**/

void Pre() {
	Fac[0] = Ie[0] = 1;
	IR(i, 1, _K-1)
		Fac[i] = Fac[i-1] * i % P,
		Ie[i] = Qp(Fac[i], P-2);
}

long long C(long long x, long long y) {
	if(y > x) return 0;
	if(!y || !x) return 1;
	return Fac[x] * Ie[y] % P * (Ie[x-y] % P) % P;
}

long long Qp(long long x, int e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = res * x % P % P;
		x = x * x % P; e >>= 1;
	}
	return res;
}





