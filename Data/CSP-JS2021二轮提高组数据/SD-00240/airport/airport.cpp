#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long 
using namespace std;
struct node
{
	ll a,b;
}mx[100009],my[100009];
ll n,ma,mb,f[100009],ans,bo,maxx;
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&ma,&mb);
	for(ll i=1;i<=ma;i++)
	scanf("%lld%lld",&mx[i].a,&mx[i].b);
	for(ll i=1;i<=mb;i++)
	scanf("%lld%lld",&my[i].a,&my[i].b);
	sort(mx+1,mx+1+ma,cmp);
	sort(my+1,my+1+mb,cmp);
	for(ll i=0;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		bo=0,maxx=0;
		for(ll j=1;j<=ma;j++)
		{
			for(ll k=1;k<j;k++)
			if(mx[j].a>mx[k].b&&f[k]==1)bo--,f[k]=0;
			if(bo<i)
			{
				bo++;
				maxx++;
				f[j]=1;
			}
		}
		memset(f,0,sizeof(f));
		bo=0;
		for(ll j=1;j<=mb;j++)
		{
			for(ll k=1;k<j;k++)
			if(my[j].a>my[k].b&&f[k]==1)bo--,f[k]=0;
			if(bo<n-i)
			{
				bo++;
				maxx++;
				f[j]=1;
			}
		}	
		ans=max(ans,maxx);
	}
	printf("%lld",ans); 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
