#include <bits/stdc++.h>
using namespace std;
int ans,cnta,cntb,n,ma,mb,xa[100005],ya[100005],xb[100005],yb[100005],posa[100005],posb[100005];
struct data{
	int x,y;
}f[100005];
struct data1{
	int x,y;
}g[100005];
bool pai(data a,data b)
{
	return a.x<b.x;
}
bool pai1(data1 a,data1 b)
{
	return a.x<b.x;
}
int pan(int mid)
{
	int sa=mid,sb=n-mid;
	int suma=0,sumb=0;
	memset(posa,0,sizeof(posa));
	memset(posb,0,sizeof(posb));
	cnta=0;
	cntb=0;
	for(int i=1;i<=ma;i++)
	{
		if(cnta==0&&sa!=0)
		{
			suma++;
			sa--;
			posa[++cnta]=f[i].y;
			continue;
		}
		else if(f[i].x>=posa[1]&&cnta!=0)
		{
			suma++;
			posa[1]=f[i].y;
		}
		else if(f[i].x<posa[1]&&cnta!=0)
		{
			if(sa!=0)
			{
				sa--;
				suma++;
				posa[++cnta]=f[i].y;
			}
			else
			continue;
		}
		sort(posa+1,posa+1+cnta);
	}
	for(int i=1;i<=mb;i++)
	{
		if(cntb==0&&sb!=0)
		{
			sumb++;
			sb--;
			posb[++cntb]=g[i].y;
		}
		else if(g[i].x>=posb[1]&&cntb!=0)
		{
			sumb++;
			posb[1]=g[i].y;
		}
		else if(g[i].x<posb[1]&&cntb!=0)
		{
			if(sb!=0)
			{
				sb--;
				sumb++;
				posb[++cntb]=g[i].y;
			}
		}
		sort(posb+1,posb+cntb+1);
	}
	return suma+sumb;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++)
	{
		scanf("%d%d",&f[i].x,&f[i].y);
	}
	sort(f+1,f+1+ma,pai);
	for(int i=1;i<=mb;i++)
	{
		scanf("%d%d",&g[i].x,&g[i].y);
	}
	sort(g+1,g+1+mb,pai1);
	for(int k=1;k<=n;k++)
	{
		int now=pan(k);
		if(now>=ans)
		{
			ans=now;
		}
	}
	printf("%d\n",ans);
	return 0;
}
