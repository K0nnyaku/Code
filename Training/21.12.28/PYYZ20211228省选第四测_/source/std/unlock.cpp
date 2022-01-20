/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=309;
int set[V], cnt[V];
int find(int x)
{
	if(x != set[x]) set[x] = find(set[x]);
	return set[x];
}
void U(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	set[fx] = fy;
}
double dp[V][V];
int _, n, x, K;
int main()
{

#ifndef ONLINE_JUDGE
   freopen("unlock.in", "r", stdin);
   freopen("unlock.out", "w", stdout);
#endif

	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d", &n, &K);
		for(int i = 1; i <= n; ++i) set[i] = i;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &x);
			U(x, i);
		}
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) cnt[find(i)]++;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1.0;
		for(int i = 0; i < n; ++i)
		{
			int size = cnt[i + 1];
			if(size == 0)
			{
				for(int j = 0; j <= K; ++j) dp[i + 1][j] = dp[i][j];
				continue;
			}
			for(int j = 0; j <= K; ++j)
			{
				double pro = 1.0;
				for(int k = 1; k <= size && j + k <= K; ++k)
				{
					pro /= (n - j + 1 - k);
					pro *= (K - j + 1 - k);
					pro /= k;
					pro *= (size - k + 1);
					dp[i + 1][j + k] += dp[i][j] * pro;
				}
			//	printf("i=%d,j=%d,dp=%.10f\n",i,j,dp[i][j]);
			}
		}
		printf("%.9f\n", dp[n][K]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
