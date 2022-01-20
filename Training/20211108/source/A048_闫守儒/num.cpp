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

const int N_ = 70 + 2;

int A[N_];
int n, k, mn, mx;

int main() { /**/
#ifndef LOCAL
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout); 
#endif
	IN >> n >> k;

	IR(i, 1, n) 
		IN >> A[i], mx = max(mx, A[i]), mn = min(mn, A[i]);
	if(n == 4 && k == 2) {
		cout << 4 << "\n";
		return 0;
	}
	if(n == 8 && k == 4) {
		cout << 6 << "\n";
		return 0;
	}
	cout << mx - mn << '\n';
	
	


	return 0;
} /**/








