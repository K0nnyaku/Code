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

long long Phi[MAXN], Sphi[MAXN];
long long ans;
int n, p;

long long Qp(long long x, long long e);
long long Wk(long long x, long long e);
long long IE(long long x);
void Euler();


int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
//printf("st = %d\n", clock());
	IN >> n >> p;
	Euler();

	if(p == 1) {
		printf("%lld", Sphi[n]);
		return 0;
	}

	IOR(i, 1, n+1) {
		ans = ((Phi[i] * Wk(i, p)) % P + ans) % P; 
	}
	
	printf("%lld\n", ans);
//printf("ed = %d\n", clock());

	return 0;
} /**/

int Prime[MAXN];
int idx;
bool Vis[MAXN];

void Euler() {
	Phi[1] = 1;
	IOR(i, 2, MAXN) {
		if(!Vis[i]) Prime[idx++] = i, Vis[i] = 1, Phi[i] = i - 1;
		IOR(v, 0, idx && i * Prime[v] < MAXN) {
			Vis[i * Prime[v]] = 1;
			if(!(i % Prime[v])) {
				Phi[i * Prime[v]] = Phi[i] * Prime[v];
				break;
			}
			Phi[i * Prime[v]] = Phi[i] * (Prime[v] - 1);
		}
	}
	IOR(i, 1, MAXN) 
		Sphi[i] = (Phi[i] % P + Sphi[i-1] % P) % P;
} 

long long Qp(long long x, long long e) {
	if(!e) return 1;
	long long res = Qp(x, e/2) % P;
	return e % 2 ? (res * res % P * x) % P : res * res % P;
}

long long Wk(long long x, long long e) {
	if(x == 1) return e;
	return (1 - Qp(x, e)) * IE(1 - x) % P;
}

long long IE(long long x) {
	return Qp(x, P-2);
}
