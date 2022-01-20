#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read()
{
	char c = getchar(), last = ' ';
	int ans = 0;
	while(c < '0' || c > '9') last = c, c = getchar();
	while(c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	while(last == '-') ans = -ans;
	return ans;
}
const int N = 500005;
int T;
int n, a[N], b[N], c[N];
char opt[N], opt1[N];
bool check()
{
	for(int i = 1, j = 2 * n; i <= n; i ++, j --)
	{
		if(b[i] != b[j]) return 0;
	}
	return 1;
}
void dfs(int now, int l, int r)
{
	if(now == 2 * n + 1)
	{
		if(check() == 1)
		{
			for(int i = 1; i <= 2 * n; i ++)
			{
				if(opt1[i] == opt[i]) continue;
				if(opt1[i] > opt[i]) break;
				if(opt1[i] < opt[i]) 
				{
					for(int j = 1; j <= 2 * n; j ++) 
					{
						c[j] = b[j];
						opt[j] = opt1[j];
					}
					break;
				}
			}
		}
		return;
	}
	if(now <= n || (now > n && a[l] == b[2 * n - now + 1]))
	{
		b[now] = a[l], opt1[now] = 'L';
		dfs(now + 1, l + 1, r);
	}
	if(now <= n || (now > n && a[r] == b[2 * n - now + 1]))
	{
		b[now] = a[r], opt1[now] = 'R';
		dfs(now + 1, l, r - 1);
	}
	
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while(T --)
{
	for(int i = 1; i <= 1000; i ++) opt[i] = 'Z';
	n = read();
	if(n <= 1000)
	{
		for(int i = 1; i <= 2 * n; i ++) a[i] = read();
		dfs(1, 1, 2 * n); 
		if(opt[1] == 'Z') 
		{
			printf("-1\n");
		}
		else
		{
			for(int i = 1; i <= 2 * n; i ++)
			{
				printf("%c", opt[i]);
				//printf("%d ", c[i]);
			}
				
			printf("\n");
		}
	}
	else
	{
		for(int i = 1; i <= 2 * n; i ++)
		{
			b[i] = read();
			if(check() == 1)
			{
				for(int j = 1; j <= n; j ++) printf("L");
				for(int j = 1; j <= n; j ++) printf("R");
				printf("\n");
			}
			else
			{
				printf("-1\n");
			}
		}
	}

}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
