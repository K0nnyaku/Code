#include<bits/stdc++.h>
using namespace std;
int n,m,T;
struct Edge
{
	int u,v,w;
}edge[500000];
int cnt;
int k,len[55],p[55],t[55],order[55];
int color[1005];
int neighbor[1255];
inline int read()
{
	int x(0);char c(0);bool flag(0);
	for(;!isdigit(c);c=getchar())if(c=='-')flag=1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return flag?-x:x;
}
int Hash(int i,int j)
{
	return m*(i-1)+j;
}
int calc()
{
	int sum=0;
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(color[u]!=color[v])
		{
			sum+=w;
		}
	}
//	cout<<sum<<endl;
	return sum;
}
int ans=0x3f3f3f3f;
void dfs(int i)
{
	if(i==n*m+1)
	{
		ans=min(ans,calc());
		return;
	}
	color[i]=1;
	dfs(i+1);
	color[i]=0;
	dfs(i+1);
	color[i]=-1;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			Edge e;
			e.u=Hash(i,j);
			e.v=Hash(i+1,j);
			e.w=read();
			edge[++cnt]=e;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			Edge e;
			e.u=Hash(i,j);
			e.v=Hash(i,j+1);
			e.w=read();
			edge[++cnt]=e;
		}
	}
	for(int i=1;i<=m;i++)
	{
		neighbor[i]=Hash(1,i);
	}
	for(int i=1;i<=n;i++)
	{
		neighbor[m+i]=Hash(i,m);
	}
	for(int i=m,j=1;i>=1&&j<=m;i--,j++)
	{
		neighbor[m+n+j]=Hash(n,i);
	}
	for(int i=n,j=1;i>=1&&j<=n;i--,j++)
	{
		neighbor[2*m+n+j]=Hash(i,1);
	}
	while(T--)
	{
		memset(p,0,sizeof p);
		memset(t,0,sizeof t);
		memset(color,-1,sizeof color);
		ans=0x3f3f3f3f;
		k=read();
		for(int i=1;i<=k;i++)
		{
			len[i]=read();
			p[i]=read();
			t[i]=read();
			order[i]=n*m+i;
			color[order[i]]=t[i];
			edge[++cnt]={order[i],neighbor[i],len[i]};
		}
		dfs(1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
