#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	void a(char& c)
	{
		do c=g();
		while(c<=32);
	}
	template<typename T>
	void d(T& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
}IO;

const int MX=150100;
int N,M;

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int F[MX],D[MX],sz[MX],son[MX];
int U[MX],dfn[MX],dfn_[MX],dc;
void dfs1(int x,int f,int d)
{
	F[x]=f,D[x]=d,sz[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,dfn[x]=++dc,dfn_[dc]=x;
	if(son[x])dfs2(son[x],u);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])dfs2(y,y);
}

char val[MX*4];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Assign(int i,int l,int r,int a,int x)
{
	if(l==r){val[i]=x;return;}
	if(a<=mid)Assign(li,l,mid,a,x);
	else Assign(ri,mid+1,r,a,x);
	val[i]=val[li]&val[ri];
}
void Query(int i,int l,int r,int a,int b,int &x)
{
	if(x||val[i])return;
	if(l==r){x=dfn_[l];return;}
	if(b>mid)Query(ri,mid+1,r,a,b,x);
	if(a<=mid)Query(li,l,mid,a,b,x);
}

struct Fenwick
{
	ll v[MX],w[MX];
	void Add_(int i,ll x)
	{
		ll y=i*x;
		while(i<=N)v[i]+=x,w[i]+=y,i+=i&-i;
	}
	void Add(int l,int r,ll x){Add_(l,x),Add_(r+1,-x);}
	ll Ask_(int i)
	{
		ll n=i,a=0,b=0;
		while(i)a+=v[i],b+=w[i],i-=i&-i;
		return a*(n+1)-b;
	}
	ll Ask(int l,int r){return Ask_(r)-Ask_(l-1);}
}T;

int C[MX];
void Change(int x,int z)
{
	int y=C[x];
	if(y)
	{
		Assign(1,1,N,dfn[y],0);
		T.Add(dfn[y],dfn[y]+sz[y]-1,1);
	}
	C[x]=z;
	if(z)
	{
		Assign(1,1,N,dfn[z],1);
		T.Add(dfn[z],dfn[z]+sz[z]-1,-1);
	}
}
void Expose(int x)
{
	Change(x,0);
	while(x)
	{
		int l=dfn[U[x]],r=dfn[x];
		while(1)
		{
			int y=0;
			Query(1,1,N,l,r,y);
			if(!y)break;
			Change(F[y],y);
		}
		x=F[U[x]];
	}
}
double Ask(int x)
{
	ll a=T.Ask(dfn[x],dfn[x]+sz[x]-1);
	return (double)a/sz[x];
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
//	scanf("%d",&N);
	IO.d(N);
	Fr(i,2,N)
	{
		int x,y;
//		scanf("%d%d",&x,&y);
		IO.d(x),IO.d(y);
		++x,++y;
//		printf(": %d %d\n",x,y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	Assign(1,1,N,1,1);
	Fr(x,2,N)T.Add(dfn[x],dfn[x]+sz[x]-1,1);
	
	IO.d(M);
//	scanf("%d",&M);
	Fr(i,1,M)
	{
		char c;
		int x;
//		scanf(" %c%d",&c,&x);
		IO.a(c),IO.d(x);
		++x;
		if(c=='q')printf("%.10f\n",Ask(x));
		else Expose(x);
		
//		Fr(j,1,N)printf("%2d ",j);putchar('\n');
//		Fr(j,1,N)printf("%2d ",C[j]);putchar('\n');
//		Fr(j,1,N)printf("%2lld ",T.Ask(dfn[j],dfn[j]));putchar('\n');
	}
	
//	Fr(i,1,N)printf("%d ",F[i]);putchar('\n');
//	Fr(i,1,N)printf("%d ",sz[i]);putchar('\n');
//	Fr(i,1,N)printf("%d ",U[i]);putchar('\n');
	
	/*N=10;
	memset(val,1,sizeof(val));
	Assign(1,1,N,3,0);
	Assign(1,1,N,7,0);
	Assign(1,1,N,9,0);
	while(1)
	{
		int l,r,x=0;
		scanf("%d%d",&l,&r);
		Query(1,1,N,l,r,x);
		printf(":%d\n",x);
	}*/
	
	/*while(1)
	{
		int x;
		scanf("%d",&x);
		Expose(x);
		Fr(i,1,N)printf("%2d ",i);putchar('\n');
		Fr(i,1,N)printf("%2d ",C[i]);putchar('\n');
		Fr(i,1,N)printf("%2lld ",T.Ask(dfn[i],dfn[i]));putchar('\n');
	}*/
	
	return 0;
}
