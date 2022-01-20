#include<cstdio>
#include<queue>
#include<cstring> 
using namespace std;
const int mod=1000000007,inf=0x3f3f3f3f,M=300000,N=50005;//?
int n,m,T,k,head[N],cnt=1,lev[N],prehead[N],result,tot,s=50001,t=50002;
int id[505][505],ls[N][2],mp;
bool vis[N];
int read()//int!!
{
	int w=1,f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		f=f*10+c-'0';
		c=getchar();
	}
	return w*f;
}
int minn(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
struct edge
{
	int u,v,w,next;
}e[M<<1];
void addedge(int u,int v,int w)
{
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}
bool bfs()
{
	queue<int> Q;
	memset(lev,inf,sizeof(lev));
	lev[s]=0;
	prehead[s]=head[s];
	Q.push(s);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].v;
			if(e[i].w>0&&lev[v]==inf)
			{
				lev[v]=lev[u]+1;
				Q.push(v);
				prehead[v]=head[v];
				if(v==t)
					return true;
			}
		}
	}
	return false;
}
int update(int u,int val)
{
	int k,ans=0;
	if(u==t)
		return val;
	for(int i=prehead[u];i&&val;i=e[i].next)
	{
		prehead[u]=i;
		if(e[i].w&&lev[e[i].v]==lev[u]+1)
		{
			int v=e[i].v;
			k=update(v,minn(val,e[i].w));
			if(!k)
				lev[v]=inf;
			ans+=k;
			ans%=mod;
			val-=k;
			e[i].w-=k;
			e[i^1].w+=k;
			ls[++mp][0]=i;ls[mp][1]=k;
		}
	}
	return ans%mod;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int temp;
	n=read();m=read();T=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			id[i][j]=++tot;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			temp=read();
			addedge(id[i][j],id[i+1][j],temp);
			addedge(id[i+1][j],id[i][j],0);
			addedge(id[i+1][j],id[i][j],temp);
			addedge(id[i][j],id[i+1][j],0);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
		{
			temp=read();
			addedge(id[i][j],id[i][j+1],temp);
			addedge(id[i][j+1],id[i][j],0);
			addedge(id[i][j+1],id[i][j],temp);
			addedge(id[i][j],id[i][j+1],0);
		}
	while(T--)//T<=50
	{
		k=read();
		if(k<=2)
		{
			mp=0;
			int temp,nu,fe,dot,color=0,opt=0;
			for(int i=1;i<=k;i++)
			{
				temp=read();nu=read();fe=read();
				if(nu<=n)
					dot=id[1][nu];
				else if(nu>n&&nu<=n+m)
					dot=id[n][nu-n];
				else if(nu>n+m&&nu<=2*n+m)
					dot=id[m-(nu-n-m)+1][m];
				else
					dot=id[n-(nu-n-n-m)+1][1];
				if(!color)
				{
					addedge(s,dot,temp);
					addedge(dot,s,0);
					opt+=2;
				}
				else
				{
					addedge(dot,t,temp);
					addedge(t,dot,0);
					opt+=2;	
				}
				color^=fe;
			}
			if(k==1)
				printf("0\n");
			if(k==2)
			{
				result=0;//ÍøÂç»¹Ô­£¿
				memset(lev,0,sizeof(lev));
				memset(prehead,0,sizeof(prehead)); 
				if(color==0)
					printf("0\n");
				else
				{
					while(bfs())
						result+=update(s,inf); 
					printf("%d\n",result%mod);
				}
			}
			for(int i=1;i<=mp;i++)
			{
				e[ls[mp][0]].w+=ls[mp][1];
				e[ls[mp][0]^1].w-=ls[mp][1];
			}
			for(int i=0;i<opt;i++)
			{
				e[cnt].next=e[cnt].w=e[cnt].u=e[cnt].v=0;
				cnt--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
