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

const int N_ = 5e5 + 2;
const int E_ = 1e6 + 2;

template<int N, int E>
struct Edge {
	int Nt[E<<1], To[E<<1], I[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
};

Edge<N_<<1, E_> I, S;
stack<int> Sk;
int Fn[N_], Lw[N_], Dep[N_<<1], F[N_<<1][22];
int n, m, pos, tot, rt, q;

void Tarjan(int x);
void Pre(int x, int vlt);
void Dp();
int Lca(int x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	rt = 1;

	I.Cl(); S.Cl(); 

	FL(Fn, 0);  FL(Lw, 0);
	FL(Dep, 0); FL(F, 0); 

	tot = n;

	while(Sk.size()) Sk.pop();

	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		I.Ad(u, v); I.Ad(v, u);
	}

	Tarjan(1);

	Dep[1] = 1; 
	Pre(1, 0);
	Dp();

	IN >> q;
	while(q--) {
		int s, t; IN >> s >> t;
		int z = Lca(s, t);
//		printf("s = %d, t = %d, dep s = %d, dep t = %d, lca = %d, dep lca = %d\n", 
//				s, t, Dep[s], Dep[t], z, Dep[z]);

		cout << (Dep[s] + Dep[t] - 2 * Dep[z]) / 2 + 1 << "\n";
	}

	return 0;
} /**/

void Tarjan(int x) {
	Sk.push(x);
	Fn[x] = Lw[x] = ++pos;

	ER(i,v,I,x,I) 
		if(!Fn[v]) {
			Tarjan(v), Lw[x] = min(Lw[x], Lw[v]);
			if(Lw[v] == Fn[x] && ++tot) {
				int y = Sk.top();
					do {
					Sk.pop(); 
					S.Ad(tot, y); S.Ad(y, tot);
				} while(y != v && (y = Sk.top()));
				S.Ad(x, tot); S.Ad(tot, x);
			}
		}
		else Lw[x] = min(Lw[x], Fn[v]);
}

void Pre(int x, int vlt) {
	ER(i,v,S,x,I) if(v != vlt)
		Dep[v] = Dep[x] + 1, F[v][0] = x, Pre(v, x);
}

void Dp() {
	Ir(e, 1, 20) IR(i, 1, tot) 
		F[i][e] = F[F[i][e-1]][e-1];
}

int Lca(int x, int y) {
	if(Dep[x] < Dep[y]) swap(x, y);
	SR(i, 20, 0) if(Dep[F[x][i]] >= Dep[y]) x = F[x][i];
	if(x == y) return x;

	SR(i, 20, 0) if(F[x][i] != F[y][i])
		x = F[x][i], y = F[y][i];

	return F[x][0];
}








