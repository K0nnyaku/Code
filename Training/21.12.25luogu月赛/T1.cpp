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

const int N_ = 7e6 + 3;
const long double EPS = 1e-17;

long double vr;
unsigned long long A[N_];
unsigned long long n, k;
bool Vn[N_];

long double Chk(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> k;
	IR(i, 1, n) IN >> A[i], Vn[A[i]] = 1, vr += A[i];
	vr /= n;

	int fg = 0;
	Ir(i, 1, N_) fg += Vn[i];
	if(fg == 1) { cout << "No answer!\n"; return 0; }

	unsigned long long l = 1, r = 1e13;
	while(l < r) {
		unsigned long long mid = (l + r) >> 1;
		if(Chk(mid) - k >= EPS) r = mid;
		else					l = mid + 1;
	}

	long double mn = abs(Chk(l) - k);
	unsigned ans = l;
	IR(i, 1, 3000) {
		if(l > i && abs(Chk(l-i) - k) - mn <= EPS) mn = abs(Chk(l-i) - k), ans = l-i;
		if(abs(Chk(l+i) - k) - mn <= EPS)		   mn = abs(Chk(l+i) - k), ans = l+i;	
	}

	cout << ans << "\n";

	return 0;
} /**/

long double Chk(int x) {
	long double res = 0, tmp = vr * x;

	IR(i, 1, n) res += pow((A[i] * x - tmp), 2);
	res /= n;

	return res;
}












