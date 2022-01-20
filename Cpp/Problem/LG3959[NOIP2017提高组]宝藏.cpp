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

const int MAXN = 12 + 10;
const int MAXM = 1e3 + 10;
const int MAXV = (1 << 13) + 1;
const int INF = 0x3f3f3f3f;

vector<int> Cost[MAXV], To[MAXV];
int E[MAXN][MAXN], Ex[MAXV], Road[MAXV][MAXN], F[MAXN][MAXV];
int n, m;

int Expand(int x);
int Calc(int x, int y);
bool Valid(int x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;

	memset(Road, 0x3f, sizeof Road);
	memset(E, 0x3f, sizeof E);
	IOR(i, 0, n) E[i][i] = 0;

	IOR(i, 0, m) {
		int u, v, w; IN >> u >> v >> w;
		u--; v--;
		E[u][v] = E[v][u] = min(E[v][u], w);
	}

	IOR(i, 1, 1 << n) 
		Ex[i] = Expand(i);

	IOR(i, 0, 1 << n) 
		for(int v = Ex[i]; v; v = (v - 1) & Ex[i]) 
			if(Valid(i, v))
				To[v].push_back(i),
				Cost[v].push_back(Calc(i, v));

	memset(F, 0x3f, sizeof F);
	IOR(i, 0, n) 
		F[1][1 << i] = 0;

	IOR(i, 2, n) IOR(v, 0, 1 << n) IOR(k, 0, To[v].size()) {
		F[i][v] = min(F[i][v], 
				F[i-1][To[v][k]] + (i - 1) * Cost[v][k]);
	}

	int ans = INF;
	IOR(i, 0, n) 
		ans = min(ans, F[i][(1 << n) - 1]);

	if(n == 1)
		cout << "0";
	else
		cout << ans << "\n";

	return 0;
} /**/

int Expand(int x) {
	int res = x;
	IOR(i, 0, n) if(x & (1 << i)) IOR(v, 0, n) 
		res |= (E[i][v] != INF) * (1 << v), Road[x][v] = min(Road[x][v], E[i][v]);
	return res;
}

int Calc(int x, int y) {
	int res = 0;
	IOR(i, 0, n) {
		int a = x & (1 << i), b = y & (1 << i);
		if(!(a && b) && (a | b)) res += Road[x][i];
	}
	return res;
}

bool Valid(int x, int y) {
	return ((x & y) == x) && ((y & Ex[x]) == y);
}











