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

const int MAXN = 5e3 + 10;

long long Qc[MAXN], Qt[MAXN], F[MAXN];
int n, s;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> n >> s;
    IOR(i, 1, n+1) {
        int x, y; IN >> x >> y;
        Qt[i] = Qt[i-1] + x;
        Qc[i] = Qc[i-1] + y;
    }

    memset(F, 0x3f, sizeof F);
    F[0] = 0;
    IOR(i, 1, n+1) IOR(v, 0, i) 
        F[i] = min( F[i], 
            F[v] + Qt[i] * (Qc[i] - Qc[v]) + s * (Qc[n] - Qc[v]) );
    
    printf("%lld", F[n]);

	return 0;
} /**/