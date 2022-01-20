#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int P = 998244353;
const int MAXN = 2e5 + 10;

long long Fac[MAXN], Ie[MAXN];
long long n, m;

void Pre();
long long Qp(long long x, long long e);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	Pre();
	IN >> n >> m;
	
	cout << Fac[m] * (Ie[n-1] * Ie[m-n+1] % P) % P 
		* (n-2) % P * Qp(2, n-3) % P;

	return 0;
} /**/

long long Qp(long long x, long long e) {
	if(e < 0) return 1;
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = res * x % P;
		x = x * x % P; e >>= 1;
	}
	return res % P;
}

void Pre() {
	Fac[0] = Ie[0] = 1;
	IOR(i, 1, MAXN) 
		Fac[i] = Fac[i-1] % P * i % P % P,
		Ie[i] = Qp(Fac[i], P-2);
}
 













