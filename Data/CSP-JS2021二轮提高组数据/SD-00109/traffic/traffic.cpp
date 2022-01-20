//CSP2021 rp++ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
template<typename T>
inline T read()
{
	T s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
const int MAXN(510);
int n,m,t;
ll G1[MAXN][MAXN],G2[MAXN][MAXN];
const int dx[5]={0,0,1,0,-1};
const int dy[5]={0,1,0,-1,0};
int col[MAXN][MAXN];
ll qx[MAXN];
int qy[MAXN],qz[MAXN];
ll ans(1e18);
inline ll check()
{
	ll res(0);
	for(register int i=0;i<=n;i++) 
		for(register int j=1;j<=m;j++)
			if(col[i][j]!=col[i+1][j]) res+=G1[i][j];
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=m;j++)
			if(col[i][j]!=col[i][j+1]) res+=G2[i][j];
	return res;
}
inline void dfs(int x,int y)
{
	if(y>m+1) y=0,++x;
	if(x>n+1)
	{
		ll now=check();
		if(ans>now) ans=now;
		return;
	}
	if(col[x][y]!=-1)
		dfs(x,y+1);
	else
	{
		col[x][y]=0;
		dfs(x,y+1);
		col[x][y]=1;
		dfs(x,y+1);
		col[x][y]=-1;
	}
}
inline void solve()
{
	int k=read<int>();
	memset(col,-1,sizeof(col));
	for(register int i=1;i<=k;i++)
	{
		qx[i]=read<ll>(),qy[i]=read<int>(),qz[i]=read<int>();
		int xx(0),yy(0);
		int p(1);
		for(register int j=1;j<=qy[i];j++)
		{
			xx+=dx[p],yy+=dy[p];
			if(yy>m&&xx==0) p=2;
			else if(yy>m&&xx>n) p=3;
			else if(yy<1&&xx>n) p=4;
		} 
		col[xx][yy]=qz[i];
		if(p==1) G1[xx][yy]=qx[i];
		else if(p==2) G2[xx][yy-1]=qx[i];
		else if(p==3) G1[xx-1][yy]=qx[i];
		else if(p==4) G2[xx][yy]=qx[i];
	}
	dfs(0,1);
	printf("%lld\n",ans);
	for(register int i=1;i<=k;i++)
	{
		int xx(0),yy(0);
		int p(1);
		for(register int j=1;j<=qy[i];j++)
		{
			xx+=dx[p],yy+=dy[p];
			if(yy>m&&xx==0) p=2;
			else if(yy>m&&xx>n) p=3;
			else if(yy<1&&xx>n) p=4;
		} 
		col[xx][yy]=-1;
		if(p==1) G1[xx][yy]=0;
		else if(p==2) G2[xx][yy-1]=0;
		else if(p==3) G1[xx-1][yy]=0;
		else if(p==4) G2[xx][yy]=0;
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read<int>(),m=read<int>(),t=read<int>();
	for(register int i=1;i<n;i++)
		for(register int j=1;j<=m;j++)
			G1[i][j]=read<ll>();
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<m;j++)
			G2[i][j]=read<ll>();
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
