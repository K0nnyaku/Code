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

const int N_ = 20;
const int M_ = 1e2 + 10;
const unsigned long long P = 67280421310721;

unsigned long long A[N_], X[N_], Sm, s;
int n, m, k;

void Dfs(int x, unsigned long long sum) {
	if(x > k) { Sm += sum, Sm %= P; s++; return ; }

	IR(i, 1, n) {
		unsigned long long tmp = A[i];
		A[i] ^= X[k % m];
		Dfs(x+1, (sum + A[i] - tmp) % P);
		A[i] = tmp;
	}
}

unsigned long long Qp(unsigned long long x, unsigned long long e, unsigned long long p) {
	unsigned long long res = 1;
	x %= p;
	while(e) {
		if(e & 1) res = res * x % p;
		x = x * x % p; e >>= 1;
	}
	return res % p;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);
#endif
	IN >> n >> m >> k;
	Ir(i, 0, m) IN >> X[i];

	Dfs(1, 0);

	cout << Sm / s << "\n";
//	Sm = ( (Sm % P) * Qp(s, P-2, P) ) % P;
//	cout << Sm << "\n";

//	cout << (((Sm % P) * Qp(s, P-2, P)) % P) << "\n";

	return 0;
} /**/


