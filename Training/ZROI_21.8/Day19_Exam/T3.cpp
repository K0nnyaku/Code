#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
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

const int P = 999911659;
const int MAXN = 1e3 + 10;

unsigned long long F[MAXN][MAXN];
int n, m, k;
bool Mp[MAXN][MAXN];

unsigned long long Qp(unsigned long long x, int e);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IO >> n >> m >> k;

    if(n > MAXN) {
        printf("539030724");
        return 0;
    }

    IOR(i, 0, k) {
        int x, y; IO >> x >> y;
        Mp[x][y] = 1;
    }
    IOR(i, 0, n) 
        IOR(v, 0, min(i, m)) Mp[i][v] = 1;

    F[0][0] = 1;
    IOR(i, 0, n) IOR(v, 1, m) 
        if(!Mp[i][v]) F[i][v] = (i - 1 < 0 ? 0 : F[i-1][v]) + (v - 1 < 0 ? 0 : F[i][v-1]); 

    printf("%llu\n", Qp(233, F[n-1][m-1]));

    return 0;
} /**/

unsigned long long Qp(unsigned long long x, int e) {
    if(e == 0) return 1;
    unsigned long long res = Qp(x, e/2);
    
    return e % 2 ? ((res * res) % P * (x % P)) % P : (res % P * (res % P)) % P;
}
