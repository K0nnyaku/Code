#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct ne{
	int u;
	int v;
};ne a[100005],b[100005];
int na[100005],nb[100005];
int vis[1000005];
int tot[1000005];
int cc[1000005];
int t=0;
int ans=-1;
int maxn=1e6+1;
inline int read()
{
	char c;
	int f=1;int now=0;
	c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-') f=-1;
		c=getchar();}
	while(c>='0'&&c<='9'){
		now=(now<<1)+(now<<3)+c-'0';
		c=getchar();}
	return now*f;
}
int cmp(ne aa,ne bb)
{
	return aa.u<bb.u||aa.u==bb.u&&aa.v<bb.v;
}
int n,ma,mb;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();ma=read();mb=read();
	for(int i=1;i<=ma;i++)
		a[i].u=read(),a[i].v=read(),tot[++t]=a[i].u,tot[++t]=a[i].v;
	for(int i=1;i<=mb;i++)
		b[i].u=read(),b[i].v=read(),tot[++t]=b[i].u,tot[++t]=b[i].v;
	sort(tot+1,tot+1+t);
	int af=unique(tot+1,tot+1+t)-tot-1;
	for(int i=1;i<=ma;i++) a[i].u=lower_bound(tot+1,tot+af+1,a[i].u)-tot,a[i].v=lower_bound(tot+1,tot+af+1,a[i].v)-tot;
	for(int i=1;i<=mb;i++) b[i].u=lower_bound(tot+1,tot+af+1,b[i].u)-tot,b[i].v=lower_bound(tot+1,tot+af+1,b[i].v)-tot;
	sort(a+1,a+ma+1,cmp);
	sort(b+1,b+mb+1,cmp);
	int fro=1;
	for(int i=1;i<=n;i++)
	{
		int now=i;
		for(int j=1;j<=ma;j++)
		{
			for(int k=fro;k<=a[j].u-1;k++) now+=cc[k],cc[k]=0;
			fro=a[j].u;
			if(now>0){
				now--;
				na[i]++;
				cc[a[j].v]=1;
			}
		}
	}
	fro=1;
	for(int i=1;i<=n;i++)
	{
		int now=i;
		for(int j=1;j<=mb;j++)
		{
			for(int k=fro;k<=b[j].u-1;k++) now+=cc[k],cc[k]=0;
			fro=b[j].u;
			if(now!=0){
				now--;
				nb[i]++;
				cc[b[j].v]=1;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,na[i]+nb[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
