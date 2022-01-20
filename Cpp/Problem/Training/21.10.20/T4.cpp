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

const int _N = 1e3;

struct Node {
	int x, y;
	Node(int _x = 0, int _y = 0) {
		x = _x; y = _y;
	}
};

int Mp[_N][_N];
int Way[4][2] = {
	{0, 0}, {0, -1}, {1, 0}, {0, 1}{-1, 0} };
int n, m, d, v, x, y;

Node Work(int w, v, x, y) {
	
}

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else 
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	IN >> n >> m;

	memset(Mp, 0x3f, Mp);
	IOR(i, 1, n+1) IOR(v, 1, m+1)
		IN >> Mp[i][v];

	IN >> d >> v >> x >> y;

	Node ans = Work(d, v, x, y);
	cout << ans.x << " " << ans.y << "\n";


	return 0;
} /**/










