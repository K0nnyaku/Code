#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define LR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

const int N_ = 1e5 + 2;

map<pair<int, int>, int> Mp;
int n, tmp, atmp, btmp;

int Gcd(int a, int b);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) {
		int a, b, c; IN >> a >> b >> c;
		int d = Gcd(a, b);
		if(d < 0) d = -d;
		a /= d, b /= d;
		Mp[make_pair(a, b)]++;
		atmp += !a;
		btmp += !b;
	}

	for(map<pair<int, int>, int>::iterator it = Mp.begin(); it != Mp.end(); it++) {
		pair<pair<int, int> , int> p = *it;
		tmp = max(tmp, p.second);
	}

	if(!(atmp + btmp))
		printf("%d\n", n - tmp);
	else
		printf("%d\n", min(atmp, btmp));

	return 0;
} /**/

int Gcd(int a, int b) {
	return b ? Gcd(b, a % b) : a;
}














