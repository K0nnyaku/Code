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

const int MAXN = 15 + 10;
const int INF = 0x3f3f3f3f;

int A[MAXN][MAXN], F[MAXN][MAXN][MAXN][MAXN][2][2];
int n, m, k, ans = -INF;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m >> k;
	IOR(i, 1, n+1) IOR(v, 1, m+1)
		IN >> A[i][v];

	memset(F, -0x3f, sizeof F);

	IOR(i, 0, n+1)
		F[i][0][0][0][1][0] = 0;

	IOR(i, 1, n+1) IOR(j, 1, k+1) IOR(l, 1, n+1) IOR(r, l, n+1) IOR(x, 0, 1) IOR(y, 0, 1) {
		if(j < (r-l+1)) continue;

		if(x == 1 && y == 0) 
			if(j > (r - l + 1)) 
				IOR(l_, l, r+1) IOR(r_, l_, r+1) 
					F[i][j][l][r][x][y] = max( F[i][j][l][r][x][y], 
							F[i-1][j-(r-l+1)][l_][r_][1][0]);
			else
				F[i][j][l][r][x][y] = F[i-1][0][0][0][1][0];

		if(x == 1 && y == 1) 
			IOR(l_, l, r+1) IOR(r_, r, m+1) IOR(y_, 0, 1) 
				F[i][j][l][r][x][y] = max( F[i][j][l][r][x][y],
						F[i-1][j-(r-l+1)][l_][r_][1][y_]);

		if(x == 0 && y == 0) 
			IOR(l_, 1, l+1) IOR(r_, l, r+1) IOR(x_, 0, 1) 
				F[i][j][l][r][x][y] = max( F[i][j][l][r][x][y],
						F[i-1][j-(r-l+1)][l_][r_][x_][0]);

		if(x == 0 && y == 1) 
			IOR(l_, 1, l+1) IOR(r_, r, m+1) IOR(x_, 0, 1) IOR(y_, 0, 1)
				F[i][j][l][r][x][y] = max( F[i][j][l][r][x][y],
						F[i-1][j-(r-l+1)][l_][r_][x_][y_]);

		IOR(v, l, r+1)
			F[i][j][l][r][x][y] += A[i][v];
	}

	IOR(i, 1, n+1) IOR(j, 1, k+1) IOR(l, 1, n+1) IOR(r, l, n+1) IOR(x, 0, 1) IOR(y, 0, 1) 
		ans = max(ans, F[i][j][l][r][x][y]);

	cout << ans;

	return 0;
} /**/














