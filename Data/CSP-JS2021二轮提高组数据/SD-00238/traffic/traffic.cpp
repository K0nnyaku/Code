#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 510;
const int K = 55;
const ll INF = 1e18;
int n, m, t;
int a[N][N], b[N][N], color[N][N];
int k[K], val[K][K], id[K][K], col[K][K];
ll ans[K];

template<typename T> inline void read(T &s)
{
	s = 0; bool f = false; char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = (s << 3) + (s << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) s = ~s + 1;
	return;
}

template<typename T> inline void print(T x)
{
	int s[21], top = 0;
	if (x < 0) putchar('-'), x = ~x + 1;
	while (x) s[++top] = x % 10, x /= 10;
	if (!top) s[++top] = 0;
	while (top) putchar(s[top--] + '0');
	return;
}

int work(int i, int j, int x)
{
	if (x <= m) return col[i][j] != color[1][x] ? val[i][j] : 0;
	if (x <= m + n) return col[i][j] != color[x - m][m] ? val[i][j] : 0;
	if (x <= 2 * m + n) return col[i][j] != color[n][m - (x - m - n) + 1] ? val[i][j] : 0;
	return col[i][j] != color[n - (x - 2 * m - n) + 1][1] ? val[i][j] : 0;
}

void check()
{
	ll Ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (i + 1 <= n && color[i][j] != color[i + 1][j]) Ans += a[i][j];
			if (j + 1 <= m && color[i][j] != color[i][j + 1]) Ans += b[i][j];
		}
	for (int i = 1; i <= t; i++)
	{
		if (ans[i] == 0) continue;
		ll tmp = 0;
		for (int j = 1; j <= k[i]; j++)
			tmp += work(i, j, id[i][j]);
		ans[i] = min(ans[i], Ans + tmp);
	}
	return;
}

void dfs(int x, int y)
{
	if (y == m + 1) { dfs(x + 1, 1); return; }
	if (x == n + 1) { check(); return; }
	color[x][y] = 0; dfs(x, y + 1);
	color[x][y] = 1; dfs(x, y + 1);
	return;
}

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	read(n), read(m), read(t);
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++) read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++) read(b[i][j]);
	for (int i = 1; i <= t; i++) ans[i] = INF;
	for (int i = 1; i <= t; i++)
	{
		read(k[i]);
		for (int j = 1; j <= k[i]; j++)
			read(val[i][j]), read(id[i][j]), read(col[i][j]);
		if (k[i] == 1) ans[i] = 0;
	}
	dfs(1, 1);
	for (int i = 1; i <= t; i++) print(ans[i]), putchar('\n');
	return 0;
}
