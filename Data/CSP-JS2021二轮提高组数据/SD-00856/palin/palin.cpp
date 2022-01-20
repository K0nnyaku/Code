#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define rep(_, __, ___) for (int _ = __; _ <= ___; ++_) 

const int maxn = 5e5 + 5;

inline lint readInt()
{
	int fx = 1, xx = 0;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			fx = -1;
		ch = getchar();
	}
	while (isdigit(ch))
		xx *= 10, xx += ch - 48, ch = getchar();
	return fx * xx; 
}

int n; 
int a[maxn << 1];
int f[maxn];
int ans, l, r;
char opt[maxn << 1];
char bestOpt[maxn << 1]; 

int vis[maxn];

void check()
{
	memcpy(bestOpt, opt, sizeof(opt));
	ans = 1;
}

void dfs(int x)
{
	if (ans)
		return;
	if (x == (n << 1) + 1)
		check();
	else if (x <= n)
	{
		opt[x] = 'L';
		if (!vis[a[l]])
		{
			vis[a[l]] = 1;
			f[x] = a[l++];
			dfs(x + 1);
			if (ans)
				return;
			f[x] = 0;
			vis[a[--l]] = 0;
		}
		opt[x] = 'R';
		if (!vis[a[r]])
		{
			vis[a[r]] = 1;
			f[x] = a[r--];
			dfs(x + 1);
			if (ans)
				return;
			f[x] = 0;
			vis[a[++r]] = 0;
		}
		opt[x] = 0;
	}
	else
	{
		int rev = (n << 1) - x + 1;
		if (a[l] == f[rev])
		{
			opt[x] = 'L';
			++l;
			dfs(x + 1);
			if (ans)
				return;
			opt[x] = 0;
			--l;
		}
		else if (a[r] == f[rev])
		{
			opt[x] = 'R';
			--r;
			dfs(x + 1);
			if (ans)
				return;
			opt[x] = 0;
			++r;
		}
	}
}

int main() 
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t = readInt();
	while (t--)
	{
		n = readInt();
		memset(a, 0, sizeof(a));
		rep(i, 1, (n << 1))
			a[i] = readInt();
		if (n > 1000)
		{
			int cnt = 0;
			rep(i, 1, (n << 1))
				if (a[i] == a[i + 1])
					++cnt;
			if (cnt >= 2)
				printf("-1\n");
			else
			{
				rep(i, 1, (n << 1))
					putchar('L');
				putchar('\n');
			}
		}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		l = 1, r = n << 1;
		dfs(1);
		if (ans == 0)
			printf("-1\n");
		else
			printf("%s\n", bestOpt + 1);
	}
	return 0; 
}
