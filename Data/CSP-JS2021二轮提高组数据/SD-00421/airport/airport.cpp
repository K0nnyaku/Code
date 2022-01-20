#include<bits/stdc++.h>

#define int long long

using namespace std;

struct air
{
	int l,r;
}a[100010],b[100010];

int n,m1,m2,ans,beg;
int f1[100010],f2[100010];
int flag1[100010],flag2[100010];

bool cmp(air a1,air a2)
{
	return a1.l<a2.l;
}

signed main()
{
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%lld%lld",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%lld%lld",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	beg=1;
	for(int i=1;i<=n;i++)
	{
		//printf("%lld\n",i);
		int r=a[beg].r,flag=0;
		f1[i]=f1[i-1];
		flag1[beg]=1;
		f1[i]++;
		for(int j=beg+1;j<=m1;j++)
		{
			if((!flag1[j])&&(a[j].l>r))
			{
				r=a[j].r;
				f1[i]++;
				flag1[j]=1;
			}
			else if((!flag)&&(!flag1[j]))
			{
				flag=1;
				beg=j;
			}
		}
		if(f1[i]==m1)break;
	}
	beg=1;
	for(int i=1;i<=n;i++)
	{
		//printf("%lld\n",i);
		int r=b[beg].r,flag=0;
		f2[i]=f2[i-1];
		flag2[beg]=1;
		f2[i]++;
		for(int j=beg+1;j<=m2;j++)
		{
			if((!flag2[j])&&(b[j].l>r))
			{
				r=b[j].r;
				f2[i]++;
				flag2[j]=1;
			}
			else if((!flag)&&(!flag2[j]))
			{
				flag=1;
				beg=j;
			}
		}
		if(f2[i]==m2)break;
	}
	for(int i=1;i<=n;i++)
	{
		if(f1[i]==0)f1[i]=f1[i-1];
		if(f2[i]==0)f2[i]=f2[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,f1[i]+f2[n-i]);
		//printf("%lld %lld\n",f1[i],f2[n-i]);
	}
	printf("%lld\n",ans);
	return 0;
}

