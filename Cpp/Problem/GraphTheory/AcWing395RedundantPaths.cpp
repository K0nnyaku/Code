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

const int N_ = 5e3 + 2;
const int E_ = 1e4 + 2;

template<int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

Edge<N_, E_> I;
int Fn[N_], Lw[N_], DccV[N_], In[N_];
int n, m, pos, cnt;
bool Bg[E_<<1], Vv[N_];

void Tarjan(int x, int elt) {
	Fn[x] = Lw[x] = ++pos;
	ER(i,v,I,x,I) if(i != (elt^1))
		if(!Fn[v]) 
			Tarjan(v, i), Lw[x] = min(Lw[x], Lw[v]), 
			Bg[i] = Bg[i^1] = (Bg[i] | Fn[x] < Lw[v]);
		else 
			Lw[x] = min(Lw[x], Fn[v]);
}

void Fdcc(int x) {
	Vv[x] = 1; DccV[x] = cnt;
	ER(i,v,I,x,I) if(!Vv[v] && !Bg[i]) Fdcc(v);
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		I.Ad(u, v); I.Ad(v, u);
	}

	IR(i, 1, n) if(!Fn[i]) Tarjan(i, 0);

	IR(i, 1, n) if(!Vv[i]) ++cnt, Fdcc(i);

	IR(i, 1, n) ER(k,v,I,i,I) 
		if(Bg[k]) In[DccV[i]]++, In[DccV[v]]++;

	int tmp = 0;
	IR(i, 1, cnt) tmp += In[i] == 2;

	cout << tmp / 2 + tmp % 2 << "\n";

	return 0;
} /**/










