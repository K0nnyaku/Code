#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void read(int &x)
{
	int f= 1;
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch= getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch^48;
		ch = getchar();
	}
	x *= f;
}

struct edge
{
	int x, y,bian;
}edges[251100];

bool cmp(edge x,edge y)
{
	return x.bian > y.bian;
}
int n,m,t,maxn,top;

int colors[251050];

int pan(int x)
{
	if(x <= m)
		return x;
	if(x > m && x <= m + n)
		return (x-m)*m;
	if(x > m+n && x <= 2*m+n)
		return n*m-x+n+1;
	else
		return (2*n+2*m-x)*m+1;
}

void dfs(int x,int y)
{
	if(x == n && y == m)
	{
		int cnt = 0;
		for(int i = 0;i < top;i++)
		{
			if(colors[edges[i].y] != colors[edges[i].x])
			{
				cnt += edges[i].bian;
			}
		}
		maxn = min(maxn,cnt);
	}
	int newx = x,newy = y+1;
	if(newy == m + 1)
	{
		newx = x+1,newy = 1;
	}
	colors[(x-1)*m+y] = 0;
	dfs(newx,newy);
	colors[(x-1)*m+y] = 1;
	dfs(newx,newy);
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	top = 0;
	read(n);read(m);read(t);
	int bian;
	for(int i = 1;i < n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			read(bian);
			edges[top++] = {(i-1)*m+j,i*m+j,bian};
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < m;j++)
		{
			read(bian);
			edges[top++] = {(i-1)*m+j,(i-1)*m+j+1,bian};
		}
	}
	int k,hao,top1 = top;
	while(t--)
	{
		read(k);
		memset(colors,-1,sizeof(colors));
		top = top1;
		for(int i = 1;i <= k;i++)
		{
			read(bian);
			read(hao);
			read(colors[n*m+hao]);
			edges[top++] = {n*m+hao,pan(hao),bian};
		}
		maxn = 1e9;
		dfs(1,1);
		printf("%d\n",maxn);
	}
	return 0;
}

