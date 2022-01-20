#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 1e4 + 2;
const int M_ = 50 + 2;
const double EPS = 1e-8;
const double INF = 1e4 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
};

Edge<N_, N_ * M_> G;
pair<int, int> Iv[M_], Pro[N_];
int n, m, pt, lt, v;
double Far[N_][M_];

double Calc(int x, int y, int a, int b);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> pt >> lt >> v;
	IR(i, 1, m) IN >> Iv[i].first >> Iv[i].second;
	IR(i, 1, n) IN >> Pro[i].first >> Pro[i].second;

	IR(i, 1, n) IR(v, 1, m) 
		Far[i][v] = Calc(Pro[i].first, Pro[i].second, Iv[i].first, Iv[i].second);

	double l = 0, r = INF;
	while(r - l > EPS) {
		double mid = (l + r) / 2;
		if(Chk(mid)) r = mid;
		else l = mid;
	}

	return 0;
} /**/

double Calc(int x, int y, int a, int b) {
	return sqrt( pow((double)x-a, 2.0) + pow((double)y - b, 2.0) );
}










