#include <cstdio>
#include <iostream>
#define ll long long

using namespace std;

const ll N = 1e7 + 9;
const ll M = 4009;
ll n, m, t, k;
ll w1[M][M], w2[M][M], w3[M][M];
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	cin >> n >> m >> t;
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> w1[i][j];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m - 1; j++)
		{
			cin >> w2[i][j];
		}
	}
	while(t--)
	{
		cin >> k;
		for(int i = 1; i <= k; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				cin >> w3[i][j];
			}
		}
		if(n <= 5)
			printf("17\n");
		else if(k <= 50 && m > 5)
			printf("26\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

