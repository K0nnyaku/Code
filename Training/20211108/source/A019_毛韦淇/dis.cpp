#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#define ll long long
using  namespace std;
const int maxn=1000006;
int cnt,son[maxn],f[maxn],dfn[maxn],size[maxn],head[maxn],dep[maxn],tot,top[maxn],n,m,dist[maxn],g[6001][6001],k;
char ch;
struct egde{
	int nt,to,dis;
}e[maxn*4];
void add(int u,int v,int dis)
{
	++cnt;
	e[cnt].nt=head[u];
	e[cnt].to=v;
	e[cnt].dis=dis;
	head[u]=cnt;
}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=fa;
	dfn[++tot]=x;
	size[x]=1;
	for(int i=head[x];i;i=e[i].nt)
	{
		int v=e[i].to;
		if(v==fa) continue;
	dist[v]=dist[x]+1;
		dfs1(v,x);
		size[x]+=size[v];
		
		if(!son[x]||size[son[x]]<size[v])
		son[x]=v;
	}
}
void dfs2(int x,int tv)
{
	top[x]=tv;
	if(son[x]) dfs2(son[x],tv);
	for(int i=head[x];i;i=e[i].nt)
	{
		int v=e[i].to;
		if(v==son[x]||v==f[x])
	    continue;
		top[v]=v;
		dfs2(v,v);
	}
}
int LCA(int a,int b)
{
	
	while(top[a]!=top[b])
	{
		if(dep[top[a]]>dep[top[b]])
		swap(a,b);
		b=f[top[b]];
	}
	return dep[a]<dep[b]?a:b;
}
int main()
{
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		int j=i/2;
		add(i,j,1);
		add(j,i,1);
	}
	dfs1(1,0);
	dfs2(1,1);
   for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
   {
   	g[i][j]=dist[i]+dist[j]-2*dist[LCA(i,j)];
   	g[j][i]=dist[i]+dist[j]-2*dist[LCA(i,j)];
   }
   
   for(int mos=1;mos<=m;mos++)
   {
   cin>>ch;
   	if(ch=='?')
   	{
   		scanf("%d",&k);
   		int ans=0;
   		for(int i=1;i<=n;i++)
   		{
   			for(int j=i+1;j<=n;j++)
   			{
   				if(g[i][j]<=k)
   				ans++;
			   }
		   }
		   printf("%d\n",ans);
	}
	else{
		scanf("%d",&k);
	}
   }
   return 0;
}
