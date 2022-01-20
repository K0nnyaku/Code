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

const int MAXN = 1e5 + 10;


long long ans;
int A[MAXN], B[MAXN];
int n, m;

void Ins(long long x);
void Qy(int now, int flag, long long x, int res);

bool Check(int x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
#endif
	IN >> n >> m;
	IOR(i, 1, n+1) IN >> A[i];
	IOR(i, 1, m+1) IN >> B[i];

	IOR(i, 1, n+1) IOR(j, 1, m+1) 
		ans += Check(A[i], B[j]);

	cout << ans;

	return 0;
} /**/

bool Check(int x, int y) {
	int res = 0;
	IOR(i, 0, 30) {
		int p = x & 1, q = y & 1;
		x >>= 1, y >>= 1;
		if(p != q) res++;

		if(res > 2) return false;
	}
	return res == 2;
}













