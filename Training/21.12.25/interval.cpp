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

const int N_ = 1e3 + 3;

/*
template<int N, int M>
struct Edge {
	int I[N], To[M], Nt[M]; int cnt;
	Edge () { FL(I, 0); FL(To, 0); FL(Nt, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = I[u]; To[cnt] = v; I[u] = cnt; }
};
*/

struct Pair { 
	int a, b; 
	Pair(int a_ = 0, int b_ = 0) { a = a_; b = b_; } 
	friend bool operator<(const Pair &x, const Pair &y) {
		return (x.a > y.a && x.a < y.b) || (x.b > y.a && x.b < y.b);
	}
};

//Edge<N_, N_*N_> I;
Pair A[N_];
int n, lct, qct;
bool E[N_][N_];

void Floyd(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
#endif
	IN >> n;
	Ir(i, 1, N_) E[i][i] = 1;
	while(n--) {
		int opt, a, b; IN >> opt >> a >> b;
		if(opt == 1) {
			A[++lct] = Pair(a, b);
			Ir(i, 1, lct) {
				if(A[i] < A[lct]) E[i][lct] = 1;//I.Add(i, lct);
				if(A[lct] < A[i]) E[lct][i] = 1;//I.Add(lct, i);
			}
			Floyd(lct);
		}
		else 
			if(E[a][b]) cout << "YES\n";
			else		cout << "NO\n";
	}

	return 0;
} /**/

void Floyd(int x) {
	IR(i, 1, lct) IR(v, 1, lct) {
		E[i][v] |= (E[i][x] && E[x][v]);
//		if(E[i][v]) cout << i << " " << v << "\n";
	}
}












