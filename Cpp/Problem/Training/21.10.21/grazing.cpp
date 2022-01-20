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

const int _N = 5e4 + 10;
const int INF = 1e9 + 7;

struct Node {
	long long l, r;
	Node(long long _l = 0, long long _r = 0) {
		l = _l; r = _r;
	}
	friend bool operator<(Node x, Node y) {
		return x.r < y.r;
	}
}L[_N];

int n, ans;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else
	freopen("grazing.in", "r", stdin);
	freopen("grazing.out", "w", stdout);
#endif

	IN >> n;
	IOR(i, 0, n) IN >> L[i].l >> L[i].r;

	sort(L, L+n);

	int mk = INF;
	IOR(i, 0, n) if(L[i].r <= mk || L[i].l >= mk) 
		mk = L[i].r, ans++;

	cout << ans;

	return 0;
} /**/













