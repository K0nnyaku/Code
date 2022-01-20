#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, v, x, y) for(int i = x.Head[y], v = x.T(i); i; i = x.Next[i], v = x.T(i))
#define ZR(x) memset(x, 0, sizeof x)

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

const int N_ = 1e6 + 2;
const int INF = 0x3f3f3f3f;

template<int N> 
struct Edge {
	int Next[N << 1], To[N << 1], Head[N];
	int cnt;
	void Add(int u, int v) {
		Next[++cnt] = Head[u]; To[cnt] = v; Head[u] = cnt; }
	int T(int x) {
		return To[x]; }
	Edge() {
		ZR(Next); ZR(To); ZR(Head);
		cnt = 1; }
};

Edge<N_> G;
int A[N_], F[N_][2];
int n, rt, ans;
bool Vis[N_];

int Dp(int x, bool opt) {
	F[x][0] = 0; Vis[x] = 1;

	int tmp = INF, p, q;
	ER(i, v, G, x) if(v != rt) 
		p = Dp(v, opt), q = F[v][0], 
		tmp = min(tmp, p - q), F[x][0] += p;

	if(x != A[rt] || !opt)	F[x][1] = F[x][0] - tmp + 1;
	else					F[x][1] = F[x][0] + 1;

	return max(F[x][0], F[x][1]);
}

int Work(int x) {
	for(rt = x; !Vis[A[rt]] && (Vis[rt] = 1); rt = A[rt]);
	int ans = Dp(rt, 0); Dp(rt, 1);
	return max(ans, F[rt][0]); 
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> A[i], G.Add(A[i], i);

	IR(i, 1, n) if(!Vis[i]) 
		ans += Work(i);
//		cout << ans << "\n";

	cout << ans << "\n";

	return 0;
} /**/




















