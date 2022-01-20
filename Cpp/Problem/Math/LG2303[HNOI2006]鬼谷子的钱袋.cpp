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

const int MAXN = 1e2 + 10;

int A[MAXN];
int n, k;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif

	IN >> n;
	for(k = 1; n; k++, n /= 2) 
		A[k] = (n+1) / 2;

	cout << k - 1 << "\n";
	LOR(i, k - 1, 0) 
		cout << A[i] << " ";

	return 0;
}
