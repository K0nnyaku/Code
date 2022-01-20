#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 199999
#define ll long long
using namespace std;
ll re()
{
	ll x=0,w=1;char y;
	y=getchar();
	while(y<'0'||y>'9')
	{
		if(y=='-')w=-1;y=getchar();
	}
	while(y>='0'&&y<='9')
	{
		x=x*10+y-'0';y=getchar();
	}return x*w;
}
struct air{
	ll l,r,vis;
}aig[M],aij[M];
ll n,m,mm;
ll mam=0,j_1=0,j_2=1,man=0;
ll cnt1=1,cnt2=1;
ll js1[M],js2[M];
ll ans;
bool cmp(air a,air b)
{
	return a.l <b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=re();m=re();mm=re();
	for(int i=1;i<=m;i++)
	{
		aig[i].l =re();
		aig[i].r=re();
	}
	for(int i=1;i<=mm;i++)
	{
		aij[i].l =re();
		aij[i].r =re();
	}
	sort(aig+1,aig+m+1,cmp);
	sort(aij+1,aij+mm+1,cmp);
	for(int i=0;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(aig[cnt1].r>=aig[j].l)
			{
				if(j_1>=i)continue;
				j_1++;
			}
			else if(aig[cnt1].r<aig[j].l)
			{
				cnt1=j;
				mam+=j_1;
				j_1=0;
				//if(i==0)mam=0,j_1=0;
			}
		}
		for(int j=2;j<=mm;j++)
		{
			if(aij[cnt2].r>=aij[j].l)
			{
				if(j_2>=n-i)continue;
				j_2++;
			}
			else if(aij[cnt2].r<aij[j].l)
			{
				cnt2=j;
				man+=j_2;
				j_2=0;
				if(n-i==0)man=0,j_2=0;
			}
		}
		man+=j_2;mam+=j_1;
		ans=max(man+mam,ans);
		man=0;mam=0;
		j_1=1;j_2=1;
		cnt1=1;cnt2=1;		
	}
	printf("%lld",ans);
	return 0;
}
