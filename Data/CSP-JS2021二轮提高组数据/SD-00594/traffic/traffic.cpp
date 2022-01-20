#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct pt
{
	int val,x,y;
	pt(int val=0,int x=0,int y=0):val(val),x(x),y(y){}
	bool operator<(const pt p) const
	{
		return val>p.val;
	}
};
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m,T,d[505][505][2],b[100005][2],c[100005][3];
int a[100005][3],f[105][105],dis[505][505],vis[505][505];
int dp[40000005],p[100005],tmp[100005][3];
priority_queue<pt> pq;
void dij(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[sx][sy]=0;
//	printf("s=%d,%d\n",sx,sy);
	pq.push(pt(0,sx,sy));
	while(!pq.empty())
	{
		while(!pq.empty()&&dis[pq.top().x][pq.top().y]!=pq.top().val)
			pq.pop();
		if(pq.empty()) break;
		int x=pq.top().x,y=pq.top().y;
		vis[x][y]=1;
		pq.pop();
		for(int k=0;k<4;k++)
		{
			int xx=x+dx[k],yy=y+dy[k];
			if(xx<0||xx>n||yy<0||yy>m) continue;
			int w=0;
			if(k==0) w=d[x][y][0];
			else if(k==1) w=d[x][y][1];
			else if(k==2) w=d[x-1][y][0];
			else if(k==3) w=d[x][y-1][1];
		//	printf("x=%d,y=%d,xx=%d,yy=%d,w=%d\n",x,y,xx,yy,w);
			if(vis[xx][yy]||dis[xx][yy]<=dis[x][y]+w) continue;
			dis[xx][yy]=dis[x][y]+w;
			pq.push(pt(dis[xx][yy],xx,yy));
		}
	}
/*	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			printf("%d ",dis[i][j]);
		printf("\n");
	}*/
}
bool cmp(const int x,const int y)
{
	return a[x][1]<a[y][1];
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&d[i][j-1][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&d[i-1][j][0]);
	for(int i=1;i<=m;i++)
	{
		b[i][0]=0;
		b[i][1]=i;
		c[i][0]=0;
		c[i][1]=i-1;
		c[i][2]=1;
	}
	for(int i=m+1;i<=m+n;i++)
	{
		b[i][0]=i-m;
		b[i][1]=m;
		c[i][0]=i-m-1;
		c[i][1]=m;
		c[i][2]=0;
	}
	for(int i=m+n+1;i<=2*m+n;i++)
	{
		b[i][0]=n;
		b[i][1]=m-(i-n-m);
		c[i][0]=n;
		c[i][1]=m-(i-n-m);
		c[i][2]=1;
	}
	for(int i=2*m+n+1;i<=2*m+2*n;i++)
	{
		b[i][0]=n-(i-2*m-n);
		b[i][1]=0;
		c[i][0]=n-(i-2*m-n);
		c[i][1]=0;
		c[i][2]=0;
	}
	while(T--)
	{
		for(int i=1;i<=2*(n+m);i++)
			d[c[i][0]][c[i][1]][c[i][2]]=0;
		int k,sum=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			int w,v,x;
			scanf("%d%d%d",&w,&v,&x);
			a[i][0]=w,a[i][1]=v,a[i][2]=x;
			d[c[v][0]][c[v][1]][c[v][2]]=w;
			sum+=w;
			p[i]=i;
		}
		sort(p+1,p+k+1,cmp);
		for(int i=1;i<=k;i++)
			for(int j=0;j<3;j++)
				tmp[i][j]=a[p[i]][j];
		for(int i=1;i<=k;i++)
			for(int j=0;j<3;j++)
				a[i][j]=tmp[i][j];
	/*	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
				printf("(%2d,%2d) ",d[i][j][0]*10/181573,d[i][j][1]*10/181573);
			printf("\n");
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(d[i][j][0]<=181573)
					printf("i=%d,j=%d,d0=%d\n",i,j,d[i][j][0]);
				if(d[i][j][1]<=181573)
					printf("i=%d,j=%d,d1=%d\n",i,j,d[i][j][1]);
			}
		}*/
	//	for(int i=1;i<=k;i++)
	//		printf("i=%d,a=%d,%d,%d\n",i,a[i][0],a[i][1],a[i][2]);
		a[k+1][0]=a[1][0],a[k+1][1]=a[1][1],a[k+1][2]=a[1][2];
		int ct=0;
		for(int i=1;i<=k;i++)
		{
			if(a[i][2]!=0||a[i+1][2]!=1) continue;
			int u=a[i][1];
			dij(b[u][0],b[u][1]);
			ct++;
			int nw=0;
			for(int j=1;j<=k;j++)
				if(a[j][2]==1&&a[j+1][2]==0)
				{
					int v=a[j][1];
					nw++;
					f[ct-1][nw-1]=dis[b[v][0]][b[v][1]];
			//		printf("i=%d,j=%d,ct=%d,nw=%d,dis=%d\n",i,j,ct,nw,f[ct-1][nw-1]);
				}
		}
		dp[0]=0;
		for(int i=1;i<(1<<ct);i++)
		{
			dp[i]=sum;
			int nw=0;
			for(int j=0;j<ct;j++)
				nw+=((i>>j)&1);
			nw--;
			for(int j=0;j<ct;j++)
				if(i&(1<<j))
					dp[i]=min(dp[i],dp[i-(1<<j)]+f[nw][j]);
		}
		printf("%d\n",dp[(1<<ct)-1]); 
	}
	return 0;
}
