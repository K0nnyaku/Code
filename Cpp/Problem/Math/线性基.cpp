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

const int L_ = 50 + 3;
const int N_ = 50 + 3;

long long Lb[N_];
int n;

void Ins(long long x);
long long Solve();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) {
		long long x; IN >> x;
		Ins(x);
	}

	cout << Solve();

	return 0;
} /**/

void Ins(long long x) {
	Sr(i, L_, 0) {
		if(!(x >> i)) continue;
		if(!Lb[i]) { Lb[i] = x; break; }
		x ^= Lb[i];
	}
}

long long Solve() {
	long long res = 0;
	Sr(i, L_, 0) if((res ^ Lb[i]) > res) res ^= Lb[i];
	return res;
}








