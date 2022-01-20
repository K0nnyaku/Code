#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], b[N][2];
string ans;
int t, n, ret = -1;
bool is_hw(int a[][2])
{
	int l = 1, r = n;
	while (l <= r)
	{
		if (a[l][0] != a[r][0]) return false;
		l++, r--;
	}
	return true;
}
void dfs(int l, int r, int dep)
{
	if (dep == n+1)
	{
		if (is_hw(b))
		{
			string t;
			for (int i = 1; i <= n; i++)
			{
				if (b[i][1] == 1) t += 'L';
				else t += 'R';
			}
			if (ret == -1 || t < ans) ret = 1, ans = t;
		}
		return;
	}
	b[dep][0] = a[l], b[dep][1] = 1;
	dfs(l+1, r, dep+1);
	b[dep][0] = a[r], b[dep][1] = 2;
	dfs(l, r-1, dep+1); 
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		n *= 2;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		dfs(1, n, 1);
		if (ret == -1) printf("-1\n");
		else cout << ans << endl;
		ret = -1;
	}
	return 0;
}
