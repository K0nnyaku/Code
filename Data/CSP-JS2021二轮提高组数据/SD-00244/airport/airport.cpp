#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000100
#define ll long long
struct yy
{
	ll e;
	ll sum;
}gn[N],gj[N];
ll n,m1,m2;
ll tot1,tot2;//
ll maxn,ans;
ll ans1[N],ans2[N];
bool vis;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		vis=0;
		for(int j=1;j<=tot1;j++)
		{
			if(u>gn[j].e)
			{
				gn[j].e=v;
				gn[j].sum++;
				vis=1;
				break;
			}
		}
		if(!vis)
		{
			gn[++tot1].e=v;
			gn[tot1].sum++;
		}
	}
	for(int i=1;i<=m2;i++)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		vis=0;
		for(int j=1;j<=tot2;j++)
		{
			if(u>gj[j].e)
			{
				gj[j].e=v;
				gj[j].sum++;
				vis=1;
				break;
			}
		}
		if(!vis)
		{
			gj[++tot2].e=v;
			gj[tot2].sum++;
		}
		continue;
	}

	for(int i=1;i<=n;i++)
	{
		ans1[i]=gn[i].sum+ans1[i-1];
		ans2[i]=gj[i].sum+ans2[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		ans=ans1[i]+ans2[n-i];
		if(ans>maxn) maxn=ans;
	}
	printf("%lld",maxn);/**/
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16*/ 
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10*/
