#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define _rep(i,x,y) for(int i=x;i>=y;i--)
#define N 5050
const int inf=1e18;
int read()
{
	int num=0,fu=1; char c;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') fu=-1,c=getchar();
	while(c>='0'&&c<='9') num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return fu*num;
}

int dx[2]={1,0};
int dy[2]={0,1};

int T,n,m,val[N][N],cl[N],k,ans,Cl[55],ge[55],w[55];

int id(int x,int y) {return (x-1)*m+y;}

void dfs(int u)
{
	if(u==n*m+1)
	{
		int res=0;
		rep(i,1,n)
			rep(j,1,m)
				rep(g,0,1)
				{
					int x=i+dx[g],y=j+dy[g];
					if(x>n||x<1||y>m||y<1) continue;
					if(cl[id(i,j)]!=cl[id(x,y)]) res+=val[id(i,j)][id(x,y)];
				}
		rep(i,1,k) 
			if(Cl[i]!=cl[ge[i]]) res+=w[i];
		ans=min(ans,res);
		return;
	}
	cl[u]=1; dfs(u+1);
	cl[u]=0; dfs(u+1);
}

signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(); m=read(); T=read();
	rep(i,1,n-1)
		rep(j,1,m)
			val[id(i,j)][id(i+1,j)]=val[id(i+1,j)][id(i,j)]=read();
	rep(i,1,n)
		rep(j,1,m-1)
			val[id(i,j+1)][id(i,j)]=val[id(i,j)][id(i,j+1)]=read();
	
	while(T--)
	{
		ans=inf; k=read();
		rep(i,1,k)
		{
			w[i]=read();int p=read(); Cl[i]=read();
			if(1<=p&&p<=m) ge[i]=id(1,p);
			if(m+1<=p&&p<=m+n) ge[i]=id(p-m,m);
			if(m+n+1<=p&&p<=2*m+n) ge[i]=id(n,2*m+n+1-p);
			if(2*m+n<=p&&p<=2*m+2*n) ge[i]=id(2*m+2*n+1-p,1);
		}
		
		dfs(1);
		
		printf("%lld\n",ans);
	}
	return 0;
}
