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

const int N_ = 8e3 + 7;

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

Edge<N_, N_<<1> I;
int Col[N_], Sz[N_], Fa[N_];
int n, q, cnt;

void MkFa(int x, int last);
void MkSz(int x, int last);
void Chg(int x);
int AskLink(int x);
int AskSon(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("color.in",  "r", stdin);
	freopen("color.out", "w", stdout);
#endif
	IN >> n;
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		I.Add(u, v); I.Add(v, u);
		Col[i] = i;
	}
	cnt = n;

	MkFa(0, 0);
	MkSz(0, 0);

	IN >> q;
	while(q--) {
		char opt; opt = getchar();
		int u;	  IN >> u;

		if(opt == 'q') 
			printf("%.10lf\n", (double)(AskSon(u, Fa[u]) +  AskLink(u)) / Sz[u] );
		else 
			cnt++, Chg(u);
	}

	return 0;
} /**/

void MkFa(int x, int last) {
	Fa[x] = last;
	ER(i,v,I,x,I) if(v != last) MkFa(v, x);
}

void Chg(int x) {
	do {
		Col[x] = cnt;
		x = Fa[x];
	} while(x);
	Col[0] = cnt;
}

int AskSon(int x, int last) {
	int res = 0;
	ER(i,v,I,x,I) if(v != last)
		res += AskSon(v, x) + Sz[v] * (Col[x] != Col[v]);
	return res;
}

int AskLink(int x) {
	int res = 0, y = x;
	do {
		res += Sz[x] * (Col[y] != Col[Fa[y]]);
		y = Fa[y];
	} while(y);

	return res;
}

void MkSz(int x, int last) {
	Sz[x] = 1;
	ER(i,v,I,x,I) if(v != last) 
		MkSz(v, x), Sz[x] += Sz[v];
}







