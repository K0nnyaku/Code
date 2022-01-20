#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

const int _BUF = 1e2 + 10;
struct FastIO
{
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
	template<typename T>
	FastIO& operator<<(T& x)
	{
		static char Buf[_BUF];
		static int len = -1;
		if(x >= 0) 
			do 
				Buf[++len] = x % 10 + 48, x /= 10;
			while(x);
		else {
			putchar('-');
			do 
				Buf[++len] = -(x % 10) + 48, x /= 10;
			while(x);
		}
		while(len >= 0) 
			putchar(Buf[len--]);
		return *this;
	}
} IO;

const int _N = 50 + 2;
const int _V = 50 + 2;

__int128 F[_N], Fac[_N], Ie[_N];
int n;

void Pre();
__int128 C(int x, int y);
__int128 Qp(__int128 x, int e);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif

	F[1] = 1;
	Pre();
	cout << C(2, 2) << "\n";
	IR(i, 2, _N-1) {
		__int128 tmp = 0;
		IR(k, 1, i-1) 
			tmp += F[k] * C(i-1, k-1) * Qp(2, (i-k) * (i-k-1) / 2);
		F[i] = Qp(2, i * (i - 1) / 2) - tmp;
		IO << F[i];
		cout << "\n";
	}

	int x; IO >> x;
	while(x) {
		IO << F[x];
		cout << "\n";
		IO >> x;
	}

	return 0;
} /**/

void Pre() {
	Fac[0] = 1;
	IR(i, 1, _V) 
		Fac[i] = Fac[i-1] * i;
}

__int128 Qp(__int128 x, int e) {
	__int128 res = 1;
	while(e) {
		if(e & 1) res = res * x;
		x *= x; e >>= 1;
	}
	return res;
}

__int128 C(int x, int y) {
	return Fac[x] * Fac[y] * Fac[x-y];
}








