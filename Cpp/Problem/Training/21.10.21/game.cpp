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

const int _N = 50 + 10;
const int _G = 10 + 10;
const int _V = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int TC[_N][_G], TW[_N][_G], P[_N], G[_G], Pf[_N][_V], F[_V];
int n, v;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else 
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
	IN >> n >> v; 
	IOR(i, 0, n) {
		IN >> P[i] >> G[i];
		IOR(v, 0, G[i]) IN >> TC[i][v] >> TW[i][v];
	}

	memset(Pf, 0, sizeof Pf);
//	IOR(i, 0, n) Pf[i][0] = 0;

	IOR(i, 0, n) IOR(p, 0, G[i]) LOR(q, v, TC[i][p]-1) 
		Pf[i][q+P[i]] = max(Pf[i][q+P[i]], 
							Pf[i][q-TC[i][p]+P[i]] + TW[i][p]);

//	IOR(i, 0, v+1)
//		cout << "i = " << i << " i + P[1] = " << i + P[1] << " Pf = " << Pf[1][i+P[1]] 
//	<< "\n";

	IOR(i, 0, n) LOR(q, v, -1) IOR(p, 0, v+1)
		if(q-p < 0) continue;
		else F[q] = max(F[q], 
						F[q-p] + Pf[i][p]);

//	IOR(p, 0, v+1) LOR(q, v, p-1) 
//		F[q] = max(F[q], 
//				F[q-p] + Pf[0][p]);
//	IOR(i, 0, v+1)
//		printf("F[%d] = %d\n", i, F[i]);

	int ans = -INF;
	IOR(i, 0, v+1) ans = max(ans, F[i]);

	cout << ans << "\n";

	return 0;
} /**/















