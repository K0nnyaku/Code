#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
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

const int _N = 50 + 10;
const int INF = 0x3f3f3f3f;

int F[_N<<2][_N][_N], Mp[_N][_N];
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else 
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif

	IN >> n >> m;
    IOR(i, 1, n+1) IOR(v, 1, m+1)
		IN >> Mp[i][v];
	
	memset(F, 0x3f, sizeof F);

	F[2][1][1] = 0;
	IOR(i, 3, n+m+1) IOR(v, 1, n+1) IOR(k, 1, n+1) {
		int b = i - v, y = i - k;
		if(b <= 0 || y <= 0) continue;
		if(v == k && !(k == 1 && v == 1) && !(k == n && v == n)) 
			continue;

		F[i][v][k] = Mp[v][b] + Mp[k][y]
				  + min(
					min(F[i-1][v][k], F[i-1][v-1][k-1]), 
					min(F[i-1][v][k-1], F[i-1][v-1][k]));
	}

	printf("%lld",F[n+m][n][m]);


	return 0;
} /**/













