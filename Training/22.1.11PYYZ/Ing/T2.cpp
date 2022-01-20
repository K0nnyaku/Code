#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 5e3 + 7;

template<typename T, int N>
struct FenWickSP {
	T A[N];
	FenWickSP() { FL(A, 0); }
	T AkP(int x) {
		T res = 0; 
		while(x) res += A[x], x -= x & -x;
		return res;
	}
	void CgP(int x, int v) { while(x <= N) A[x] += v, x += x & -x; }
	void CgS(int l, int r, T v) { CgP(l, v); CgP(r+1, -v); }
};

FenWickSP<unsigned long long, N_> Fk;
unsigned long long A[N_<<1], n, ans;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
//	double st = clock();
	IN >> n;
	IR(i, 1, n) IN >> A[i], A[i+n] = A[i];

	IR(i, 1, n) 
		Sr(v, i, 1) if(A[i] > A[v]) Fk.CgS(A[i], A[i], 1);

	IR(i, 1, n) 
		Sr(v, i, 1) if(A[i] > A[v]) ans += Fk.AkP(A[v]);

	Ir(i, 1, n) {
		unsigned long long k = A[i]; Fk.CgS(k+1, n, -1);
		Fk.CgS(k, k, -Fk.AkP(k));
		
		Ir(v, i+1, n+i) if(k > A[v]) Fk.CgS(k, k, 1);
		Ir(v, i+1, n+i) if(k > A[v]) ans += Fk.AkP(A[v]);
	}
	cout << ans << "\n";
//	cout << clock() - st << "\n";

	return 0;
} /**/








