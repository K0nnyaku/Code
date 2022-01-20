#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll a[100008],ans,n;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			ll sum=a[i]^a[j]%mod;
			ans+=((sum*sum)%mod);
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
