#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
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

const int _N = 2e3 + 2;
const int _V = 2e6 + 10;
const int P = 1e9 + 7;

struct Node {
	int x, y;
	Node(int _x = 0, int _y = 0) {
		x = _x; y = _y;
	}
	bool friend operator<(Node x, Node y) {
		return x.x == y.x ? x.y < y.y : x.x < y.x;
	}
}N[_N];

#define X(y) N[y].x
#define Y(x) N[x].y
#define S(x, y) (((x % P) + (y % P)) % P)
#define R(x, y) (((x % P) - (y % P)) % P)
#define M(x, y) ((x % P) * (y % P) % P)

long long F[_V], Fac[_V], Ie[_V];
long long h, w, n;

void Pre();
long long C(int x, int y);
long long Qp(long long x, int e);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif

	IN >> h >> w >> n;
	IR(i, 1, n) IN >> N[i].x >> N[i].y;
	N[n+1] = Node(h, w);

	sort(N+1, N+n+1);

	Pre();

	IR(i, 1, n+1) F[i] = C( X(i)+Y(i)-2, X(i)-1 );

	IR(i, 2, n+1) IR(v, 1, i-1) if(X(v) <= X(i) && Y(v) <= Y(i))
		F[i] =
			R(F[i], 
			  M(F[v], 
				C( X(i)-X(v) + Y(i)-Y(v), X(i) - X(v)) ) );

	cout << (F[n+1] + P) % P << "\n";

	return 0;
} /**/

void Pre() {
	Fac[0] = Ie[0] = 1;
	IR(i, 1, _V-1)  
		Fac[i] = M(Fac[i-1], i),
		Ie[i] = Qp(Fac[i], P-2);
}

long long Qp(long long x, int e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = M(res, x);
		x = M(x, x); e >>= 1;
	}
	return res % P;
}

long long C(int x, int y) {
	if(x < y) return 0;
	return M(Fac[x], M(Ie[y], Ie[x-y]) );
}













