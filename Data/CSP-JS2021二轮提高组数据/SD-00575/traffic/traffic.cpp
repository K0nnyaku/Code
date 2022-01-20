#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

using namespace std;
struct Edge
{
	int to,nex;
}E[200];

int xx,yy;
int deep[200],fa[200][200],head[200],cnt;

int ksm(int a,int b)
{
	int re=1,t=a;
	while (b)
	{
		if (b&1)
			re=re*t;
		t=t*t;
		b>>=1;
	}
	return re;
}

int gcd(int x,int y)
{
	if (y==0)
		return x;
	return gcd(y,x%y);
}

void exgcd(int a,int b)
{
	if (b==0)
	{
		xx=1;
		yy=0;
		return;
	}
	
	exgcd(b,a%b);
	
	int tx=xx;
	xx=yy;
	yy=tx-a/b*yy;
	return;
}

void addEdge(int x,int y)
{
	E[++cnt].to=y;
	E[cnt].nex=head[x];
	head[x]=cnt;
	return;
}

void build(int x)
{
	for (int i=1;deep[fa[x][i]]>=0;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=head[x];i;i=E[i].nex)
	{
		int y=E[i].to;
		if (fa[x][0]==y)
			continue;
		deep[y]=deep[x]+1;
		fa[y][0]=x;
		build(y);
	}
	return;
}

int get_lca(int x,int y)
{
	if (x==y)
		return x;
	if (deep[x]<deep[y])
		swap(x,y);
	int tmp=log(deep[x]-deep[y])/log(2);
	for (int i=tmp;i>=0;i--)
	{
		if (deep[fa[x][i]]>=deep[y])
			x=fa[x][i];
		if (x==y)
			return x;
	}
	tmp=log(deep[x])/log(2);
	for (int i=tmp;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}

inline void init()
{
	cout << ksm(2,12) << endl;
	return;
}

int main()
{
	//freopen("traffic.in","r",stdin);
	//freopen("traffic.out","w",stdout);
	init();
	//fclose(stdin);
	//fclose(stdout);
	return 0; 
}
