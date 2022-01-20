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

long long Phi(long long x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IOR(i, 2, 11) {
		printf("----------\n");
		IOR(v, 1, 4) 
			printf("%d ^ %d = %lld\n", i, v, Phi(pow(i, v))); 
		printf("\n--------\n");
	}

	return 0;
} /**/

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