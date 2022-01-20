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

const int MAXN = 3e3 + 10;
const int INF = 0x3f3f3f3f;

int F[MAXN][MAXN], A[MAXN], B[MAXN];
int n;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n;
	IOR(i, 1, n+1) IN >> A[i];
	IOR(i, 1, n+1) IN >> B[i];

	A[0] = B[0] = -INF;

	IOR(i, 1, n+1) {
		int mx = 0;

		IOR(v, 1, n+1) {
			F[i][v] = (A[i] == B[v] ? 
				mx+1 : F[i-1][v]);

			if(B[v] < A[i]) 
				mx = max(mx, F[i-1][v]);
		}
	}

	int ans = 0;
	IOR(i, 1, n+1) ans = max(ans, F[n][i]);

	cout << ans;

	return 0;
} /**/























