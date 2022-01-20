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

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;

struct { int a, b; } Ba[MAXN];
int n, m, ans = INF;

int Wk(int x) {
	int Bk[MAXN];
	memset(Bk, 0, (m+1) * sizeof (int));
	IOR(i, 0, n) {
		if((x >> i) & 1) 
			Bk[Ba[i].a]++;
		else 
			Bk[Ba[i].b]++;
	}
	int res = 0;
	IOR(i, 1, m+1) 
		if(Bk[i] % 2) 
			res++;
//	IOR(i, 1, m+1) printf("%d ", Bk[i]);
//	printf("%d %d\n", x, res);
	return res;
}

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n >> m;
	bool flag1 = 0, flag2 = 0;
	IOR(i, 0, n) {
		IN >> Ba[i].a >> Ba[i].b;
		if(Ba[i].a != Ba[i].b) flag1 = 1;
		if(Ba[i].b != 1 || Ba[i].a != i+1) flag2 = 1;
	}
	flag2 = flag2 || (n != m);
	
	if(n <= 10 && m <= 10)
		IOR(i, 0, 1 << n) {
			ans = min(ans, Wk(i));
		}
	else 
	if(!flag1) {
		int Bk[MAXN];
		ans = 0;
		memset(Bk, 0, sizeof Bk);
		IOR(i, 0, n) 
			Bk[Ba[i].a]++;
		IOR(i, 1, m+1) if(Bk[i] % 2) 
			ans++;
	}
	else
	if(!flag2) {
		ans = n % 2;
	}

	printf("%d", ans);

	return 0;
} /**/