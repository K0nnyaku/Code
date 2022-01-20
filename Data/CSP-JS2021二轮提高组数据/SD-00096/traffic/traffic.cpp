#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
const int M=N*N;
const int INF=1e9;
int fst[M],nxt[M*20],mm=1,cur[M];
int vis[M],dis[M],q[M],tim;
int tm,fn;
int S,T,n,m,qn;
struct Edge{int v,w;}e[M*20];
pair<int,int>flow[M*20],newe[M];
void ade(int u,int v,int w){e[++mm]=(Edge){v,w},nxt[mm]=fst[u],fst[u]=mm;}
void link(int u,int v,int w){ade(u,v,w),ade(v,u,0);}
int bfs(int S,int T,int curtim)
{
	int head=0,tail=1;
	dis[S]=0;q[1]=S;vis[S]=curtim;
	while(head<tail)
	{
		int u=q[++head];
		for(int i=fst[u];i;i=nxt[i])
		{
			int v=e[i].v;if(vis[v]==curtim||!e[i].w)continue;
			dis[v]=dis[u]+1;q[++tail]=v;vis[v]=curtim;
		}
	}
	if(curtim!=vis[T])return 0;
	for(int i=1;i<=tail;i++)cur[q[i]]=fst[q[i]];
	return 1;
}
int dfs(int u,int T,int lim)
{
	if(u==T)return lim;
	int add=0,f;
	for(int &i=cur[u];i;i=nxt[i])
	{
		int v=e[i].v;
		if(dis[v]==dis[u]+1&&e[i].w&&(f=dfs(v,T,min(lim,e[i].w))))
		{
			e[i].w-=f,e[i^1].w+=f;
			add+=f,lim-=f;
			flow[++fn]=make_pair(i,f);
			if(!lim)break;
		}
	}
	return add;
}
int dinic()
{
	int ans=0;
	++tim;
	while(bfs(S,T,tim))
	{
		ans+=dfs(S,T,INF);++tim;
	}
	return ans;
}


void newade(int u,int v,int w)
{
	newe[++tm]=make_pair(u,fst[u]);
	e[++mm]=(Edge){v,w},nxt[mm]=fst[u],fst[u]=mm;
}
void newlink(int u,int v,int w)
{
	newade(u,v,w),newade(v,u,w);
}
void clear()
{
	for(int i=tm;i>=1;i--)
		fst[newe[i].first]=newe[i].second,--mm;
	for(int i=fn;i>=1;i--)
	{
		int id=flow[i].first,f=flow[i].second;
		e[id].w+=f,e[id^1].w-=f;
	}
	tm=fn=0;
}
int getid(int x,int y){return (x-1)*m+y;}
int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x;
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("traffic5.in","r",stdin);
//	freopen("cswa.txt","w",stdout);
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&qn);
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			int x=read();
			link(getid(i,j),getid(i+1,j),x);
			link(getid(i+1,j),getid(i,j),x);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			int x=read();
			link(getid(i,j),getid(i,j+1),x);
			link(getid(i,j+1),getid(i,j),x);
		}
	S=0,T=n*m+1;
	while(qn--)
	{
		int K;
		scanf("%d",&K);
		for(int i=1;i<=K;i++)
		{
			int x=read(),id=read(),col=read();
			int tid;
			if(id<=m)tid=getid(1,id);
			else if(id<=m+n)tid=getid(id-m,m);
			else if(id<=m*2+n)tid=getid(n,2*m+n-id+1);
			else tid=getid(2*(m+n)-id+1,1);
			if(col)newlink(S,tid,x);
			else newlink(tid,T,x);
		}
		printf("%d\n",dinic());
		clear();
	}
}
