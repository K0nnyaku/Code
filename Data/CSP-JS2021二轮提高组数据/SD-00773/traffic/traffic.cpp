#include<bits/stdc++.h>
using namespace std;
int n,m,t;
struct eg
{
	int u,v,w;
	int next;
}edge[100001*32];
int head[100001*8];
int cnt=1;
int tr(int x,int y)
{
	return (x-1)*m+y;
}
void add_edge(int u,int v,int w)
{
	cnt++;
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int s,d;
int trpos(int val)
{
	if(val<=m)
	{
		return tr(1,val);
	}
	val-=m;
	if(val<=n)
	{
		return tr(val,m);
	}
	val-=n;
	if(val<=m)
	{
		return tr(n,m-val+1);
	}
	val-=m;
	return tr(n-val+1,1);
}

int inque[800001];
int dis[800001];
queue<int> q;
int st[800001];
int tq[606][606];
int can=1;
bool bfs()
{
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<=d;i++)
	{
		st[i]=head[i];
	}
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inque[u]=0;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].v;
			if(dis[v]>dis[u]+1&&edge[i].w)
			{
				dis[v]=dis[u]+1;
				if(inque[v]==0)
				{
					q.push(v);
					inque[v]=1;
				}
			}
		}
	}
	
	if(dis[d]<0x3f3f3f3f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int dfs(int u,int mmin)
{
	if(u==d)
	{
		can=1;
		return mmin;
	}
	int used=0;
	for(int i=st[u];i;i=edge[i].next)
	{
		st[u]=i;
		int v=edge[i].v;
		if(dis[v]==dis[u]+1&&edge[i].w)
		{
			int val=dfs(v,min(mmin-used,edge[i].w));
			edge[i].w-=val;
			edge[i^1].w+=val;
			
			used+=val;
			if(mmin==used)
			{
				break;
			}
		}
	}
	return used;
}
int nd=0;
int u[800001*6];
int v[800001*6];
int w[800001*6];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		for(int i2=1;i2<=m;i2++)
		{
			tq[i][i2]=tr(i,i2);
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int i2=1;i2<=m;i2++)
		{
			int val;
			cin>>val;
//			add_edge(tr(i,i2),tr(i+1,i2),val);
//			add_edge(tr(i+1,i2),tr(i,i2),val);
			nd++;
			u[nd]=tq[i][i2];
			v[nd]=tq[i+1][i2];
			w[nd]=val;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int i2=1;i2<=m-1;i2++)
		{
			int val;
			cin>>val;
//			add_edge(tr(i,i2),tr(i,i2+1),val);
//			add_edge(tr(i,i2+1),tr(i,i2),val);
			nd++;
			u[nd]=tq[i][i2];
			v[nd]=tq[i][i2+1];
			w[nd]=val;
		}
	}
	s=0,d=n*m+3*n+3*m;
	for(int o=1;o<=t;o++)
	{
		memset(head,0,sizeof(head));
		memset(edge,0,sizeof(edge));
		cnt=1;
		for(int i=1;i<=nd;i++)
		{
			add_edge(u[i],v[i],w[i]);
			add_edge(v[i],u[i],w[i]);
		}
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int val,pos,co;
			cin>>val>>pos>>co;
			if(co==0)
			{
				add_edge(s,n*m+pos,0x3f3f3f3f);
				add_edge(n*m+pos,s,0);		
			}
			else
			{
				add_edge(n*m+pos,d,0x3f3f3f3f);
				add_edge(d,n*m+pos,0);
			}
			add_edge(n*m+pos,trpos(pos),val);
			add_edge(trpos(pos),n*m+pos,val);
		}
		
//		for(int i=2;i<=cnt;i++)
//		{
//			cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<"\n";
//		}
		
		can=1;
		int ans=0;
		while(bfs())
		{
			can=1;
			while(can)
			{
				can=0;
				ans+=dfs(s,0x3f3f3f3f);	
			}
		}
		
		cout<<ans<<"\n";
	}
//	cout<<"\n"<<(double)clock()/CLOCKS_PER_SEC;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
