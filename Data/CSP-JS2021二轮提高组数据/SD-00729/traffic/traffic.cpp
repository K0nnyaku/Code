#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,T,k;
long long ans[10][505][505];
int h[505][505],l[505][505];
int s,p,t;
//www wbw bww bbw wwb wbb bwb bbb
inline int read()
{
	int x=1,y=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')
	  c=getchar();
	if(c=='-')
	{
	  x=-1;
	  c=getchar();
	}
	while(c>='0'&&c<='9')
	{
	  y=(y<<3)+(y<<1)+c-'0';
	  c=getchar();
	}
	return x*y;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=2;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    h[i][j]=read();
	for(int i=1;i<=n;i++)
	  for(int j=2;j<=m;j++)
	    l[i][j]=read();
	while(T--)
	{
	  memset(ans,0,sizeof(ans));
	  k=read();
	  for(int i=1;i<=k;i++)
	  {
	  	s=read(),p=read(),t=read();
	  	if(t==0)
	  	{
	  	  if(1<=p&&p<=m)
	  	  {
	  	  	for(int j=5;j<=8;j++)
	  	  	  ans[j][1][p]=s;
		  }
		  if(m+1<=p&&p<=m+n)
		  {
		  	for(int j=5;j<=8;j++)
	  	  	  ans[j][p-m][m]=s;
		  }
		  if(m+n+1<=p&&p<=2*m+n)
		  {
		  	for(int j=5;j<=8;j++)
		  	  ans[j][n][2*m+n-p+1]=s;
		  }
		  if(2*m+n+1<=p&&p<=2*(m+n))
		  {
		  	for(int j=5;j<=8;j++)
		  	  ans[j][2*(m+n)-p+1][1]=s;
		  }
		}
		else
		{
	  	  if(1<=p&&p<=m)
	  	  {
	  	  	for(int j=1;j<=4;j++)
	  	  	  ans[j][1][p]=s;
		  }
		  if(m+1<=p&&p<=m+n)
		  {
		  	for(int j=1;j<=4;j++)
	  	  	  ans[j][p-m][m]=s;
		  }
		  if(m+n+1<=p&&p<=2*m+n)
		  {
		  	for(int j=1;j<=4;j++)
		  	  ans[j][n][2*m+n-p+1]=s;
		  }
		  if(2*m+n+1<=p&&p<=2*(m+n))
		  {
		  	for(int j=1;j<=4;j++)
		  	  ans[j][2*(m+n)-p+1][1]=s;
		  }
		}
	  }
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	    {
	      ans[1][i][j]=ans[1][i][j]+min(min(ans[1][i][j-1],ans[3][i][j-1])+min(ans[1][i-1][j],ans[2][i-1][j]),min(ans[2][i][j-1],ans[4][i][j-1])+min(ans[3][i-1][j],ans[4][i-1][j]));
		  ans[2][i][j]=ans[2][i][j]+h[i][j]+min(min(ans[1][i][j-1],ans[3][i][j-1])+min(ans[5][i-1][j],ans[6][i-1][j]),min(ans[2][i][j-1],ans[4][i][j-1])+min(ans[7][i-1][j],ans[8][i-1][j]));
		  ans[3][i][j]=ans[3][i][j]+l[i][j]+min(min(ans[5][i][j-1],ans[7][i][j-1])+min(ans[1][i-1][j],ans[2][i-1][j]),min(ans[6][i][j-1],ans[8][i][j-1])+min(ans[3][i-1][j],ans[4][i-1][j]));
		  ans[4][i][j]=ans[4][i][j]+h[i][j]+l[i][j]+min(min(ans[5][i][j-1],ans[7][i][j-1])+min(ans[5][i-1][j],ans[6][i-1][j]),min(ans[7][i][j-1],ans[8][i][j-1])+min(ans[7][i-1][j],ans[8][i-1][j]));
		  ans[5][i][j]=ans[5][i][j]+h[i][j]+l[i][j]+min(min(ans[1][i][j-1],ans[3][i][j-1])+min(ans[1][i-1][j],ans[2][i-1][j]),min(ans[2][i][j-1],ans[4][i][j-1])+min(ans[3][i-1][j],ans[4][i-1][j]));
		  ans[6][i][j]=ans[6][i][j]+l[i][j]+min(min(ans[1][i][j-1],ans[3][i][j-1])+min(ans[5][i-1][j],ans[6][i-1][j]),min(ans[2][i][j-1],ans[4][i][j-1])+min(ans[7][i-1][j],ans[8][i-1][j]));
		  ans[7][i][j]=ans[7][i][j]+h[i][j]+min(min(ans[5][i][j-1],ans[7][i][j-1])+min(ans[1][i-1][j],ans[2][i-1][j]),min(ans[6][i][j-1],ans[8][i][j-1])+min(ans[3][i-1][j],ans[4][i-1][j]));
		  ans[8][i][j]=ans[8][i][j]+min(min(ans[5][i][j-1],ans[7][i][j-1])+min(ans[5][i-1][j],ans[6][i-1][j]),min(ans[7][i][j-1],ans[8][i][j-1])+min(ans[7][i-1][j],ans[8][i-1][j]));
		}
	  printf("%lld\n",min(min(min(ans[1][n][m],ans[2][n][m]),min(ans[3][n][m],ans[4][n][m])),min(min(ans[5][n][m],ans[6][n][m]),min(ans[7][n][m],ans[8][n][m]))));
	}
	return 0;
}

