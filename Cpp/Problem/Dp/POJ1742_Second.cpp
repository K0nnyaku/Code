//#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
#include<iostream>
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

const int MAXN = 1e6 + 10;

int A[MAXN], B[MAXN], Use[MAXN], F[MAXN];
int T, n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	while(n + m) {
		memset(F, 0, (m+10) * sizeof(int));
		F[0] = true;

		IOR(i, 0, n) IN >> A[i];
		IOR(i, 0, n) IN >> B[i];

		IOR(i, 0, n) {
			memset(Use, 0, (m+10) * sizeof(int));
			IOR(v, A[i], m+1) 
				if(!F[v] && F[v-A[i]] && Use[v-A[i]] < B[i]) 
					F[v] = true, Use[v] = Use[v-A[i]] + 1;
		}

		int ans = 0;
		IOR(i, 1, m+1) ans += F[i];

		cout << ans << "\n";

		IN >> n >> m;
	}

	return 0;
} /**/







