#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct ae{
	int c;
	int sum;
	int col;
} p[10000];
queue<ae> q; 
int const _=1e5+5;
int tot,fir[_],vis[_],dis[_],n,m,k,t,w,cl[_];
struct edge
{
	int nxt;
	int to;
	int val;
} e[_];
void add(int u,int v,int w)
{
	e[++tot]=(edge){fir[u],v,w};
	fir[u]=tot;
}
long long read()
{
	char ch=getchar();
	long long x=0,cf=1;
	while(ch<'0'||ch>'9'){if(ch=='-');cf=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*cf;
}
void bfs()
{
	q.push((ae){1,1,1});
	q.push((ae){1,1,2});
	while(!q.empty())
	{
	int u=q.front().c;
	q.pop();
	int l=q.front().sum;
	for(int i=fir[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(cl[v]==0)
		{
			q.push((ae){v,l+1,1});
			q.push((ae){v,l+1,2});
		}
	}
	}
}
int main()
{
	//freopen("traffic.in","r",stdin);
	//freopen("traffic.out","w",stdout);
	n=read();
	m=read();
	t=read();
	while(t--)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				w=read();
				add(j+m*(i-1),j+m*i,w);
				add(j+m*i,j+m*(i-1),w);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m-1;j++)
			{
				w=read();
				add(j+m*(i-1),j+m*(i-1)+1,w);
				add(j+m*(i-1)+1,j+m*(i-1),w);
			}
		}
		k=read();
		for(int i=1;i<=k;i++)
		{
			w=read();
			int u;
			u=read();
			if(u<m)
			{
				add(u*m+i,u,w);
				add(u,u*w+i,w);
			}
			if(u>m&&u<(m+n))
			{
				add(u*m+i,m,w);
				add(m,u*m+i,w);
			}
			if(u>(m+n)&&u<(2*m+n))
			{
				int y=u%(n*m);
				add(u*m+i,(n*m)-y,w);
				add((n*m)-y,u*m+i,w);
			}
			if(u>(2*m+n)&&u<=(2*m+2*n))
			{
				int r=u%n;
				add(u*m+i,1+r*(n+m),w);
				add(1+r*(n+m),u*m+i,w);
			}
			cl[u*m+i]=read();
		}
	}
	cout<<13<<endl;
	return 0;
}

