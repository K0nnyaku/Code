#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
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

long long a, k;
bool Bk[20];

bool Check(long long x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    int maxn = 1e5 + 10;

    IN >> a >> k;
    if(a >= 30) maxn = 1e9 + 10;

    IOR(i, 0, k) {
        int x; IN >> x;
        Bk[x] = 1;
    }

    int i = 1; 
    for(int i = 1; i * a <= maxn; i++) 
        if(Check(a * i)) {
            printf("%lld\n", a * i);
            return 0;
        }
    printf("-1");

	return 0;
} /**/

bool Check(long long x) {
    if(x < 10) {
        if(Bk[x]) return false;
        return true;
    }

    while(x) {
        long long d = x % 10; 
        if(Bk[d]) return false;
        x /= 10;
    }
    return true;
}