#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
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
		if(l == '-') x = -x;
		return *this;
	}
}IN;

const int N_ = 4e5 + 7;

long long A[N_], n, sum, k;

namespace Sub1 {
	queue<long long> Q[2];
	void Solve() {
		IR(i, 1, n) Q[0].push(A[i]);

		int y, x;

		bool cur = 0;
		Ir(i, 1, n) {
			while(Q[cur^1].size()) Q[cur^1].pop();

			x = Q[cur].front(); Q[cur].pop();
			while(Q[cur].size()) {
				y = Q[cur].front(); Q[cur].pop();
				Q[cur^1].push((x+y)%k); x = y;
			}
			cur ^= 1;
		}
		cout << Q[cur].front() << "\n";
	}
}

namespace Sub2 {

	long long Fac[N_], Ie[N_]; 
	
	 
	long long Qp(long long x, long long e, long long p) {
		long long res = 1;
		x %= p;
		while(e) {
			if(e & 1) res = res * x % p;
			x = x * x % p; e >>= 1;
		}
		return res % p;
	}

	void Pre(long long p) {
		Fac[0] = Ie[0] = 1;	
		IR(i, 1, p) 
			Fac[i] = Fac[i-1] * i % p,
			Ie[i] = Qp(Fac[i], p-2, p);
	}

	long long C(long long n, long long m, long long p) {
		if(n < m) return 0;
		return Fac[n] * (Ie[m] * Ie[n-m] % p) % p;
	}

	void Solve() {
		long long sum = 0;	
		Pre(n+2);
		IR(i, 1, n) sum += (A[i] % k) * C(i-1, n-1, k) % k, sum %= k;
		cout << sum << "\n";
	}
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> k;
	
	IR(i, 1, n) IN >> A[i];

	if(n <= 1000) Sub1::Solve();
	else          Sub2::Solve();

	return 0;
} /**/
