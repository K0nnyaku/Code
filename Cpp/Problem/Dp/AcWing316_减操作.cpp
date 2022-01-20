#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _N = 1e2 + 10;

int A[_N], F[_N], Way[_N][_N];
int n, m, sum;
bool Vis[_N];

void Mk(int pos, int res);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IN >> A[i], sum += A[i] * (i > 2);
	m = (sum + m - A[1] + A[2]) / 2;
	cout << m << "\n";

	F[0] = 1;
	IR(i, 3, n) SR(v, m, 1) {
		if(v == m) 
			SR(k, m, 0) Way[i][k] = Way[i-1][k];

		if(!F[v] && F[v-A[i]]) 
			F[v] = 1, Way[i][v] = i;
	}

	Mk(n, m);

	int cnt = 0;
	SR(i, n, 1) if(Vis[i])
		cout << i << " ",
		cnt++;

	cnt = n - cnt;
	IR(i, 1, n) if(!Vis[i])
		cout << --cnt << " ";

	return 0;
} /**/

void Mk(int pos, int res) {
	int tmp = Way[pos][res];
	if(!tmp) return ;
	Vis[tmp] = 1;
	Mk(tmp, res-A[tmp]);
}














