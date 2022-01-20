#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
};
node a[100005],b[100005];
int n,m1,m2,ans,sum1[100005],sum2[100005];
bool vis[100005];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int cnt=m1,now=0;
    while(now<=n)
    {
    	now++;
    	int tim=0,num=cnt;
    	cnt=0;sum1[now]=sum1[now-1];
		for(int i=1;i<=num;i++)
		{
			if(a[i].l>tim)
			{
				tim=a[i].r;
				sum1[now]++;
			}
			else a[++cnt]=a[i];
	    }
	}
	cnt=m2;now=0;
    while(now<=n)
    {
    	now++;
    	int tim=0,last=0,num=cnt;
    	cnt=0;sum2[now]=sum2[now-1];
		for(int i=1;i<=num;i++)
		{
			if(b[i].l>tim)
			{
				tim=b[i].r;
				sum2[now]++;
			}
			else b[++cnt]=b[i];
	    }
	}
	for(int i=0;i<=n;i++)ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d",ans);
	return 0;
}
