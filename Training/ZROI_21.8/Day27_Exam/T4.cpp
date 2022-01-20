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

const int MAXN = 8 + 10;

int A[MAXN][MAXN];
int n;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n;
	IOR(i, 0, n) IOR(v, 0, n)
		IN >> A[i][v];
	if(n == 1) 
		printf("%d", A[0][0] != 0 ? A[0][0] : 1);
	else
	if(n == 2) {
		IOR(i, 1, 5) IOR(v, 1, 5) IOR(k, 1, 5) IOR(p, 1, 5) {
			int Bk[5]; memset(Bk, 0, sizeof Bk);
			int a = A[0][0] ? A[0][0] : i, 
				b = A[0][1] ? A[0][1] : v,
				x = A[1][0] ? A[1][0] : k,
				y = A[1][1] ? A[1][1] : p; 
			Bk[a]++, Bk[b]++, Bk[x]++, Bk[y]++;
			IOR(i, 1, 5) 
				if(Bk[i] > 1 || !Bk[i]) a = b = x = y;

			if(a < b && x < y) {
				printf("%d %d\n", a, b);
				printf("%d %d\n", x, y);
				return 0;
			}
		}
		printf("%d", -1);
	}

	return 0;
} /**/