#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int l,r;
};
bool cmp(const pt x,const pt y)
{
	return x.l<y.l;
}
struct qwq
{
	pt a[1000005];
	int m,nans[1000005],f[1000005],b[1000005];
	int find(int x)
	{
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	void link(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		f[x]=y;
	}
	void solve(int k)
	{
	//	printf("solve:\n");
		for(int i=1;i<=m;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
			b[i]=a[i].l;
		for(int i=1;i<=m+2;i++)
			f[i]=i;
		int nw=0;
		nans[0]=0;
		for(int i=1;i<=k;i++)
		{
			int las=0,u=-1;
			while(1)
			{
				u=lower_bound(b+1,b+m+1,las)-b;
				u=find(u);
			//	printf("i=%d,nw=%d,las=%d,u=%d\n",i,nw,las,u);
				if(u>m) break;
				las=a[u].r;
				link(u,u+1);
				nw++;
			}
			nans[i]=nw;
		}
	}
}T[2];
int n;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&T[0].m,&T[1].m);
	T[0].solve(n);
	T[1].solve(n);
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,T[0].nans[i]+T[1].nans[n-i]);
	printf("%d\n",ans);
	return 0;
}
