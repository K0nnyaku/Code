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

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

long long A[MAXN], Up[MAXN], Down[MAXN];
long long b, k, n, mx = -INF, mn = INF;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n >> k >> b;
	IOR(i, 1, n+1) 
		IN >> A[i];
	
	if(k == 0) {
		printf("%lld\n", b);
		return 0;
	}
	
	Up[1] = Down[1] = A[1];
	mx = mn = A[1];

	IOR(i, 2, n+1) {
		Up[i] = max(A[i], A[i] + Up[i-1]);
		Down[i] = min(A[i], A[i] + Down[i-1]);
		mx = max(mx, Up[i]);
		mn = min(mn, Down[i]);
	}

	printf("%lld\n", max(k * mx, k * mn) + b);

	return 0;
} /**/