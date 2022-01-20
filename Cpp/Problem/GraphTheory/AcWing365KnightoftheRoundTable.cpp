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

const int N_ = 1e3 + 2;
const int M_ = 1e6 + 2; 
const int INF = 0x3f3f3f3f;

template<typename T, int N>
struct Stack {
	T A[N];
	int cnt, tp;

	Stack() { FL(A, 0); cnt = 0; tp = 1; }

	T Tp() { return A[tp]; }
	int Num() { return cnt; }
	void Pp() { tp--; cnt--; }
	void Ph(const T &x) { A[++tp] = x; cnt++; }
	void Cl() { FL(A, 0); cnt = 0; tp = 0; }
};

template<int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Hd[N];
	int cnt;

	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }

	void Add(int u, int v) { Nt[++cnt] = Hd[u]; To[Hd[u] = cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); cnt = 1; }
};

Stack<int, N_> Sk;
Edge<N_, M_> G;
vector<int> Dcc[N_];
int Dfn[N_], Low[N_], Cl[N_];
int n, m, cnt;
bool Ve[N_][N_], Vv[N_], Vc[N_][N_], Vl[N_], Ct[N_], Fg[N_];

void Tarjan(int x, int y, int rt);
void Pre(int x, int pos, bool clo);


int main() { 
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	while(n + m) {
		FL(Dfn, 0);  FL(Low, 0); FL(Ct, 0); FL(Cl, 0x3f);
		FL(Ve, 0);   FL(Vv, 0);  FL(Vc, 0); FL(Vl, 0); FL(Fg, 0);
		G.Cl();

		IR(i, 1, m) { int u, v; IN >> u >> v;  Ve[u][v] = 1; Ve[v][u] = 1; }

		IR(i, 1, n) IR(v, i+1, n) if(!Ve[i][v]) 
			G.Add(i, v), G.Add(v, i);

		IR(i, 1, n) if(!Vv[i]) 
			Tarjan(i, 1, i), Sk.Cl();

#ifdef Debug
		IR(i, 1, cnt) {
			cout << "\n=======================\n";
			Ir(v, 0, Dcc[i].size()) 
				cout << Dcc[i][v] << " ";
			cout << "\n=======================\n";
		}
#endif

		IR(i, 1, cnt) 
			Pre(Dcc[i][0], i, 0), FL(Cl, 0x3f);

		IR(i, 1, cnt) if(Fg[i]) 
			Ir(v, 0, Dcc[i].size()) Vl[Dcc[i][v]] = 1;

		int ans = 0;
		IR(i, 1, n) 
			ans += !Vl[i];

		cout << ans << "\n";

		IN >> n >> m;
	}


	return 0;
} 

void Tarjan(int x, int pos, int rt) {
	Dfn[x] = Low[x] = pos; 	
	Vv[x] = 1;
	
	Sk.Ph(x);
	int tot = 0;
	ER(i, v, G, x) 
		if(!Dfn[v]) {
			Tarjan(v, pos+1, rt);
			Low[x] = min(Low[x], Low[v]);

			if(Low[v] >= Dfn[x]) {
				Ct[x] = ++tot > 1 || x != rt;

				cnt++;
				while(Sk.Num() && Sk.Tp() != v) 
					Vc[cnt][Sk.Tp()] = 1, 
					Dcc[cnt].push_back(Sk.Tp()), 
					Sk.Pp(); 

				if(Sk.Num()) 
					Vc[cnt][Sk.Tp()] = 1, 
					Dcc[cnt].push_back(Sk.Tp()), 
					Sk.Pp();

				Vc[cnt][x] = 1; Dcc[cnt].push_back(x);
			}

		}
		else Low[x] = min(Low[x], Dfn[v]);
}

void Pre(int x, int pos, bool clo) {
	if(Fg[pos]) return ;

	Cl[x] = clo;
	ER(i, v, G, x) if(Vc[pos][v]) 
		if(Cl[v] == INF) Pre(v, pos, clo^1);
		else if(Cl[v] == clo) { Fg[pos] = 1; return ; }
}






















