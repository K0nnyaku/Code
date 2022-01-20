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

const int N_ = 50 + 2;

template<int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
};

Edge<N_*N_, N_*N_<<1> I;
int Mp[N_][N_], Ada[N_*N_], X[N_*N_], Y[N_*N_];
int t, n, m, xct, yct, idx;
bool Vv[N_*N_];

int H(int x, int y);
bool Aug(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		I.Cl();    xct = 0;    yct = 0;
		FL(Mp, 0); FL(Ada, 0); FL(X, 0); FL(Y, 0);

		IN >> n >> m;
		IR(i, 1, n) {
			IR(v, 1, m) {
				char ch = getchar();
				if(ch == '#') Mp[i][v] = 0;
				else if(ch == '*') Mp[i][v] = 1;
				else Mp[i][v] = 2;
			}
			getchar();
		}

		IR(i, 1, n) IR(v, 1, m) 
			X[H(i, v)] = Mp[i][v] && Mp[i][v-1] ? xct : xct+=Mp[i][v]!=0;

		IR(v, 1, m) IR(i, 1, n) 
			Y[H(i, v)] = Mp[i][v] && Mp[i-1][v] ? yct : yct+=Mp[i][v]!=0;

		IR(i, 1, n) IR(v, 1, m) 
			if(Mp[i][v] == 2) I.Ad(X[H(i, v)], Y[H(i, v)] + xct);

		int ans = 0;
		IR(i, 1, xct) 
			FL(Vv, 0), ans += Aug(i);

		cout << "Case :" << ++idx << "\n";
		cout << ans << "\n";
	}

	return 0;
} /**/

int H(int x, int y) { return (x - 1) * m + y; }

bool Aug(int x) {
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1) && (!Ada[v] || Aug(Ada[v])))
		return Ada[v] = x;
	return 0;
}




