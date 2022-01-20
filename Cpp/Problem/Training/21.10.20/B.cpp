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

const int _N = 1e5 + 10;

struct Line {
	int l, r;
	Line(int _l = 0, int _r = 0) {
		l = _l; r = _r;
	}
	friend bool operator<(Line x, Line y) {
		return x.l == y.l ? x.r < y.r : x.l < y.l;
	}
}L[_N];

int n, m, s = 1, ans;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else 
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	IN >> m >> n;
	IOR(i, 0, n) 
		IN >> L[i].l >> L[i].r;
	sort(L, L+n);

	IOR(i, 0, n) {
		int t = i;
		while(L[t].l <= s && t < n) t++;
		i = t-1;
		t--;

		if(t == i && L[t].l > s) {
			cout << "NO" << "\n";
			return 0;
		}

		s = L[t].r+1;

		ans++;
		if(s >= m) {
			cout << ans << "\n";
			return 0;
		}
	}
	cout << "NO" << "\n";

	return 0;
} /**/












