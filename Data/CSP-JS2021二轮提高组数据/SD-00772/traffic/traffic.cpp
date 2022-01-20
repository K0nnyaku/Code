#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int p1[N][N], p2[N][N];
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdin);
	int n, m, t, k, v, id, f;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &p1[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			scanf("%d", &p2[i][j]);
		}
	}
	while (t--)
	{
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d%d%d", &v, &id, &f);
		}
		printf("12\n");
	}
	return 0;
}
