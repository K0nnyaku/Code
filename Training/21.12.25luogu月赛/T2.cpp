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

const int N_ = 1e5 + 10;

int A[N_];
int n, T, ans;

void Solve(int step, int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n >> T;
	IR(i, 1, n) IN >> A[i];

	while(T--) {
		int x; IN >> x;
		ans = 0;
		Solve(0, x);
		cout << ans << "\n";
	}

	return 0;
} /**/

void Solve(int x, int step) {
	if(step <= 0) { ans = max(ans, x); return ; }
	IR(i, 1, n) Solve(x >= A[i] ? x - A[i] : x + A[i], step-1);
}













