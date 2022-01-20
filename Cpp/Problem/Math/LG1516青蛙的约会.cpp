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

long long Exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) { x = 1, y = 0; return a; }
	long long res = Exgcd(b, a % b, y, x);
	y -= x * (a / b);	   return res;
}

long long n, m, x, y, l, k, t;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> x >> y >> m >> n >> l;
	if(m-n < 0) m = -m , n = -n, x = -x, y = -y;
	long long d = Exgcd(m-n, l, k, t);

	if((y - x) % d) cout << "Impossible\n";
	else cout << ((k * (y - x) / d) % (l / d) + (l / d)) % (l / d);

	return 0;
} /**/










