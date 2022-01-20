#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MAXN = 3000 + 10;

double sm;
long long ans;
int A[MAXN];
int n;

long long Qy(long long x);
long long Abs(long long x);
long long Power(long long x);
bool Check(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IO >> n;
    IOR(i, 0, n) IO >> A[i], sm = (double)A[i]+sm;
    sm = (double)sm/n;

    ans = Qy(floor(sm));
    ans = min(ans, Qy(ceil(sm)));

    printf("%lld", ans);

	return 0;
} /**/

long long Qy(long long x) {
    long long res = 0;
    IOR(i, 0, n) 
        res += Power(A[i] - x);
    return res;
}

long long Power(long long x) {
    return x * x;
}