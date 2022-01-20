// 无输出，但没时间调了 
#include <iostream>
#include <memory.h>
#include <algorithm>
#define x(p) ((p) / 1000)
#define y(p) ((p) % 1000)
using namespace std;
typedef unsigned long long ull;
const int maxn = 500 + 6;
int n, m, t, k, c[501501 + 1000 + 6], cnt;	// 501501 > 5e5
struct point { int x, y; };
struct edge { int w, u, v; } e[maxn * maxn], e2[maxn * maxn];
bool operator<(const edge &e1, const edge &e2) { return e1.w > e2.w; }
inline int getHash(int x, int y) { return x * 1000 + y; }
ull ans;

void dfs(int, int);

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);	cout.tie(0);
//	不注释掉会 RE，为啥呢
	cin >> n >> m >> t;
	for (int i = 1;i < n;i++)
		for (int k = 1;k <= m;k++)
		{
			cin >> e2[++cnt].w;
			e2[cnt].u = getHash(i, k);
			e2[cnt].v = getHash(i + 1, k);
		}
	for (int i = 1;i <= n;i++)
		for (int k = 1;k < m;k++)
		{
			cin >> e2[++cnt].w;
			e2[cnt].u = getHash(i, k);
			e2[cnt].v = getHash(i, k + 1);
		}
	int row, col, id, color, p, v;
	while (t--)
	{
		cin >> k;
		memcpy(e, e2, sizeof (edge) * (cnt + 1));
		memset(c, -1, sizeof c);
		ans = 0XFFFFFFFFFFFFFFFF;
		p = 0;
		for (int i = 1;i <= k;i++)
		{
			cin >> e[cnt + i].w >> id >> color;
			if (id <= m)
				row = 1, col = id,
				v = getHash(0, col);
			else if (id <= m + n)
				row = id - m, col = m,
				v = getHash(row, m + 1);
			else if (id <= 2 * m + n)
				row = n, col = n + 2 * m + 1 - id,
				v = getHash(n + 1, col);
			else
				row = 2 * m + 2 * n + 1 - id, col = 1,
				v = getHash(row, 0);
			e[cnt + i].u = getHash(row, col);
			e[cnt + i].v = v;
			c[v] = color;
		}
		sort(e + 1, e + cnt + k + 1);		// 但是贪心策略我不能证明是正确的，我也不知道是不是正确的 
		if (c[e[1].u] != -1)	p++;
		if (c[e[1].v] != -1)	p++;
		dfs(1, p);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int i, int p)
{
#define u e[i].u
#define v e[i].v
#define w e[i].w

	if (p == n * m + k)
	{
		ull t = 0;
		for (int i = 1;i <= cnt + k;i++)
			if (c[u] != c[v])
				t += w;
		ans = min(t, ans);
		return;
	}
	if (c[v] == -1 && c[u] != -1)
		c[v] = c[u] ^ 1, dfs(i + 1, p + 1);
	else if (c[u] == -1 && c[v] != -1)
		c[u] = c[v] ^ 1, dfs(i + 1, p + 1);
	else if (c[u] == -1 && c[v] == -1)
	{
		c[u] = 1, c[v] = 0, dfs(i + 1, p + 2);
		c[u] = 0, c[v] = 1, dfs(i + 1, p + 2); 
	}
	else
		dfs(i + 1, p);
	return;
}




























