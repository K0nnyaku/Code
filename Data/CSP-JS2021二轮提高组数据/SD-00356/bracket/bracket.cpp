#include <bits/stdc++.h>
#include <cstdio>

const int maxn = 505;

#define DEBUG printf("NONONO")

int n, k, num, ans, siz, masiz, sum;
int a[maxn], next[maxn], sum[maxn];
std::string ch;

void dfs(int dep)
{
	if(dep > num)
	{
		siz = masiz = 0;
		for(int i = 1; i <= n; ++i) sum[i] = 0; 
		for(int i = 1; i <= n; ++i)
		{
			if(a[i] == 0) siz++;
			else masiz = std::max(masiz, siz);
			sum[i] = a[i] + sum[i - 1];
			if(sum[i] > 0 || masiz > k) return;
		}
		if(sum[n] == 0 && masiz <= k && a[1] && a[n])
		{
			int ppt = 0;
		for(int i = 1; i < n - 1; ++i)
		{
			for(int j = i + 1; j <= n; ++j)
			{
				if(j + 2 > n) break;
				if(sum[j] - sum[i - 1] == 0 && !a[j + 1] && !a[i - 1] && a[j + 2] == 1 && a[i - 2] == -1) ppt++;
			}
		}
		if(ppt) ans += 0;
		else ans ++;
		}
		return;
	}
	a[next[dep]] = -1;
	dfs(dep + 1);
	a[next[dep]] = 0;
	dfs(dep + 1);
	a[next[dep]] = 1;
	dfs(dep + 1);
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	std::cin >> n >> k >> ch;
	for(int i = 1; i <= n; ++i)
	{
		if(ch[i - 1] == '(') a[i] = -1;
		if(ch[i - 1] == '?')
		{
			next[++num] = i;
		}
		if(ch[i - 1] == ')') a[i] = 1;
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
