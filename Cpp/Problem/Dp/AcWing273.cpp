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

const int MAXN = 2e3 + 10;
const int INF = 0x3f3f3f3f;

int A[MAXN], F[MAXN][MAXN], T[MAXN], Q[MAXN];
int n, idx;

long long Abs(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n; 
	IOR(i, 1, n+1) IN >> A[i], T[i] = A[i];

	sort(T+1, T+n+1);
	idx = unique(T+1, T+n+1) - T;
//	IOR(i, 1, n+1) 
//		Q[i] = lowwer_bound(T+1, T+n+1, A[i]);

	memset(F, 0x3f, sizeof F);
	IOR(i, 1, n+1) {
		int mn = INF;
		IOR(v, 1, idx+1) {
			F[i][v] = min(F[i][v], mn + Abs(A[i] - T[v]));
			mn = min(mn, F[i-1][v]);
		}
	}
	ans = mn;

	memset(F, 0, sizeof F);
	IOR(i, 1, n+1) {
		int mx = 0;
		IOR(v, 1, idx+1) {
			F[i][v] = min(F[i][v], mn + Abs(A[i] - T[v]));
			mn = min(mn, F[i-1][v]);
		}
	}

	return 0;
} /**/

long long Abs(int x) {
	return x < 0 ? -x : x;
}








