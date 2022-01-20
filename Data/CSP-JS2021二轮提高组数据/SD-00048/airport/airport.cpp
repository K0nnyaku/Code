#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct k
{
	int hd;
	int tl;
}a[100001],b[100001];
bool cmp(k p,k q)
{
	return p.hd<q.hd;
}
int n,m1,m2,ans;
int gn,gj,x[100001],y[100001],cnt1,cnt2,mx=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n;
	cin>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>a[i].hd>>a[i].tl;
	for(int i=1;i<=m2;i++)cin>>b[i].hd>>b[i].tl;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		cnt1=0,cnt2=0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		gn=i;
		gj=n-i;
		for(int j=1;j<=m1;j++)
		{
			if(gn>0)
			{
				gn--;
				cnt1++;
				for(int k=0;k<i;k++)
					if(x[k]==0)
					{
						x[k]=a[j].tl;
						break;
					}
			}
			else
			{
				for(int k=0;k<i;k++)
					if(x[k]<a[j].hd)
					{
						gn++;
						x[k]=0;
					}
				if(gn>0)
				{
					gn--;
					cnt1++;
					for(int k=0;k<i;k++)
						if(x[k]==0)
						{
							x[k]=a[j].tl;
							break;
						}
				}
			}
		}
		for(int j=1;j<=m2;j++)
		{
			if(gj>0)
			{
				gj--;
				cnt2++;
				for(int k=0;k<n-i;k++)
					if(y[k]==0)
					{
						y[k]=b[j].tl;
						break;
					}
			}
			else
			{
				for(int k=0;k<n-i;k++)
					if(y[k]<b[j].hd)
					{
						gj++;
						y[k]=0;
					}
				if(gj>0)
				{
					gj--;
					cnt2++;
					for(int k=0;k<n-i;k++)
						if(y[k]==0)
						{
							y[k]=b[j].tl;
							break;
						}
				}
			}
		}
		int rrrr=cnt1+cnt2;
		if(mx<rrrr)mx=rrrr;
	}
	cout<<mx;
	return 0;
}
