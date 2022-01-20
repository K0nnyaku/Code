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

const int N_ = 1e3 + 2;

int A[N_], B[N_];
int n, m, cnt = 0;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> m;
	Ir(i, 0, m) IN >> A[i], A[i] = -A[i];
	IN >> n;
	Ir(i, 0, n) IN >> B[i];

	sort(A, A+m);
	sort(B, B+m);

	Ir(i, 0, m) 
		while(B[cnt] <= -A[i] && (A[i] += B[cnt++])) ;

	cout << cnt << "\n";

	
	return 0;
} /**/















