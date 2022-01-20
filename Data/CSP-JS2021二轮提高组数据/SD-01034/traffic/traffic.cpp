#include<stdio.h>
#include<string.h>

int n,m,T;
#define node(x,y) (((x)-1)*m+(y))

struct Edge{ int v,f,next; }e[5000002],t_e[5000002];
int ecnt=1,t_ecnt=1,h[500002],t_h[500002],cur[500002];
inline void add_edge(int u,int v,int f){ e[++ecnt]={v,f,h[u]},h[u]=ecnt;e[++ecnt]={u,f,h[v]},h[v]=ecnt; }

int s,t;

int dis[500002];
struct Queue{ int head,tail,q[500002]; inline void clear(){ head=1,tail=0; } inline void push(int x){ q[++tail]=x; } inline void pop(){ head++; } inline int front(){ return q[head]; } inline bool empty(){ return head>tail; } }q;
inline bool bfs()
{
	q.clear();
	memset(dis,-1,sizeof(dis));
	q.push(s),dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		cur[u]=h[u];
		for(int i=h[u];i;i=e[i].next)
			if(dis[e[i].v]==-1&&e[i].f) q.push(e[i].v),dis[e[i].v]=dis[u]+1;
	}
	return dis[t]!=-1;
}

inline long long min(long long x,long long y){ return x<y?x:y; }
long long dfs(int u,long long f)
{
	if(!f) return 0;
	if(u==t) return f;
	long long sum=0,temp=0;
	for(int i=cur[u];i;i=e[i].next)
	{
		if(dis[e[i].v]==dis[u]+1)
		{
			temp=dfs(e[i].v,min(f,e[i].f));
			sum+=temp,f-=temp;
			e[i].f-=temp,e[i^1].f+=temp;
			if(!f) return sum;
		}
		cur[u]=i;
	}
	return sum;
}

inline int dinic()
{
	long long ans=0;
	while(bfs())
		ans+=dfs(s,0x3f3f3f3f3f3f3f3fll);
	return ans;
}

inline void save()
{
	t_ecnt=ecnt;
	for(int i=1;i<=n*m+2;i++) t_h[i]=h[i];
	for(int i=1;i<=ecnt;i++) t_e[i]=e[i];
}
inline void cancel()
{
	ecnt=t_ecnt;
	for(int i=1;i<=n*m+2;i++) h[i]=t_h[i];
	for(int i=1;i<=ecnt;i++) e[i]=t_e[i];
}

inline int get(int x)
{
	if(x<=m) return node(1,x);
	if(x<=n+m) return node(x-m,m);
	if(x<=2*m+n) return node(n,m-(x-m-n)+1);
	return node(n-(x-2*m-n)+1,1);
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	s=n*m+1,t=n*m+2;
	for(int i=1,x;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&x),add_edge(node(i,j),node(i+1,j),x);
	for(int i=1,x;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			scanf("%d",&x),add_edge(node(i,j),node(i,j+1),x);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			add_edge(s,node(i,j),0),add_edge(node(i,j),t,0);
	long long ans=dinic();
	save();
	for(int i=1,k;i<=T;i++)
	{
		scanf("%d",&k);
		for(int i=1,x,p,c;i<=k;i++)
			scanf("%d%d%d",&x,&p,&c),c?add_edge(get(p),t,x):add_edge(s,get(p),x);
		printf("%d\n",ans+dinic());
		cancel();
	}
	return 0;
}
