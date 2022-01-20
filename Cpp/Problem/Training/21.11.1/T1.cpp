#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

long long tmp;
long long n, k;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif

	IN >> n >> k;

	/*
	IR(i, 1, n) 
		ans += k % i;
	cout << ans << "\n";
	*/
	
	long long lmt = k;
	for(long long l = 1, r; l <= min(k, n); ) {
		r = lmt / (lmt / l);
		if(r > n) {
			r = n;
			tmp += (r * (r + 1) / 2 - (l-1) * l / 2) * (k / l);
			break;
		}
		tmp += (r * (r + 1) / 2 - (l-1) * l / 2) * (k / l);
//		printf("l = %d, r = %d, tmp = %d\n", l, r, tmp);
		l = r + 1;
	}
//	cout << tmp << "\n";
	cout << n * k - tmp;

	return 0;
} /**/










