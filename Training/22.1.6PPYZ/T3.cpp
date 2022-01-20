#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

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

const int N_ = 1e2 + 7;
const int M_ = 1e2 + 7;
const int P = 1e9 + 7;

long long Mp[N_][M_], F[N_+M_];
long long ans, sum, n, m, k, s;

long long Qp(long long x, int e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res *= x, res %= P;
		x *= x;	  x %= P;   e >>= 1;
	}
	return res;
}

long long Ie(long long x) { return Qp(x, P-2); }
void Pre() {
	F[0] = 1;
	Ir(i, 1, N_<<1) F[i] = i * F[i-1], F[i] %= P;
}
long long C(long long x, long long y) { 
	if(!y) return 1;
	return F[x] * Ie(F[y]*F[x-y]) % P; 
}

void Fd(int x, int y, int res) {
	if(x == n && y == m) { sum += res % P; sum %= P; return ; }

	if(x + 1 <= n) Fd(x+1, y, Mp[x+1][y] ? res / 2 + res % 2 : res);
	if(y + 1 <= m) Fd(x, y+1, Mp[x][y+1] ? res / 2 + res % 2 : res);
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> k >> s;
	IR(i, 1, k) { int u, v; IN >> u >> v; Mp[u][v] = 1; }

	Pre();

	if(Mp[1][1]) s = s / 2 + s % 2;
	Fd(1, 1, s);

	cout << sum * Ie(C(n+m-2, n-1)) % P << "\n";

	return 0;
} /**/















