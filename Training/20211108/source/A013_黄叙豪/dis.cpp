#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
int head[N],ver[N],nxt[N],tot;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct fkosk
{
	char op;
	int x;
}qwq[N];
bool del[N],vis[N];
set<pair<int,int> >v;
void bfs(const int s,int k)
{
	queue<pair<int,int> >q;
	q.push(make_pair(s,0));
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front().first,dis=q.front().second;q.pop();
		if(dis<k)
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if(vis[y])
			{
				continue;	
			}
			vis[y]=1;
			q.push(make_pair(y,dis+1));
		}
		if(dis<=k && dis>0)
		{
			v.insert(make_pair(s,x));	
		}
	}
}
int ans[N],cnt;
signed main()
{
	clock_t c1=clock();
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);

	//======================================
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>qwq[i].op>>qwq[i].x;
		if(qwq[i].op=='-') del[qwq[i].x]=1;
	}
	for(int i=1;i<=n;i++) if(!del[i] && i!=1) add(i,i/2),add(i/2,i);
	for(int i=m;i>=1;i--)
	{
		if(qwq[i].op=='-') add(qwq[i].x,qwq[i].x/2),add(qwq[i].x/2,qwq[i].x);
		else
		{
			for(int j=1;j<=n;j++)
			{
//				printf("now start with %d\n",j);
				bfs(j,qwq[i].x);
				memset(vis,0,sizeof(vis));
//				puts("");
			}
			ans[++cnt]=v.size();
			v.clear();
//			puts("==========================\n");
		}
	}
	for(int i=cnt;i>=1;i--) printf("%d\n",ans[i]/2);
	//======================================
	cerr<<endl<<"Time:"<<clock()-c1<<"(ms)"<<endl;
	return 0;
}