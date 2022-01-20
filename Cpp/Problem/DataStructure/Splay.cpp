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

template<typename T_data, int N>
struct Splay {
	int F[N], C[N][2], Q[N], cnt, rt;
	
#define W(x)  (x == C[F[x]][1])
#define Is(x) (x != )<++>
	void Up(int x) { Q[x] = C[x][0] [Q] + C[x][1] [Q] + 1; }
	void Cn(int x, int y, int p) { F[x] = y; C[y][p] = x; }
	void Rot(int x) {
		int u = F[x], v = F[u], p = W(x), q = W(u);
		Cn(u, v, q); Cn(C[x][p^1], u, p); Cn(u, x, p^1);
		Up(u);
	}

	void Sy(int x) {
		for(int y; !Is(x); Rot(x))
	}

	

};

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif

	return 0;
} /**/
