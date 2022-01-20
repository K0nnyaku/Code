#include<bits/stdc++.h>
const int maxn=100005;
using namespace std;
int n,m1,m2,z1[maxn],z2[maxn];
bool vis[maxn];
struct airs
{
	int zstart,zend;
}a1[maxn],a2[maxn];
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
inline void write(int zx)
{
	if(zx<0)	putchar('-') , zx=~zx+1;
	int s[20],zpoi=0;
	while(zx)
	{
		s[++zpoi]=zx%10;
		zx/=10;
	}
	if(!zpoi)	s[++zpoi]=0;
	while(zpoi)
		putchar(s[zpoi--]+'0');
}
inline bool cmp(airs x,airs y)
{
	return x.zstart<y.zstart;
}
void solve1()
{
	int poi1=0,cnt=0,ztime;
	for(register int i=0;i<m1;++i)
	{
		ztime=a1[i].zstart;
		for(register int j=poi1;j<i;++j)
		{
			if(vis[poi1])	++poi1;
			if(a1[j].zend<ztime && !vis[j])	vis[j]=true , --cnt;//cnt为当前占用的停机坪 
		}
		++z1[++cnt];
	}
}
void solve2()
{
	memset(vis,0,sizeof(vis));
	int poi1=0,cnt=0,ztime;
	for(register int i=0;i<m2;++i)
	{
		ztime=a2[i].zstart;
		for(register int j=poi1;j<i;++j)
		{
			if(vis[poi1])	++poi1;
			if(a1[j].zend<ztime && !vis[j])	vis[j]=true , --cnt;//cnt为当前占用的停机坪 
		}
		++z2[++cnt];
	}
}
int solvez()
{
	for(register int i=1;i<=n;++i)
	{
		z1[i]+=z1[i-1];
		z2[i]+=z2[i-1];
	}
	int best=0;
	for(register int i=0;i<=n;++i)
		best= (z1[i]+z2[n-i])>best ? (z1[i]+z2[n-i]) : best;
	return best;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); m1=read(); m2=read();
	for(register int i=0;i<m1;++i)
	{
		a1[i].zstart=read();
		a1[i].zend=read();
	}
	for(register int i=0;i<m2;++i)
	{
		a2[i].zstart=read();
		a2[i].zend=read();
	}
	sort(a1,a1+m1,cmp); sort(a2,a2+m2,cmp);
	solve1();//预处理出国内飞机的情况 
	solve2();//预处理出国外飞机的情况 
	write( solvez() );//判断最优解 
	return 0;
}
