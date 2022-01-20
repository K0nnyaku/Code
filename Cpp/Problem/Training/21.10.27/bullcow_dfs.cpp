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

long long Len[_N], F[_N][_L];
long long n, idx, ans;
bool Vis[_N];

bool Check();
void Dfs(int pos);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\WA.out", "w", stdout);
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

	Dfs(1);

	cout << ans << "\n";

	return 0;
} /**/

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









