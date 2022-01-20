#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;
//

const int MAXN = 1e7 + 10;
const int P = 1e9 + 7;

long long Sphi[MAXN];
long long ans;
int n, p;

long long Qp(long long x, long long e);
long long Phi(long long x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("WA.out", "w", stdout);
#endif
	IN >> n >> p;

    IOR(i, 1, n+1) IOR(v, 1, p+1) {
        ans = (Phi(Qp(i, v)) % P + ans % P) % P;
    }
    printf("%lld\n", ans);

	return 0;
} /**/

long long Qp(long long x, long long e) {
	if(!e) return 1;
	long long res = Qp(x, e/2) % P;
	return e % 2 ? (res * res % P * (x % P)) % P : res * res % P;
}

long long Phi(long long x) {
    long long res = x;
    IOR(i, 2, sqrt(x)+1) 
        if(!(x % i)) {
            res = res / i * (i - 1);
            while(!(x % i)) x /= i;
        }
    if(x > 1) res = res / x * (x - 1);

    return res;
}