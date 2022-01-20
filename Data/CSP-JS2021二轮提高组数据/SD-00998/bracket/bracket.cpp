#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
const int P = 1e9 + 7;
int n, k, cha[505], zkh, ykh;
ll ans, p_;

void dfs(int x, int zuokuohao, int youkuohao, int xing)
{//					左括号总数 	  右括号总数  *的连续数 是否左右括号连续 
	if (x > n)
	{ 
		return ;
	} 
	if (x == n)
		ans = max(ans, p_);
	if (cha[x] == 1)
	{
		zuokuohao++;
		xing = 0;
	}
	else if (cha[x] == 2) 
	{
		xing++;
		if (xing > k)
		{
			p_--;
			return ;
		} 
	}
	else if (cha[x] == 3)
	{
		youkuohao++;
		xing = 0;
		if (youkuohao > zuokuohao) 
		{
			p_--;
			return ;
		}
		if (x == n && zuokuohao > youkuohao)
		{
			p_--;
			return ;
		}
	}
	zuokuohao++; p_++; 
	dfs(x + 1, zuokuohao, youkuohao, xing);
	zuokuohao--; p_--;
	xing++; p_++; 
	dfs(x + 1, zuokuohao, youkuohao, xing);
	xing--; p_--; 
	youkuohao++; p_++;
	dfs(x + 1, zuokuohao, youkuohao, xing);
	youkuohao--; p_--;
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout); 
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		int ch;
		scanf("%c", &ch);
		if (ch == '(') cha[i] = 1;
		else if (ch == '*') cha[i] = 2;
		else if (ch == ')') cha[i] = 3;
		else if (ch == '?') cha[i] = 4;
	}
	dfs(1, 0, 0, 0);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
