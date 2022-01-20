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

const int MAXN = 1e7 + 10;

long long F[MAXN], Mu[MAXN];
long long n, m, t, ans;

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> t;

    Pre();

    while(t--) {
        IN >> n >> m;
        if(n > m) 
            swap(n, m);
        ans = 0;
        for(int l = 1, r = 0; l <= n; l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += (F[r] - F[l-1]) * ((n / l) * (m / l));
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
            Prime[idx++] = i, Mu[i] = -1;
        IOR(v, 0, idx) {
            if(Prime[v] * i >= MAXN) break;

            Vis[i * Prime[v]] = 1;

            if(!(i % Prime[v])) 
                break;

            Mu[i * Prime[v]] = -Mu[i];
        }
    }

    IOR(i, 1, MAXN) IOR(v, 0, idx) {
        if(Prime[v] * i >= MAXN) break;
        F[i * Prime[v]] += Mu[i];

    }
    IOR(i, 1, MAXN) 
        F[i] += F[i-1];
}