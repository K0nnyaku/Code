#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1001][1001],b[1001][1001],vis[1001][1001],n,m,t;
inline int read()
{
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		r=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();
	}
	return w*r;
}
int ans()
{
	int sum=0;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(vis[i][j]+vis[i+1][j]==1)
			sum=sum+b[i][j];
			if(vis[i][j]+vis[i][j+1]==1)
			sum=sum+a[i][j];
		}
	}
	return sum;
}
int find(int i,int j,int k)
{
	vis[i][j]=k;
	if(i==n&&j==m)
	{
		return ans();
	}
	int ans=0;
	if(j==m)
	{
		ans=min(find(i+1,1,1),find(i+1,1,0));
	}
	else
	{
		ans=min(find(i,j+1,1),find(i,j+1,0));
	}
	return ans;
}
int main()
{
	n=read();
	m=read();
	t=read();
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		b[i][j]=read();
	}
	for(int o=1;o<=t;o++)
	{
		memset(vis,0x3f,sizeof(vis));
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int x=read(),y=read(),c=read();
			if(y>m)
			{
				y=y-m;
				if(y>n)
				{
					y=y-n;
					if(y>m)
					{
						y=y-m;
						b[y][0]=x;
						vis[y][0]=c;
					}
					else
					{
						a[n][y]=x;
						vis[n+1][y]=c;
					}
				}
				else
				{
					b[y][m]=x;
					vis[y][m+1]=c;
				}	
			}
			else
			{
				a[0][y]=x;
				vis[0][y]=c;
			}
		}
		printf("%d",min(find(1,1,0),find(1,1,1)));
	}
}
