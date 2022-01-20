#include <cstdio>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 5e5 + 6;
const int inf = 0X7FFFFFFF;

int t, n, a[maxn * 2], b[maxn * 2];
char op[maxn * 2];
string ans, tmp;

void dfs(int l, int r, int idx);

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	if (t == 1)
	{
		scanf("%d", &n);
		if (n <= 100)
			goto there;
		for (int i = 1;i <= n;i += 2)
			if (a[i] != a[2 * n - i + 1])
			{
				puts("-1");
				return 0;
			}
		for (int i = 1;i <= n;i++)
			printf("LL");
		puts("");
		return 0;
	}
there:
	while (t--)
	{
		scanf("%d", &n);
		ans = "";
		for (int i = 1;i <= 2 * n;i++)
			scanf("%d", a + i);
		dfs(1, 2 * n, 1);
		printf("%s\n", ans == "" ? "-1" : ans.data());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int l, int r, int idx)
{
	if (l == r)		// 如果不是回文串，不会搜到这种状态 
	{
	}
	if (idx == 2 * n)
	{
		if (a[l] != b[1])
			return;
		op[idx] = 'L';
		tmp = string(op + 1);
		if (ans == "")
			ans = tmp;
		else
			ans = ans < tmp ? ans : tmp;
		return;
	}
	if (idx > n)
	{
		if (a[l] == b[2 * n - idx + 1])
			b[idx] = a[l], op[idx] = 'L', dfs(l + 1, r, idx + 1);
		else if (a[r] == b[2 * n - idx + 1])
			b[idx] = a[r], op[idx] = 'R', dfs(l, r - 1, idx + 1);
		return;
	}
	b[idx] = a[l], op[idx] = 'L', dfs(l + 1, r, idx + 1);
	b[idx] = a[r], op[idx] = 'R', dfs(l, r - 1, idx + 1);
	return;
}






























