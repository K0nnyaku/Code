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
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int N_ = 13 + 2;
const int C_ = 1 << N_;

struct Node {
	long long mx, sum;
	Node(long long mx_ = 0, long long sum_ = 0) {
		mx = mx_; sum = sum_;
	}
	friend bool operator<(const Node &x, const Node &y) {
		return x.mx < y.mx;
	}
}F[C_][N_][N_];

int long W[N_];
int n, m;
bool E[N_][N_];

long long Calc(int p, int k, int v);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IN >> W[i];
	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		E[u][v] = E[v][u] = 1;
	}

	IR(i, 0, n) 
		E[i][0] = E[0][i] = 1, E[i][i] = 1;

	IR(i, 1, n) 
		F[(1 << i) | 1][i][0] = Node(0, 1);

	Ir(i, 1, 1 << n+1) IR(v, 0, n) IR(k, 0, n) {
		if(k == v || !E[v][k]) continue;
		if(!(i & 1 << v) || !(i & 1 << k)) continue;

		IR(p, 0, n) if(p != v && p != k) {
			if(!(i & 1 << p)) continue;
			if(!E[k][p]) continue;

			Node tmp = F[i ^ 1 << v][k][p];
			tmp.mx += Calc(p, k, v);

			if(F[i][v][k] < tmp) F[i][v][k] = tmp;
			else if(F[i][v][k].mx == tmp.mx) F[i][v][k].sum += tmp.sum;
		}
	}

	Node ans = Node(0, 1);
	IR(v, 0, n+1) IR(k, 0, n+1) {
		if(k == v || !E[v][k]) continue;
		Node tmp = F[(1 << n+1)-1][v][k];

		if(ans < tmp) ans = tmp;
		else if(tmp.mx == ans.mx) ans.sum += tmp.sum;
	}

	cout << ans.mx << "\n" << ans.sum / 2 << "\n";

	return 0;
} /**/

long long Calc(int p, int k, int v) {
	return W[v] + 
				  W[v] * W[k] + 
								W[p] * W[k] * W[v] * E[p][v];
}















