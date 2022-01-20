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

const int N_ = 1e3 + 7;
const int M_ = 1e4 + 7;

vector<int> Ans, Cor;
int Mp[M_<<1];
int n, m, cnt;
bool Tg[M_], Vv[M_];
bool fg;

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T C[M];
	Edge()    { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void Cl() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void Add(int u, int v, T c, int pos) { Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c; Mp[cnt] = pos; }
};

Edge<int, N_, M_<<1> I;

void FdTg(int x);
bool Chk(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/grap/graph10.in",  "r", stdin);
	freopen("I:/Code/Data/grap/graph10.out", "w", stdout);
//	freopen("I:/Code/Data/In.in", "r", stdin);
//	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, m) {
		int u, v, w; IN >> u >> v >> w;
		I.Add(u, v, w, i); I.Add(v, u, w, i);
		Cor.push_back(w);
	}

		cout << m << "\n";
		IR(i, 1, m) cout << i << "\n";

	return 0;
	sort(Cor.begin(), Cor.end());
	cnt = unique(Cor.begin(), Cor.end()) - Cor.begin();
	
	int l = 0, r = cnt;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(Chk(mid)) l = mid;
		else         r = mid - 1;
	}

	if(l == 0) {
		cout << m << "\n";
		IR(i, 1, m) cout << i << "\n";
		return 0;
	}

	Chk(l);

	sort(Ans.begin(), Ans.end());
	int tmp = unique(Ans.begin(), Ans.end()) - Ans.begin();

	cout << tmp << "\n";

	Ir(i, 0, tmp)
		cout << Ans[i] << "\n";

	return 0;
} /**/

bool Chk(int x) {
	if(!x) return 1;

	Ans.clear(); FL(Vv, 0);
	FL(Tg, 0); fg = 0; FdTg(x);

	return fg;	
}

void FdTg(int x) {
	if(fg) return ;

	if(!x) {
		queue<int> Q; Q.push(1);
		FL(Vv, 0);    Vv[1] = 1;
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			ER(i,v,I,x,I) 
				if(!Vv[v] && (!Tg[I.C[i]]) && (Vv[v]=1)) 
					Q.push(v), Ans.push_back(Mp[i]);
		}
		IR(i, 1, n) 
			if(!Vv[i]) { Ans.clear(); FL(Vv, 0); return; }
		fg = 1;
		return ;
	}

	Ir(i, 0, cnt) {
		if(fg) return ;
		if(!Tg[Cor[i]])
			Tg[Cor[i]] = 1, FdTg(x-1), Tg[Cor[i]] = 0;
	}
}










