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

int n, m, T, a[600][600], h[500][500], l[500][500], ans = INF, X[MAXN], Y[MAXN], NUM, tag[MAXN];

inline void check()
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (i != 0 && a[i][j] != a[i - 1][j]) sum += l[i - 1][j];
			if (j != 0 && a[i][j] != a[i][j - 1]) sum += h[i][j - 1];
			if (a[i][j] != a[i + 1][j]) sum += l[i][j];
			if (a[i][j] != a[i][j + 1]) sum += h[i][j];
		}
	ans = min(ans, sum);
	
//	if (ans == 0)
//	{
//		for (int i = 0; i <= n; i++)
//		{
//			for (int j = 0; j <= m; j++)
//				cout << a[i][j] << ' ';
//			cout << endl;
//		}
//		cout << endl;
//		exit(0);
//	}

}

void dfs(int x, int y)
{
	if (x == n + 1)
	{
		check();
		return;
	}
	a[x][y] = 1;
	if (y == m)
		dfs(x + 1, 1);
	else
		dfs(x, y + 1);
	
	a[x][y] = 2;
	if (y == m)
		dfs(x + 1, 1);
	else 
		dfs(x, y + 1);
	
}

inline void step_1()
{
	dfs(1, 1);
	cout << ans;
}

signed main()
{     
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	n = read(), m = read(), T = read();
	
	for (int i = 1; i < n; i++) 
		for (int j = 1; j <= m; j++)
			l[i][j] = read();
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j< m; j++)
			h[i][j] = read();
			
			
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			cout << l[i][j] << ' ';
//		cout << endl;
//	}
	
	
	while (T--)
	{
		ans = 0;

		int k = read();
		for (int i = 1; i <= k; i++)
		{
			int w = read(), p = read(), t = read() + 1;
			int x, y;
			NUM++;
			if (p <= m)
				x = 0, y = p, l[x][y] = w, tag[NUM] = 1;
			if (p > m && p <= m + n)
				y = m + 1, x = p - m, h[x][y - 1] = w, tag[NUM] = 2;
			if (p > m + n && p <= 2 * m + n)
				x = n + 1, y = 2 * m + n + 1 - p, l[x - 1][y] = w, tag[NUM] = 3;
			if (p > 2 * m + n)
				y = 0, x = 2 * m + 2 * n + 1 - p, h[x][y] = w, tag[NUM] = 4;
			a[x][y] = t;
			X[NUM] = x, Y[NUM] = y;
//			cout << endl << x << ' ' << y << endl << endl;


			
		}
		
//		for (int i = 0; i <= n; i++)
//		{
//			for (int j = 1; j <= m; j++)
//				cout << h[i][j] << ' ';
//			cout << endl;
//		}
		
		
		
		if (n <= 5 && m <= 5) step_1();
		for (int i = 1; i <= NUM; i++)
		{
			int x = X[i], y = Y[i];
			if (tag[i] == 1) l[x][y] = 0;
			if (tag[i] == 2) h[x][y - 1] = 0;
			if (tag[i] == 3) l[x - 1][y] = 0;
			if (tag[i] == 4) h[x][y] = 0;
		}
		memset(a, 0, sizeof(a));
//		memset(h, 0, sizeof(h));
//		memset(l, 0, sizeof(l));
		memset(tag, 0, sizeof(tag));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
