#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n,m,T,k,ans;
int dis[1001][1001][3];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&dis[i][j][1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			scanf("%d",&dis[i][j][2]);
		}
	}
	scanf("%d",&k);
	if(k==1)
	{
		int f,p,t,xf,yf;
		scanf("%d%d%d",&f,&p,&t);
		if(f<=m) xf=1,yf=f;
		else if(f<=m+n)xf=f-m,yf=m;
		else if(f<=m+m+n)xf=n,yf=n+2*m-f+1;
		else xf=2*m+2*n-f+1,yf=1;
		if(xf==1||xf==n)
			ans=min(p,dis[xf][yf][2]+dis[xf][yf][1]+dis[xf][yf-1][1]);
		else
			ans=min(p,dis[xf][yf][2]+dis[xf][yf][1]+dis[xf-1][yf][2]);
	}
	cout<<ans<<endl;
}
