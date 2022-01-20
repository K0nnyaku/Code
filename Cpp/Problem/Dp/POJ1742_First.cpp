//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
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

const int MAXV = 1e6 + 10;
const int MAXN = 1e6 + 10;

int W[MAXN], A[MAXN], B[MAXN];
int n, m, cnt, T;
bool F[MAXN];

void Divide(int x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	F[0] = true;
	while(n + m) {
		IOR(i, 0, n) IN >> A[i];
		IOR(i, 0, n) IN >> B[i];

		IOR(i, 0, n) Divide(A[i], B[i]);

		IOR(i, 0, cnt) {
			LOR(v, m, W[i]-1) 
				F[v] |= F[v - W[i]];
		}

		int ans = 0;
		IOR(i, 1, m+1) ans += F[i], F[i] = 0;

		cout << ans << "\n";

		IN >> n >> m;

		cnt = 0;
	}

	return 0;
} /**/

void Divide(int x, int y) {
	int i;
	for(i = 1; i < y; i <<= 1) 
		W[cnt++] = x * i;

	i >>= 1;
	int res = y - i;
	if(res > 0) W[cnt++] = x * res;
}

//问题:
//










