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

const int _N = 20 + 10;
const int _L = 20 + 10;

long long Len[_N], F[_N][_L], P[_N], Vis[_N];
long long n, idx, ans;

long long Calc();
bool Check();
void Dfs(int pos);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#else
	freopen("bullcow.in", "r", stdin);
	freopen("bullcow.out", "w", stdout);
#endif
	IN >> n; 
	char clo = getchar();
	while(clo != 'Q') {
		int x; IN >> x;
		Len[++idx] = x;
		clo = getchar();
	}

	if(idx >= 11) {
		Dfs(1);
		cout << ans << '\n';
		return 0;
	}

	IR(i, 1, idx) P[i] = i;
	do {
		ans += Calc();
	}while(next_permutation(P+1, P+idx+1));

	cout << ans << '\n';

	return 0;
} /**/

long long Calc() {
	memset(F, 0, sizeof F);

	IR(i, 0, n) 
		if(i + Len[P[1]] <= n) F[1][i + Len[P[1]]] = 1;

	IR(i, 1, idx-1) IR(v, 0, n) IR(k, 1, n) 
		if(v + Len[P[i+1]] + k <= n) 
			F[i+1][v + Len[P[i+1]] + k] += F[i][v];
		else break;

	long long res = 0;
	IR(i, 1, n) 
		res += F[idx][i];
	
	return res;
}

void Dfs(int pos) {
	if(pos > n) {
		ans += Check();
		return ;
	}

	IR(i, 1, idx) {
		if(!Vis[i] && pos + Len[i] - 1 <= n) 
			Vis[i] = 1, 
			Dfs(pos + Len[i] + 1),
			Vis[i] = 0;
	}
	Dfs(pos+1);
}

bool Check() {
	IR(i, 1, idx) if(!Vis[i]) return false;
	return true;
}











