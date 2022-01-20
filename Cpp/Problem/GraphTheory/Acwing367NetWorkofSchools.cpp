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
const int M_ = 5e6 + 2;

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N];
	int cnt;

	Edge() { FL(Nt, 0); FL(To, 0); FL(To, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
};

template<typename T, int N>
struct Stack {
	T A[N]; int num, tp;
	Stack() { FL(A, 0); num = tp = 0; }

	T Tp() { return A[tp]; }
	void Ph(const T &x) { A[num = ++tp] = x; }
	void Pp() { num = --tp; }
	void Cl() { FL(A, 0); num = tp = 0; }
};

Stack<int, N_> Sk;
Edge<N_, M_> G;
int Mc[N_], Low[N_], Dfn[N_], In[N_], Out[N_];
int n, m, cnt, pos;
bool Vsk[N_];

void Tarjan(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;

	IR(i, 1, n) {
		int v; IN >> v;
		while(v) { G.Add(i, v); IN >> v; }
	}

	IR(i, 1, n) if(!Mc[i])
		Tarjan(i), Sk.Cl();

	IR(i, 1, n) ER(k, v, G, i) if(Mc[i] != Mc[v]) 
		In[Mc[v]]++, Out[Mc[i]]++;

	if(cnt == 1) { cout << "1\n0"; return 0; }

	int ans = 0, tmp = 0;

	IR(i, 1, cnt) ans += !In[i];
	cout << ans << "\n";

	IR(i, 1, cnt) tmp += !Out[i]; 
	cout << max(ans, tmp) << "\n";

	return 0;
} /**/

void Tarjan(int x) {
	Low[x] = Dfn[x] = ++pos;
	Sk.Ph(x); Vsk[x] = 1;

	ER(i, v, G, x) 
		if(!Dfn[v])		Tarjan(v), Low[x] = min(Low[x], Low[v]);
		else if(Vsk[v])			   Low[x] = min(Low[x], Dfn[v]);

	if(Low[x] == Dfn[x]) {
		cnt++;
		while(Sk.Tp() != x) 
			Mc[Sk.Tp()] = cnt, Vsk[Sk.Tp()] = 0, Sk.Pp();
		Mc[x] = cnt, Vsk[x] = 0, Sk.Pp(); 	
	}
}



















