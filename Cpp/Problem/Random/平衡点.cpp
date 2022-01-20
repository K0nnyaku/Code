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

struct Node {     
	int x, y, w;
	Node(int x_ = 0, int y_ = 0, int w_ = 0) { x = x_; y = y_; w = w_; }
};

const int N_ = 1e4 + 7;
const double E = 0.98;
const double EPS = 1e-10;

Node A[N_];
double x, y, z;
int n;

mt19937 Random(19260817);
int Rand(int l = -10000, int r = 10000) { return Random() % (r - l + 1) + l;	}

double Vf(double x, double y) {
	double res = 0;
	IR(i, 1, n) 
		res += sqrt(pow(x-A[i].x, 2) + pow(y-A[i].y, 2)) * A[i].w;
	return res;
}


void Sa() {
	double temp = 3e3;
	while(temp > EPS) {
		double u = x + (Rand() - Rand()) * temp;
		double v = y + (Rand() - Rand()) * temp;

		double w = Vf(u, v);
		double del = w - z;

		if(del < 0) x = u, y = v, z = w;
		else if(exp(-del/temp) * UINT_MAX > Random()) x = u, y = v;

		temp *= E;
	}
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> A[i].x >> A[i].y >> A[i].w, x += A[i].x, y += A[i].y;

	x /= n; y /= n; z = Vf(x, y);

	while((double)clock() / CLOCKS_PER_SEC < 0.8) Sa();

	printf("%.3lf %.3lf\n", x, y);

	return 0;
} /**/












