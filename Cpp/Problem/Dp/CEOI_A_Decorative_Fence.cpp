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
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _N = 20 + 10;

long long F[_N][_N][2];
long long t, last;
bool Vis[_N];
bool way;

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> t;
	Pre();
//	IR(i, 1, 5) IR(v, 1, i) IR(k, 0, 1)
//		printf("F[%d][%d][%d] = %d\n", 
//				i, v, k, F[i][v][k]);

	while(t--) {
		long long n, c; IN >> n >> c;
		memset(Vis, 0, sizeof Vis);

		IR(i, 1, n) SR(v, 1, 0) 
			if(F[n][i][v] >= c) {
				printf("%d ", i);
				Vis[i] = 1, last = i, way = v^1;
				i = n+1; break;
			}
			else c -= F[n][i][v];

		int pos;
		SR(i, n-1, 1) IR(v, 1, n)  {
			if(v == 1) pos = 0;
			if(!Vis[v] && ++pos && ( (way && v > last) || (!way && v < last) ))  {
				
				if(F[i][pos][way] >= c) {
					printf("%d ", v);
					Vis[v] = 1;
					last = v, way ^= 1;
					break;
				}
				else c -= F[i][pos][way];
			}
		}

		cout << "\n";
	}

	return 0;
} /**/

void Pre() {
	F[1][1][0] = F[1][1][1] = 1;
	IR(i, 2, _N-1) IR(v, 1, i) {
		IR(k, v, i-1) 
			F[i][v][0] += F[i-1][k][1];
		IR(k, 1, v-1) 
			F[i][v][1] += F[i-1][k][0];
	}
}













