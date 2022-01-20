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

const int N_ = 10 + 3;

int n;
int A[N_], B[N_];

bool Chk();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> B[i], A[i] = i;

	if(n > 11) { cout << -1 << "\n"; return 0; }

	do {
		if(Chk()) {
			IR(i, 1, n) cout << A[i] << " ";
			return 0;
		}
	}while(next_permutation(A+1, A+n+1));

	cout << -1;

	return 0;
} /**/

bool Chk() {
	int T[N_];

	IR(i, 1, n) T[i] = A[A[i]];
	IR(i, 1, n) if(T[i] != B[i]) return false;

	return true;
}













