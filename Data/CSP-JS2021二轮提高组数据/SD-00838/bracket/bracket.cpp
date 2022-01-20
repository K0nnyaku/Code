#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
	char c = getchar(), last = ' ';
	ll ans = 0;
	while(c < '0' || c > '9') last = c, c = getchar();
	while(c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	while(last == '-') ans = -ans;
	return ans;
}
const ll mod = 1e9+7;
const int N = 505;
int n, k;
ll ans;
char s[N];
int c[N];
int flag1[N], flag2[N];
bool check()
{
	for(int i = 1; i <= n; i ++) flag1[i] = 0, flag2[i] = 0;
	int cnt = 0;
	bool f1 = 0, f2 = 0;
	if(c[1] == 0) return 0;
	for(int i = 1; i <= n; i ++)
	{
		if(c[i] == 1) 
		{
			f1 = 1;
			f2 = 0;
			cnt ++;
		}
		if(c[i] == -1) 
		{
			f1 = 0;
			f2 = 1;
			cnt --;
		}
		if(c[i] == 0)
		{
			if(f1 == 1) 
			{
				flag1[cnt] ++;
				if(flag1[cnt] > k) return 0;
			}
			if(f2 == 1)
			{
				if(flag1[cnt] != 0) return 0;
				else 
				{
					flag2[cnt] ++;
					if(flag2[cnt] > k) return 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(c[i] == 1) printf("( ");
		if(c[i] == 0) printf("* ");
		if(c[i] == -1) printf(") ");
		//printf("%d ", c[i]);
		
	}
	putchar('\n');
	return 1;
}
void dfs(int now, int sum, int cntk)//dao now, zhi qian s
{
	if(cntk > k) return;
	if(now == n + 1) 
	{
		if(sum == 0 && cntk == 0)
			if(check() == 1) 
				ans ++;
		return;	
	}
	if(n - now - 1 + sum < 0) return;
	if(s[now] == '(') 
	{
		c[now] = 1;
		dfs(now + 1, sum + 1, 0);	
	}
	else if(s[now] == ')')
	{
		c[now] = -1;
		dfs(now + 1, sum - 1, 0);
	}
	else if(s[now] == '*')
	{
		c[now] = 0;
		dfs(now + 1, sum, cntk + 1);
	}
	else if(s[now] == '?')
	{
		for(int i = -1; i <= 1; i ++)
		{
			if(sum + i < 0) continue;
			c[now] = i;
			if(i == 0)
				dfs(now + 1, sum + i, cntk + 1);
			else dfs(now + 1, sum + i, 0);
		}
	}
	
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	scanf("%s", s + 1);
	dfs(1, 0, 0);
	printf("%lld", ans % mod);
	return 0;
}
