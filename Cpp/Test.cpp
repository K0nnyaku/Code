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

template<typename T, int N, int M>
struct FenWick {
	T A[N+3][M+3];
	void CgP(int x, int y, T v) {
		int yt = y;
		do 
			while(y <= N) A[x][y] += v, y += y & -y;
		while((x += x&-x) && (y = yt) && x <= N);
	}
	T AkS(int x, int y) {
		int yt = y; T res = 0;
		do 
			while(y) res += A[x][y], y -= y & -y;
		while((x -= x&-x) && (y = yt) && x);

		return res;
	}
	T AkSS(int x, int y, int a, int b) { 
		return AkS(a, b) + AkS(x-1, y-1) - AkS(a, y-1) - AkS(x-1, b); }

	T* operator[](const int &x) { return A[x]; }
};

const int N_ = 1 << 12;
const int M_ = 1 << 12;

FenWick<long long, N_, M_> Fk;
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/11.in",  "r", stdin );
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	int x, y, p, q; long long v;

	while(~scanf("%d", &x)) 
		if(x == 1) IN >> x >> y >> v,       Fk.CgP(x, y, v);
		else       IN >> x >> y >> p >> q,  cout << Fk.AkSS(x, y, p, q) << "\n";

	return 0;
} /**/

