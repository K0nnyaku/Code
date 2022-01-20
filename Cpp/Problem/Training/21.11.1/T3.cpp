#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

struct Node {
	int x, y, val;
	Node(int x_ = 0, int y_ = 0, int val_ = 0) {
		x = x_, y = y_, val = val_; 
	}
	friend bool operator<(Node x, Node y) {
		return x.val < y.val;
	}
}P[N_*N_];

int Mp[N_][N_], Way[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} }, Pos[N_][N_];
int n, m, cnt, ans;
bool Vis[N_*N_];

struct UF {
	int fa, mk;
	UF(int fa_ = 0, int mk_ = 0) {
		fa = fa_, mk = mk_;
	}
} Fa[N_];
int FindFa(int x);
int Abs(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IR(v, 1, m)
		IN >> Mp[i][v], P[++cnt] = Node(i, v, Abs(Mp[i][v])), Pos[i][v] = ++cnt;

	sort(P+1, P+cnt+1);

	IR(i, 1, cnt) Fa[i] = UF(i, 0);

	IR(i, 1, cnt) {
		do Ir(v, 0, 4) {
			int xw = Way[v][0] + P[i].x, yw = Way[v][1] + P[i].y;
			if(xw > n || xw <= 0 || yw > m || yw <= 0) continue;

			int pfa = FindFa(Pos[P[i].x][P[i].y]), mfa = FindFa(Pos[xw][yw]);
			if(Abs(Mp[xw][yw]) <= P[i].val) 
				Fa[pfa] = UF(mfa, Fa[pfa].mk | Fa[mfa].mk);

		} while(P[i].val == P[++i].val);

		i--;
		if(Mp[P[i].x][P[i].y] <= 0) continue;
		int pfa = FindFa(Pos[P[i].x][P[i].y]);
		if(!Fa[pfa].mk) 
			ans++, Fa[pfa].mk = 1;
//			printf("i = %d, x = %d, y = %d\n", i, P[i].x, P[i].y);
	}
	
	cout << ans << "\n";

	return 0;
} /**/

int Abs(int x) {
	return x < 0 ? -x : x;
}

int FindFa(int x) {
	return Fa[x].fa = Fa[x].fa == x ? x : FindFa(Fa[x].fa);
}





















