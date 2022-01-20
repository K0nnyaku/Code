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

const int _N = 1e5 + 10;
const int P = 5000011;
const int INF = 0x3f3f3f3f;

#define S(x, y) (((x % P) + (y % P)) % P)

int n, m, ans;

bool Check(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\WA.out", "w", stdout);
#else
	freopen("bullcow.in", "r", stdin);
	freopen("bullcow.out", "w", stdout);
#endif
	IN >> n >> m;

	IR(i, 0, (1 << n) - 1) 
		ans += Check(i);

	cout << ans << "\n";

	return 0;
} /**/

bool Check(int x) {
	int last = -INF;
	IR(i, 0, n-1) {
		if(x & (1 << i)) 
			if(i - last <= m) return false;
			else last = i;
	}

//	IR(i, 0, n-1) 
//		cout << (( x & ( 1 << i ) ) != 0 ) << " ";
//	cout << "\n";

	return true;
}












