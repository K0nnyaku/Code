#include<iostream>
#include<cstdio>
using namespace std;
int T,n,k;
int fa[1010],num[1010],tot;
int siz[1010];
int fac[1010];
bool used[1010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int u=find(x);
	int v=find(y);
	if(u==v) return;
	fa[u]=v;
	siz[v]+=siz[u];
}
int bcnt(int x)
{
	int res=0;
	while(x)
	{
		res++;
		x-=(x&(-x));
	}
	return res;
}
int main()
{
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
		for(int i=1;i<=n;i++)
		{
			int a;scanf("%d",&a);
			merge(i,a);
		}
		tot=0;int ans=0;
		for(int i=1;i<=n;i++) if(fa[i]==i) num[++tot]=siz[i];
		for(int s=0;s<(1<<n);s++)
		{
			if(bcnt(s)!=k) continue;
			for(int i=1;i<=n;i++) used[i]=0;
			for(int i=0;i<n;i++)
			{
				if(s&(1<<i))
				{
					used[find(i+1)]=1;
				}
			}
			int f=1;
			for(int i=1;i<=n;i++) if(!used[find(i)]) f=0;
			ans+=f;
		}
		long long nbcnt=fac[n]/fac[k]/fac[n-k];
		printf("%.10f\n",1.0*ans/nbcnt);
	}
}
