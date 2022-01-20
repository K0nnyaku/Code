/*
Author: smyslenny
Title:
Date:2021.10.23
Main idea:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>

#define ll long long
#define INF 0x3f3f3f3f
#define orz cout<<"LKP AK IOI"

using namespace std;
const int M=1e3+5;
int n,m,k,T;
ll Ans; 
int read()
{
	int x=0,y=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') y=0;c=getchar();}
	while(isdigit(c)) { x=x*10+(c^48);c=getchar();}
	return y?x:-x;
}
int shu[M][M],heng[M][M];
struct new_node{
	int w,num,col;
}node[M];
int col[M][M];

ll check()
{
	ll sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i+1<=n)
			{
				if(col[i][j]!=col[i+1][j])
					sum+=shu[i][j];
			}
			if(j+1<=m)
			{
				if(col[i][j]!=col[i][j+1])
					sum+=heng[i][j];
			}
		}
	for(int i=1;i<=k;i++)
	{
		int x=node[i].num,w=node[i].w;
		if(x<=m) 
		{
			if(node[i].col!=col[1][x])
				sum+=w;
		}
		else if(x<=m+n)
		{
			x-=m;
			if(node[i].col!=col[x][m])
				sum+=w;
		}
		else if(x<=2*m+n)
		{
			x-=m+n;
			x=m-x+1;
			if(node[i].col!=col[n][x])
				sum+=w;
		}
		else
		{
			x-=2*m+n;
			x=n-x+1;
			if(node[i].col!=col[x][1])
				sum+=w;
		}
	}
	return sum;
}

void dfs(int x,int y)
{
	if(x>n)
	{
		Ans=min(Ans,check());
		return;
	}
	if(y>m)
	{
		dfs(x+1,1);
		return;
	}
	col[x][y]=1;
	dfs(x,y+1);
	col[x][y]=2;
	dfs(x,y+1);
	col[x][y]=0;
	return;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			shu[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			heng[i][j]=read();
	while(T--)
	{
		memset(node,0,sizeof(node));
		k=read();
		Ans=INF;
		for(int i=1;i<=k;i++)
			node[i].w=read(),node[i].num=read(),node[i].col=read()+1;
		dfs(1,1);
		printf("%lld\n",Ans);
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
