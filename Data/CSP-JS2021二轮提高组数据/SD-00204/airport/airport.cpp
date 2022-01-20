#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a[100010],b[100010],c[100010],d[100010];
long long gn[100010],gw[100010],qzgn[100010],qzgw[100010];
long long ss[100010];
long long sss[100010];
long long n,m,x,y,gns=1,gws=1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&x,&y);
	for(int i=1;i<=x;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		int ff=0;
		for(int j=1;j<=gns;j++)
		{
			if(gn[j]<=a[i])
			{
				gn[j]=b[i];
				qzgn[j]++;
				ff=1;
				break;
			}
		}
		if(ff==0)
		{
			gns++;
			qzgn[gns]++;
			gn[gns]=b[i];
		}
	}
	for(int i=1;i<=y;i++)
	{
		scanf("%lld%lld",&c[i],&d[i]);
		int ff=0;
		for(int j=1;j<=gws;j++)
		{
			if(gw[j]<=c[i])
			{
				gw[j]=d[i];
				qzgw[j]++;
				ff=1;
				break;
			}
		}
		if(ff==0)
		{
			gws++;
			qzgw[gws]++;
			gw[gws]=d[i];
		}
	}
	for(int i=1;i<=n;i++)ss[i]=ss[i-1]+qzgn[i];
	for(int i=1;i<=n;i++)sss[i]=sss[i-1]+qzgw[i];
	long long maxn=-100000;
	for(int i=0;i<=n;i++)
	{
		if(ss[i]+sss[n-i]>maxn)
		maxn=ss[i]+sss[n-i];
	}
	printf("%lld",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
