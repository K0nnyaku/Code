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

const int MAXN = 4e4 + 10;
const int MAXM = 4 + 10;

long long Fac[MAXN], Ie[MAXN], D[MAXN];
long long A[MAXM], N[MAXM], L[MAXM] = {2, 3, 4679, 35617};
long long g, n, cnt;

long long Qp(long long x, long long e, long long p);
long long Lucas(long long n, long long m, long long p);
long long Crt(int k, long long* A, long long *N);
long long C(long long n, long long m, long long p);
void Pre(long long p);
void Exgcd(long long a, long long b, long long &x, long long &y);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
//	freopen("I:\\Code\\Out.out", "w", stdout);
#endif


//	Pre(2);
//	cout << C(4, 4 ,2);
//	return 0;

	IN >> n >> g;
	if(g % 999911659 == 0) {
		cout << "0" << "\n";
		return 0;
	}

	int lm = sqrt(n);
	IOR(i, 1, lm+1) if(n % i == 0) 
		D[cnt++] = i, D[cnt++] = n / i;

	if(D[cnt-1] == D[cnt-2]) cnt--;

	IOR(i, 0, 4) {
		Pre(L[i]); N[i] = L[i];
		IOR(v, 0, cnt) {
			A[i] = (A[i] % L[i] + Lucas(n, D[v], L[i]) ) % L[i];
		}
	}


	long long x = Crt(4, A, N);
	cout << x << "\n";

	cout << Qp(g, x, 999911659) << "\n";

	return 0;
} /**/

void Pre(long long p) {
	Fac[0] = Ie[0] = 1;	
	IOR(i, 1, p+1) 
		Fac[i] = Fac[i-1] * i % p;
}
 
long long Qp(long long x, long long e, long long p) {
	long long res = 1;
	x %= p;
	while(e) {
		if(e & 1) res = res * x % p;
		x = x * x % p; e >>= 1;
	}
	return res % p;
}

long long Lucas(long long n, long long m, long long p) {
	if(!m) return 1;
	return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

long long Crt(int k, long long* A, long long *N) {
	long long pn = 1, res = 0;
	IOR(i, 0, k) pn *= N[i];	
	IOR(i, 0, k) {
		long long im, x, m = pn / N[i];
		Exgcd(m, N[i], im, x);
		im = (im + N[i]) % N[i];
		im = im * pn / N[i];
		res = (res % pn + A[i] * im % pn) % pn;	
	}
	return res;
}

void Exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {x = 1, y = 0; return ;}
	Exgcd(b, a % b, y, x);
	y -= x * (a / b);
}

long long C(long long n, long long m, long long p) {
	if(n < m) return 0;
	return Fac[n] * ( Qp(Fac[m], p-2, p) * Qp(Fac[n-m], p-2, p) % p) % p;
}






