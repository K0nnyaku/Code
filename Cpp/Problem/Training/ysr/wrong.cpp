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

const int N_ = 20 + 2;
const int M_ = N_;

int A[N_], Ans[M_];
int n, m;

int Abs(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("wrong.in", "r", stdin);
	freopen("wrong.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) A[i] = i;

	do {
		int sum = 0;
		bool flag = 0; 
		IR(i, 1, n) {
			int tmp = Abs(A[i] - i);
			if(!tmp) {
				flag = 1; break; }
			sum += Abs(A[i]-i);
		}
		if(!flag) Ans[sum]++;
	}while(next_permutation(A+1, A+1+n));

	IR(i, 1, m+1) 
		printf("%d ", Ans[i-1]);

	return 0;
} /**/

int Abs(int x) {
	return x < 0 ? -x : x; }









