#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 5e4 + 2;
const int V_ = 1e3 + 2;
const int P = 1e9 + 7;

long long A[N_], S[V_];
long long ans, cnt;
int n;

#define M(x, y) (((x) % P) * ((y) % P) % P)
#define S(x, y) (((x) % P + (y) % P) % P)

int main() { /**/
#ifndef LOCAL
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout); 
#endif
	IN >> n;
	IR(i, 1, n) IN >> A[i], S[A[i]]++;
		
	IR(i, 1, 1000) IR(v, 1, 1000)
		ans = S(ans, M( M(i^v, i^v), M(S[i], S[v]) ) );
	cout << ans << "\n";

	return 0;
} /**/

/*
3
2 5 4
*/



















