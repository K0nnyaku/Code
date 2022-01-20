#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge
{
	int frm,too,w,nxt;
}edge[510*510*4],edge2[510*510*4];
struct node
{
	int v,p,co;
}a[60];
int n,m,t;
int head[510*510],head2[510*510];
int p[510*510];
int cnt=1;
void add(int u,int v,int w)
{
	edge[cnt].frm=u;
	edge[cnt].too=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
int fifa(int x)
{
	if(x==p[x])
	{
		return x;
	}
	return p[x]=fifa(p[x]);
}
void join(int x,int y)
{
	int px=fifa(x),py=fifa(y);
	if(px!=py)
	{
		p[px]=py;
	}
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int kru()
{
	int ans=0;
	for(int i=1;i<=(n+1)*(m+1);i++)
	{
		p[i]=i;
	}
	sort(edge+1,edge+cnt,cmp);
	for(int i=1;i<cnt;i++)
	{
		int u=edge[i].frm,v=edge[i].too;
		if(fifa(u)!=fifa(v))
		{
			join(u,v);
			ans+=edge[i].w;
		}
	}
	return ans;
}
bool cmp2(node x,node y)
{
	return x.p<y.p;
}
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
	int x=2*n+2*m;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int w;
			scanf("%lld",&w);
			if(j==1)
			{
				add(2*n+2*m-i+1,x+(i-1)*(m-1)+j,w);
			}
			else if(j==m)
			{
				add(m+i+1,x+(i-1)*(m-1)+j-1,w);
			}
			else
			{
				add(x+(i-1)*(m-1)+j-1,x+(i-1)*(m-1)+j,w);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int w;
			scanf("%lld",&w);
			if(i==1)
			{
				add(j+1,x+(i-1)*(m-1)+j,w);
			}
			else if(i==n)
			{
				add(2*m+n-j-1,x+(i-1)*(m-1)+j-1-1,w);
			}
			else
			{
				add(x+(i-1)*(m-1)+j-1,x+(i-1)*(m-1)+j+m-1-1,w);
			}
		}
	}
	for(int i=1;i<=502*502;i++)
	{
		head2[i]=head[i];
	}
	for(int i=1;i<cnt;i++)
	{
		edge2[i].frm=edge[i].frm;
		edge2[i].too=edge[i].too;
		edge2[i].w=edge[i].w;
		edge2[i].nxt=edge[i].nxt;
	}
	int now=cnt;
	while(t--)
	{
		int k;
		scanf("%lld",&k);
		cnt=now;
		memset(head,0,sizeof(head));
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=502*502;i++)
		{
			head[i]=head2[i];
		}
		for(int i=1;i<cnt;i++)
		{
			edge[i].frm=edge2[i].frm;
			edge[i].too=edge2[i].too;
			edge[i].w=edge2[i].w;
			edge[i].nxt=edge2[i].nxt;
		}
		for(int i=1;i<=k;i++)
		{
			scanf("%lld%lld%lld",&a[i].v,&a[i].p,&a[i].co);
		}
		sort(a+1,a+k+1,cmp2);
		a[0].co=2;
		int lst=0;
		for(int i=1;i<2*m+2*n;i++)
		{
			if(a[lst+1].p==i&&a[++lst].co!=a[lst-1].co)
			{
				add(i,i+1,a[lst].v);
			}
			else
			{
				add(i,i+1,0);
			}
		}
		if(a[k].p==2*m+2*n&&a[k].co!=a[k-1].co)
		{
			add(1,2*m+2*n,a[k].v);
		}
		else
		{
			add(1,2*m+2*n,0);
		}
		printf("%lld\n",kru());
	}
	return 0;
}
