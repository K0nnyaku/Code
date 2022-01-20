#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

int k, v;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
#endif
	IN >> k >> v;
	if(k <= 10 && v <= 10) {
		int pos = 2, n = k + 1, m = 1 + (k - 1) * 2;

		cout << n << " " << m << "\n";
		cout << 1 << " " << n << " " << v << "\n";

		IR(i, 1, k-1) {
			cout << 1 << " " << i+1 << " " << v + i - 1 << "\n";
			cout << i+1 << " " << n << " " << 1 << "\n";
		}
	}

	return 0;
} /**/







