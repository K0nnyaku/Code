#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
const int N=505;
int li[N][N],co[N][N],q,n,m,lct[N],v[N],tot,xd[4]={-1,0,0,1},yd[4]={0,-1,1,0};
bool col[N],p[N][N];
LL res=0;
queue<pair<int,int> > Q;
inline int read()
{
	int s=0;char c=getchar();
	while(!isdigit(c))  c=getchar();
	while(isdigit(c))  s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
bool in(int x,int y) {return x>=0&&y>=0&&x<=n+1&&y<=m+1;}
LL jud(int x,int y,bool c)
{
	LL rt=0;
	if(in(x-1,y))  rt+=co[x-1][y]*((c^p[x-1][y])?1:-1);
	if(in(x,y-1))  rt+=li[x][y-1]*((c^p[x][y-1])?1:-1);
	if(in(x,y+1))  rt+=li[x][y]*((c^p[x][y+1])?1:-1);
	if(in(x+1,y))  rt+=co[x][y]*((c^p[x+1][y])?1:-1);
	return rt;
}
void que(int x,int y,bool c) {p[x][y]=c;res+=jud(x,y,c);Q.push({x,y});}
bool IN(int x,int y) {return x>0&&y>0&&x<=n&&y<=m;}
LL solve(bool c)
{
	res=0;int pi=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)  p[i][j]=c^1;
	for(int i=1;i<=tot;i++)
		if(col[i]==c)
		{
			if(lct[i]<=m)  que(0,lct[i],c);
			else  if(lct[i]<=n+m)  que(lct[i]-m,m+1,c);
			else  if(lct[i]<=n+m*2)  que(n+1,m-(lct[i]-m-n)+1,c);
			else  que(n-(lct[i]-m*2-n)+1,0,c);
		}
		else
		{
			if(lct[i]<=m)  p[0][lct[i]]=c^1;
			else  if(lct[i]<=n+m)  p[lct[i]-m][m+1]=c^1;
			else  if(lct[i]<=n+m*2)  p[n+1][m-(lct[i]-m-n)+1]=c^1;
			else  p[n-(lct[i]-m*2-n)+1][0]=c^1;
		}
	if(pi==tot)  return 0;
	while(Q.size())
	{
		int x=Q.front().first,y=Q.front().second;Q.pop();
		for(int i=0;i<4;i++)
		{
			int xn=x+xd[i],yn=y+yd[i];
			if(IN(xn,yn)&&p[xn][yn]!=c&&jud(xn,yn,c)<=0)  que(xn,yn,c);
		}
	}return res;
}
LL check()
{
	LL rt=0;
	for(int i=1,x,y;i<=tot;i++)
	{
		if(lct[i]<=m)  x=1,y=lct[i];
		else  if(lct[i]<=n+m)  x=lct[i]-m,y=m;
		else  if(lct[i]<=m*2+n)  x=n,y=m-(lct[i]-m-n)+1;
		else  x=n-(lct[i]-m*2-n)+1,y=1;
		if(col[i]^p[x][y])  rt+=v[i];
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(p[i][j]^p[i+1][j])  rt+=co[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(p[i][j]^p[i][j+1])  rt+=li[i][j];
	return rt;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)  co[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)  li[i][j]=read();
	if(n*m<=25)
	{
		while(q--)
		{
			res=1e18;tot=read();
			for(int i=1;i<=tot;i++)  v[i]=read(),lct[i]=read(),col[i]=read();
			for(int S=0;S<(1<<(n*m));S++)
			{
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)  p[i][j]=(S&(1<<((i-1)*m+j-1)))>0;
				res=min(res,check());
			}printf("%lld",res);
		}return 0;
	}
	while(q--)
	{
		tot=read();
		for(int i=1;i<=tot;i++)
		{
			v[i]=read(),lct[i]=read(),col[i]=read();
			if(lct[i]<=m)  co[0][lct[i]]=v[i];
			else  if(lct[i]<=n+m)  li[lct[i]-m][m]=v[i];
			else  if(lct[i]<=m*2+n)  co[n][m-(lct[i]-m-n)+1]=v[i];
			else  li[n-(lct[i]-m*2-n)+1][0]=v[i];
		}
		printf("%lld\n",min(solve(0),solve(1)));
		for(int i=1;i<=tot;i++)
			if(lct[i]<=m)  co[0][lct[i]]=0;
			else  if(lct[i]<=n+m)  li[lct[i]-m][m]=0;
			else  if(lct[i]<=m*2+n)  co[n][m-(lct[i]-m-n)+1]=0;
			else  li[n-(lct[i]-m*2-n)+1][0]=0;
	}return 0;
}
