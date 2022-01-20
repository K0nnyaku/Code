#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,t,a[maxn],st[maxn],poi,poi1,poi2,tpoi;
bool vis[maxn];
struct palce
{
	int fir,sec;
}p[maxn];
inline int read()
{
	int zx=0;
	int zk=1;
	char zc=getchar();
	while(zc<'0'||zc>'9')
	{
		if(zc=='-')	zk=-1;
		zc=getchar();
	}
	while(zc>='0'&&zc<='9')
	{
		zx=(zx<<3)+(zx<<1)+(zc^48);
		zc=getchar();
	}
	return zx*zk;
}
bool query(int s,int e)
{
	if(s<poi1 && e>poi2)	return false;
	if(poi==n)
		return true;
	if(a[s-1]<a[e+1])
	{
		if(a[poi1]==a[s-1] && poi1!=s-1)
			{st[--tpoi]=0 , st[++poi]=0 , ++poi1 ; if(query(s-1,e)) return true;}
		if(a[poi2]==a[s-1])
			{st[--tpoi]=0 , st[++poi]=1 , --poi2 ; if(query(s-1,e)) return true;}
		if(a[poi1]==a[e+1])
			{st[--tpoi]=1 , st[++poi]=0 , ++poi1 ; if(query(s,e+1)) return true;}
		if(a[poi2]==a[e+1] && poi2!=e+1)
			{st[--tpoi]=1 , st[++poi]=1 , --poi2 ; if(query(s,e+1)) return true;}
		return false;
	}
	else
	{
		if(a[poi1]==a[e+1])
			{st[--tpoi]=1 , st[++poi]=0 , ++poi1 ; if(query(s,e+1)) return true;}
		if(a[poi2]==a[e+1] && poi2!=e+1)
			{st[--tpoi]=1 , st[++poi]=1 , --poi2 ; if(query(s,e+1)) return true;}
		if(a[poi1]==a[s-1] && poi1!=s-1)
			{st[--tpoi]=0 , st[++poi]=0 , ++poi1 ; if(query(s-1,e)) return true;}
		if(a[poi2]==a[s-1])
			{st[--tpoi]=0 , st[++poi]=1 , --poi2 ; if(query(s-1,e)) return true;}
		return false;
	}
}
void wout()
{
	n*=2;
	for(register int i=1;i<=n;++i)
	{
		if(!st[i])	putchar('L');
		else	putchar('R');
	}
	
	putchar('\n');
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(register int w=0;w<t;++w)
	{
		n=read(); poi1=0; poi2=2*n-1; tpoi=2*n;
		for(register int i=0;i<2*n;++i)
		{
			a[i]=read();
			if(vis[a[i]])	p[a[i]].sec=i;
			else	vis[a[i]]=true , p[a[i]].fir=i;
		}
		memset(vis,0,sizeof(vis));
		if(a[0]<a[2*n-1])
		{
			poi=0; tpoi=2*n; ++poi1; st[++poi]=0;
			if(query(p[a[0]].sec,p[a[0]].sec))
				{wout() ; continue;}
			poi=0; tpoi=2*n; --poi1; --poi2; st[++poi]=1;
			if(query(p[a[2*n-1]].fir,p[a[2*n-1]].fir))
				{wout() ; continue;}
		}
		else
		{
			poi=0; tpoi=2*n; --poi2; st[++poi]=1;
			if(query(p[a[2*n-1]].fir,p[a[2*n-1]].fir))
				{wout() ; continue;}
			poi=0; tpoi=2*n; ++poi2; ++poi1; st[++poi]=0;
			if(query(p[a[0]].sec,p[a[0]].sec))
				{wout() ; continue;}
		}
		putchar('-') , putchar('1') , putchar('\n');
	}
	return 0;
}
