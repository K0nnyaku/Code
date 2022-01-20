#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 1e9+7;
char s[N], t[N];
int n, k, ret;
bool is_khpp(char *s)
{
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (l < r) return false;
		if (s[i] == '(') l++;
		else if (s[i] == ')') r++;
	}
	return l == r;
}
bool is_xing_k(char *s)
{
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '*') x++;
		else
		{
			if (x > k) return false;
			x = 0;
		}
	}
	return x <= k;
}
bool lr_xing(char *s)
{
	return s[1] == '*' || s[n] == '*';
}
bool sas(char *s)
{
	for (int i = 2; i < n-1; i++)
	{
		if (s[i] == '(' && s[i+1] == ')')
		{
			if (s[i-1] == '*' && s[i+2] == '*') return false;
		}
	}
	return true;
}
void dfs(int dep)
{
	if (dep == n+1)
	{
		if (is_khpp(t) && is_xing_k(t))
		{
			if (!lr_xing(t) && sas(t))
			{
				ret++;
			}
		}
		return;
	}
	if (s[dep] == '(' || s[dep] == ')' || s[dep] == '*')
	{
		t[dep] = s[dep];
		dfs(dep+1);
	}
	else
	{
		t[dep] = '(';
		dfs(dep+1);
		t[dep] = ')';
		dfs(dep+1);
		t[dep] = '*';
		dfs(dep+1);
	}
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	int f = 0;
	for (int i = 1; i <= n; i++)
	{
		f += (s[i] == '?');
	}
	if (f == 0)
	{
		if (!is_khpp(s) || !is_xing_k(s) || lr_xing(s) || !sas(s))
		{
			printf("0");
			return 0;
		}
	}
	dfs(1);
	printf("%d", ret);
	return 0;
}
