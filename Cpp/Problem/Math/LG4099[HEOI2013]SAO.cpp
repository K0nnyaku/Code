#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 1e3 + 10;
const int P = 1e9 + 7;

struct Edge {
	int next, to, val;
	Edge(int _next = 0, int _to = 0, int _val = 0) {
		next = _next; to = _to; val = _val;
	}
} E[MAXN];

int Head[MAXN];
int cnt;

void Add(int from, int _to, int _val) {
	E[++cnt] = Edge(Head[from], _to, _val);
	Head[from] = cnt;
}

#define V(x) E[x].val
#define T(x) E[x].to

long long Size[MAXN], Tem[MAXN], Ie[MAXN], Fac[MAXN], F[MAXN][MAXN];
int T; 

void Init();
void Pre();
void Dp(int x, int last);
long long Qp(long long x, long long e);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
//	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	Pre();

	IN >> T;
	while(T--) {
		Init(); int n;
		IN >> n; int _n = n;
		while(--_n) {
			int u, v; char way;
			IN >> u; u++;
			way = getchar();
			IN >> v; v++;

			Add(u, v, (way == '<'));
			Add(v, u, (way == '>'));
		}

		Dp(1, 0);
		long long ans = 0;
		IOR(i, 1, n+1) ans += F[1][i] % P;
		ans %= P;
		cout << ans * Fac[n] % P << "\n";
	}

	return 0;
} /**/

void Init() {
	cnt = 0;
	IOR(i, 0, MAXN) E[i] = { 0, 0, 0 };
	IOR(i, 0, MAXN) Head[i] = 0;
	memset(Size, 0, sizeof Size);
	memset(F, 0, sizeof F);
}

void Dp(int x, int last) {
	Size[x] = 1;
	F[x][1] = 1;

	EOR(i, x) {
		if(T(i) == last) continue;

		Dp(T(i), x);
		Size[x] += Size[T(i)];

		memset(Tem, 0, sizeof Tem);

		if(V(x)) {
			LOR(v, Size[x], 0) IOR(k, 1, min((long long)v-1, Size[T(i)]) + 1)
//				Tem[v] += F[x][v-k] * F[T(i)][k] * (v - k) * Ie[v];
				Tem[v] = ( Tem[v] % P + 
					F[x][v-k] * F[T(i)][k] % P * (v-k) * Ie[v] % P) % P;
//				cout << " v = " << v << " Ie = " << Ie[v] << "\n";
		}
		else {
			LOR(v, Size[x] - Size[T(i)], 0) IOR(k, 1, Size[v] + 1)
//				Tem[v] += F[x][v] * F[v][k];
				Tem[v] = ( Tem[v] % P +
					F[x][v] * F[T(i)][k] % P) % P;	

			LOR(v, Size[x], 0) IOR(k, 1, min((long long)v-1, Size[T(i)]) + 1)
//				Tem[v] -= F[x][v-k] * F[T(i)][k] * (v - k) * Ie[v];
				Tem[v] = ( Tem[v] % P +
					F[x][v-k] * F[T(i)][k] % P * (v-k) * Ie[v] % P) % P;
		}

		IOR(v, 1, Size[x]) F[x][v] = Tem[v];
	}
}

void Pre() {
	long long x = 1;
	Fac[0] = Ie[0] = 1;
	IOR(i, 1, MAXN) 
		Ie[i] = Qp(i, P-2),
		Fac[i] = Fac[i-1] * i;
}

long long Qp(long long x, long long e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = res * x % P;
		x = x * x % P; e >>= 1;
	}
	return res % P;
}

















