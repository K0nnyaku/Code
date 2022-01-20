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

const int MAXN = 5e6 + 10;

int Mu[MAXN];
int t, a, b, d;

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    Pre();
    IN >> t;
    while(t--) {
        IN >> a >> b >> d;
        long long ans = 0;
        if(a > b) swap(a, b);
        for(int l = 1, r = 0; l <= a; l = r + 1) {
            r = min(a / (a / l), b / (b / l));
            ans += (long long)(Mu[r] - Mu[l-1]) * (a /(l * d)) * (b / (l * d));
        }
        printf("%lld\n", ans);
    }

	return 0;
} /**/

int Prime[MAXN];
int idx;
bool Vis[MAXN];

void Pre() {
    Mu[1] = 1;
    
    IOR(i, 2, MAXN) {
        if(!Vis[i]) 
            Mu[i] = -1, Prime[idx++] = i;
        IOR(v, 0, idx)  {
            if(Prime[v] * i >= MAXN) break;
            Vis[i * Prime[v]] = 1;

            if(!(i % Prime[v])) break;
            Mu[i * Prime[v]] = -Mu[i];
        }
    }

    IOR(i, 1, MAXN) 
        Mu[i] += Mu[i-1];
}