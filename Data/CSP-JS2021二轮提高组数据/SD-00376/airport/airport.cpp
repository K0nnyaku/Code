#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int size = 100010;
map<ll,ll> gn; map<ll,ll> gj;
ll n,m1,m2,a1,a2,ans,pd[size],vis[size];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	ll s,t;
	for(int i=1;i<=m1;i++)
	{
		scanf("%lld %lld",&s,&t); gn.insert({s,t});
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%lld %lld",&s,&t); gj.insert({s,t});
	}
	for(int i=0;i<=n;i++)
	{
		a1=0;
		for(int j=1;j<=n;j++)
			pd[j]=-1;
		for(map<ll,ll>::iterator it=gn.begin();it!=gn.end();it++)
		{
			for(int k=1;k<=i;k++)
				if(pd[k]<=(*it).first)
				{
					pd[k]=(*it).second;
					++a1; break;
				}
		}
		for(map<ll,ll>::iterator it=gj.begin();it!=gj.end();it++)
		{
			for(int k=i+1;k<=n;k++)
				if(pd[k]<=(*it).first)
				{
					pd[k]=(*it).second;
					++a1; break;
				}
		}
		ans=max(ans,a1);
	}
	cout<<ans;
	return 0;
}
