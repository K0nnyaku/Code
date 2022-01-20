#include<cstdio>
#include<cstring>

struct edge{ int u,v,w; }e[50];
int n,m,tot,col[50],ans=(1<<30);

int min(const int& a,const int& b){ return a<b?a:b; }
void add(int u,int v,int w){ e[++tot]=(edge){u,v,w}; }

void dfs(int u)
{
	if(u==n*m+1)
	{
		int res=0;
		for(int i=1;i<=tot;++i)
			if(col[e[i].u]!=col[e[i].v]) res+=e[i].w;
		ans=min(ans,res);
		return;
	}
	col[u]=0,dfs(u+1);
	col[u]=1,dfs(u+1);
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int T;
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;++i) for(int j=1;j<=m;++j)
	{
		int w; scanf("%d",&w);
		add((i-1)*m+j,i*m+j,w);	
	}
	for(int i=1;i<=n;++i) for(int j=1;j<m;++j) 
	{
		int w; scanf("%d",&w);
		add((i-1)*m+j,(i-1)*m+j+1,w);	
	}
	
	while(T--)
	{
		int k; scanf("%d",&k);
		for(int i=1,x,p,t;i<=k;++i)
		{
			scanf("%d%d%d",&x,&p,&col[n*m+i]);
			if(p<=m) add(n*m+i,p,x);
			else if(p<=m+n) add(n*m+i,(p-m)*m,x);
			else if(p<=2*m+n) add(n*m+i,(n-1)*m+2*m+n-p+1,x);
			else add(n*m+i,(2*m+2*n-p)*m+1,x);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
