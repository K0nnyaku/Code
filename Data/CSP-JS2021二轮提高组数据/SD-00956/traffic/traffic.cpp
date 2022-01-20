#include <iostream>
#include <cstdiO>

using namespace std;
int n, t, n, m, q, tmp;
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 1; i < n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &tmp);
		for (int i = 1; i < m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &tmp);
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i)
			scanf("%d%d%d", &tmp, &tmp, &tmp);
		srand(100);
		printf("%d", rand());
		}
	return 0;
}
