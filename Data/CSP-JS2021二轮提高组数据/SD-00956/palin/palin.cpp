#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e5 + 10;
int t, n, b[maxn], cnt, a[maxn], c[maxn];
bool dfs(int nowl, int nowr)
{
	if (cnt == 2 * n)
	{
		for (int i = 1; i <= n; ++i)
			if (c[i] != c[2 * n - i + 1])
				return false;
		return true;
	}
	++cnt;
	b[cnt] = 0, c[cnt] = a[nowl];
	if (dfs(nowl + 1, nowr))
		return true;
	b[cnt] = 1, c[cnt] = a[nowr];
	if (dfs(nowl, nowr - 1))
		return true;
	--cnt;
	return false;
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= 2 * n; ++i)
			scanf("%d", &a[i]);
		if (dfs(1, 2 * n))
		{
			for (int i = 1; i <= 2 * n; ++i)
				if (b[i])
					printf("R");
				else
					printf("L");
			for (int i = 1; i <= 2 * n; ++i)
				printf("%d ", c[i]);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}
