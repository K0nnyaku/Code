#include <cstdio>

const int maxn = 5e5 + 5;

int t, n;
int a[maxn << 1];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; ++i)
		{
			scanf("%d", &a[i]);
		}
	}
	return 0;
}
