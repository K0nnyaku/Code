#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define MAXN 2000000
#define INF 1e13 + 7

using namespace std;

inline int read()
{
	int x = 0, f = 1; char c  = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') { x = x * 10 + (c ^ 48); c = getchar();}
	return f * x;	   
}

int T, flag = 0, n, x[500000], a[500000], f = 0, t = 0;
char ans[500000], cle;

inline int check()
{
	for (int i = 1; i <= n; i++)
		if (x[i] != x[2 * n + 1 - i])
			return 0;
			
	
	return 1;
}

inline void dfs(int nnow)
{
	if (nnow == 2 * n + 1)
	{
		if (check()) flag = 1;
		return;
	}

	x[nnow] = a[f];
	f++;
	ans[nnow] = 'L';
	dfs(nnow + 1);
	f--;
	x[nnow] = 0;
	
	if (flag) return;
	
	x[nnow] = a[t];
	t--;
	ans[nnow] = 'R';
	dfs(nnow + 1);
	t++;
	x[nnow] = 0;

}

signed main()
{     
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	T = read();
	while (T--)
	{
		memset(ans, cle, sizeof(ans));
		flag = 0;
		n = read();
		f = 1, t = 2 * n;
		for (int i = 1; i <= 2 * n; i++)
			a[i] = read();
		dfs(1);
		if (!flag) {cout << -1; puts("");}
		else 
		{
			for (int i = 1; i <= 2 * n; i++)
				cout << ans[i];
			puts("");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
