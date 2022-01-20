#include<bits/stdc++.h>
using  namespace std;
namespace _mzf
{
	#define ll long long
	ll  n,m,t,g[50][50][50][50],k,ds,ans=2e18;
	int vis[50][50],v[50][50];
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};
	ll read()
	{
		ll flag=1,sum=0;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			sum=sum*10+ch-'0';
			ch=getchar();
		}
		return flag*sum;
	}
	void dfs(int x,int y,int dq,ll sum)
	{
		if(sum>ans) return;
		if(dq==n*m)
		{
			ans=min(ans,sum);
			return;
		}
		for(int i=0;i<4;i++)
		{
			int xx=dx[i]+x;
			int yy=dy[i]+y;
			if((xx<0||xx>n+1||yy<0||yy>m+1)) continue;
			//else 	if(vis[xx][yy]!=vis[x][y]&&(v[xx][yy]==0)){v[xx][yy]=1;sum+=g[xx][yy][x][y];}
			if(xx==0&&vis[xx][yy]==-1) continue;
			else if(vis[xx][yy]!=vis[x][y]&&(v[xx][yy]==0))	{v[xx][yy]=1;if(vis[xx][yy]!=vis[x][y]) dfs(xx,yy,dq+1,sum+g[xx][yy][x][y]);
				else dfs(xx,yy,dq+1,sum);sum+=g[xx][yy][x][y];}
			if(xx==n+1&&vis[xx][yy]==-1) continue;
			else if(vis[xx][yy]!=vis[x][y]&&(v[xx][yy]==0))	{v[xx][yy]=1;if(vis[xx][yy]!=vis[x][y]) dfs(xx,yy,dq+1,sum+g[xx][yy][x][y]);
				else dfs(xx,yy,dq+1,sum);sum+=g[xx][yy][x][y];}
			if(yy==0&&vis[xx][yy]==-1) continue;
			else if(vis[xx][yy]!=vis[x][y]&&(v[xx][yy]==0))	{v[xx][yy]=1;if(vis[xx][yy]!=vis[x][y]) dfs(xx,yy,dq+1,sum+g[xx][yy][x][y]);
				else dfs(xx,yy,dq+1,sum);sum+=g[xx][yy][x][y];}
			if(yy==m+1&&vis[xx][yy]==-1) continue;
			else if(vis[xx][yy]!=vis[x][y]&&(v[xx][yy]==0))	{v[xx][yy]=1;if(vis[xx][yy]!=vis[x][y]) dfs(xx,yy,dq+1,sum+g[xx][yy][x][y]);
				else dfs(xx,yy,dq+1,sum);sum+=g[xx][yy][x][y];}
			if(vis[xx][yy]!=-1) continue;
			for(int i=0;i<=1;i++)
			{
				vis[xx][yy]=i;
				if(vis[xx][yy]!=vis[x][y]) dfs(xx,yy,dq+1,sum+g[xx][yy][x][y]);
				else dfs(xx,yy,dq+1,sum);
				vis[xx][yy]=-1;
			}
			
		 } 
	}
	void mzfmain()
	{
		n=read();
		m=read();
		t=read();
		int w;
		for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			w=read();
			g[i][j][i+1][j]=g[i+1][j][i][j]=w;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
		w=read(),g[i][j][i][j+1]=g[i][j+1][i][j]=w;
		while(t--)
		{
			k=read();
			ans=2e18;
			for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
			vis[i][j]=v[i][j]=-1;
			for(int i=1;i<=k;i++)
			{
				ll x,y,z;
				x=read();
				y=read();
				z=read();
				if(y<=m)
				{
					g[0][y][1][y]=g[1][y][0][y]=x;
					vis[0][y]=z;
				}
				else if(y>m&&y<=n+m)
				{
					g[y-m][m+1][y-m][m]=g[y-m][m][y-m][m]=x;
					vis[y-m][m+1]=z;
				}
				else if(y>n+m&&y<=2*m+n)
				{
					g[n+1][2*m+n-y+1][n][2*m+n-y+1]=g[n][2*m+n-y+1][n+1][2*m+n-y+1]=x;
					vis[n+1][2*m+n-y+1]=z;
				}
				else if(y>2*m+n)
				{
					int w=2*m+2*n-y+1;
					g[w][0][w][1]=g[w][1][w][0]=x;
					vis[w][0]=z;
				}
				ds=n*m+k;
				dfs(1,1,1,0);
			}
			cout<<ans<<endl; 
		}
	}
}
int main()
{
	freopen("traffic","r",stdin);
	freopen("traffic","w",stdout);
	_mzf::mzfmain();
	return 0;
}
