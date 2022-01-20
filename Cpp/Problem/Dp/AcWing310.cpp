#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

const int _BUF = 1e2 + 10;
struct FastIO
{
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _L = 30 + 10;
long long F[_L][4];
int t;

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif

	Pre();

	IN >> t;
	while(t--) {
		long long x; IN >> x;

		int len;
		IR(i, 3, _L-1) if(F[i][3] >= x) {
			len = i; break;
		}

		int k = 0;
		SR(i, len, 1) IR(v, 0, 9) {

			long long tmp = F[i-1][3];
			if(v == 6 || k == 3) IR(p, max(0, 3 - k - (v == 6)), 2) 
				tmp += F[i-1][p];

			if(tmp >= x) {
				cout << v;
				if(k < 3) 
					k = v == 6 ? k+1 : 0;
				break;
			}
			else 
				x -= tmp;
		}

		cout << "\n";
	}


	return 0;
} /**/

void Pre() {
	F[0][0] = 1;
	IR(i, 1, _L-1) {
		IR(k, 0, 2) F[i][0] += 9 * F[i-1][k];
		F[i][1] = F[i-1][0];
		F[i][2] = F[i-1][1];
		F[i][3] = F[i-1][2] + 10 * F[i-1][3];
		/*
		cout << "\n-----------------------\n";
		IR(v, 0, 3)
			printf("F[%d][%d] = %d\n", i, v, F[i][v]);
		cout << "-----------------------\n";
		*/
	}
}




















