#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3010;
int n,m,T,cnt,f[N];
struct Edge{
	int x,y,z;
}e[N];
int getf(int x)
{
	return f[x]==x?x:f[x]=getf(f[x]);
}
void add(int x,int y,int z)
{
	e[++cnt].x=x;
	e[cnt].y=y;
	e[cnt].z=z;
}
bool cmp(Edge a,Edge b)
{
	return a.z>b.z;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	int x;
	cnt=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			add(i*m+j,(i+1)*m+j,x);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			scanf("%d",&x);
			add(i*m+j,i*m+j+1,x);
		}
	while(T--)
	{
		int k,x,p,t,ts=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&x,&p,&t);
			ts+=t;
			if(p<=m)
				add((n*(m+1)+i),p,x);
			else if(p>m&&p<=m+n)
				add((n*(m+1)+i),(p-m)*n+m,x);
			else if(p>m+n&&p<=2*m+n)
				add((n*(m+1)+i),(n*m+(2*m+n-p+1)),x);
			else add((n*(m+1)+i),(2*m+2*n-p+1)*m+1,x);
			f[(n*(m+1)+i)]=n*(m+1)+2+t;
		}
		f[(n*(m+1)+2)]=(n*(m+1)+2);
		f[(n*(m+1)+3)]=(n*(m+1)+3);
		if(ts==0||ts==t)
		{
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n*(m+1);i++) f[i]=i;
		//cout<<cnt<<endl;
		sort(e+1,e+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int x=e[i].x,y=e[i].y;
			//cout<<e[i].z<<endl;
			x=getf(x);y=getf(y);
			if(x==n*(m+1)+2&&y==n*(m+1)+3||x==n*(m+1)+3&&y==n*(m+1)+2) ans+=e[i].z;
			else if(x!=y) f[x]=y;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
