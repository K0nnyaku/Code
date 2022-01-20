//---------------------Tem For Cpp-------------------------//
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

const int MAXN = 1e3+10;
const int MAXL = 2e2+10;
const int INF = 0x3f3f3f3f;

int C[MAXL][MAXL], F[MAXN][MAXL][MAXL], P[MAXN];
int T;

void Init();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> T;
	while(T--) {
		int l, n; IN >> l >> n;
		IOR(i, 1, l+1) IOR(v, 1, l+1)
			IN >> C[i][v];
		IOR(i, 1, n+1) IN >> P[i];

		Init();

		IOR(i, 1, n+1) IOR(x, 1, l+1) IOR(y, 1, l+1) {
			if(x == y || x == P[i-1] || y == P[i-1])
				continue;

			F[i][x][y] = min(F[i][x][y], 
					F[i-1][x][y] + C[P[i-1]][P[i]]);

			F[i][P[i-1]][y] = min(F[i][P[i-1]][y],
					F[i-1][x][y] + C[x][P[i]]);

			F[i][x][P[i-1]] = min(F[i][x][P[i-1]], 
					F[i-1][x][y] + C[y][P[i]]);
		}

		int ans = INF;
		IOR(x, 1, l+1) IOR(y, 1, l+1) 
			ans = min(ans, F[n][x][y]);

		cout << ans << "\n";
	}

	return 0;
} /**/

void Init() {
	memset(F, 0x3f, sizeof F);
	P[0] = 3;
	F[0][1][2] = 0;
}









