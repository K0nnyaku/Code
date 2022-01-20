#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int N=1005;
int n,m,k,T,idk,a[N][N],b[N][N],w[N*N],id1[N][N],id2[N][N],dis[N*N],vis[N*N],qwq[N*N];

struct Edge
{
	int v,ne;
}e[N*N*24];
int head[N*N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

struct Node
{
	int u,w;
	bool operator < (const Node &x)const
	{
		return w>x.w;
	}
};

inline int dij(int x,int y)
{
	for(int i=1;i<=k;++i)
		dis[i]=1e18,vis[i]=0;
	if(x>y) swap(x,y);
	priority_queue<Node> qu;
	for(int i=x;i<=y-1;++i)
		if(qwq[i])
		{
			dis[qwq[i]]=w[qwq[i]];
			qu.push((Node){qwq[i],w[qwq[i]]});
		}
	while(!qu.empty())
	{
		int u=qu.top().u;
		qu.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+w[v])
			{
				dis[v]=dis[u]+w[v];
				if(!vis[v])
					qu.push((Node){v,dis[v]});
			}
		}
	}
	int res=1e18;
	for(int i=1;i<=idk;++i)
		if(qwq[i]&&(i<x||i>=y))
			res=min(res,dis[qwq[i]]);
	return res;
}

signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
			id1[i][j]=++k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
			id2[i][j]=++k;
	for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
		{
			if(id1[i][j-1]) add(id1[i][j],id1[i][j-1]);
			if(id1[i][j+1]) add(id1[i][j],id1[i][j+1]);
			if(id2[i][j-1]) add(id1[i][j],id2[i][j-1]);
			if(id2[i][j]) add(id1[i][j],id2[i][j]);
			if(id2[i+1][j-1]) add(id1[i][j],id2[i+1][j-1]);
			if(id2[i+1][j]) add(id1[i][j],id2[i+1][j]);
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
		{
			if(id2[i-1][j]) add(id2[i][j],id2[i-1][j]);
			if(id2[i+1][j]) add(id2[i][j],id2[i+1][j]);
			if(id1[i-1][j]) add(id2[i][j],id1[i-1][j]);
			if(id1[i-1][j+1]) add(id2[i][j],id1[i-1][j+1]);
			if(id1[i][j]) add(id2[i][j],id1[i][j]);
			if(id1[i][j+1]) add(id2[i][j],id1[i][j+1]);
		}
	for(int i=1;i<=m-1;++i)
		qwq[++idk]=id2[1][i];
	++idk;
	for(int i=1;i<=n-1;++i)
		qwq[++idk]=id1[i][m];
	++idk;
	for(int i=m-1;i>=1;--i)
		qwq[++idk]=id2[n][i];
	++idk;
	for(int i=n-1;i>=1;--i)
		qwq[++idk]=id1[i][1];
	++idk;
	for(int i=1;i<=n-1;++i)
		for(int j=1;j<=m;++j)
			w[id1[i][j]]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m-1;++j)
			w[id2[i][j]]=read();
	while(T--)
	{
		int k=read();
		if(k!=2) return 0;
		int x1=read(),p1=read(),t1=read();
		int x2=read(),p2=read(),t2=read();
		if(t1==t2)
		{
			puts("0");
			continue;
		}
		int ans=min(x1,x2);
		ans=min(ans,dij(p1,p2));
		printf("%lld\n",ans);
	}
	return 0;
}
