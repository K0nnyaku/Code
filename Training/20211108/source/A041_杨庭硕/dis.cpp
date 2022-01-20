#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e3+5,MAXM=MAXN<<1;
int n,m,cnt,ans,head[MAXN],no[MAXN][MAXN],vis[MAXN][MAXN],vis2[MAXN],num;
struct edge{
	int to,nt;
}edge[MAXM];
void add_edge(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nt=head[u];
	head[u]=cnt;
}
void dfs(int u,int dis,int fa)
{
	for(int i=head[u];i;i=edge[i].nt)
	{
		int v=edge[i].to;
		if(no[u][v] || vis2[v]) continue;
		vis2[v]=1;
		dis++;
		if(!vis[fa][v] && dis<=num)
		{
			ans++;
			vis[fa][v]=1;
			vis[v][fa]=1;
//			printf("vis[%d][%d]\n",fa,v);
		}
		dfs(v,dis,fa);
		dis--;
	}
}
int main()
{
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		add_edge(i,i/2);
		add_edge(i/2,i);
	}
	for(int i=1;i<=m;i++)
	{
		char ch;
		cin>>ch>>num;
		if(ch=='-')
		{
			no[num][num/2]=1;
			no[num/2][num]=1;
		}
		if(ch=='?')
		{
			memset(vis,0,sizeof(vis));
			ans=0;
			for(int i=1;i<=n;i++)
			{
				memset(vis2,0,sizeof(vis2));
//				printf("dfs(%d):\n",i);
				vis2[i]=1;
				dfs(i,0,i);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
