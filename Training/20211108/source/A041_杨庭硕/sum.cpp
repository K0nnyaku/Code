#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int mod=1e9+7;
int num[1005],n,ans;
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%lld",&a);
		num[a]++;
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(num[i]!=0 && num[j]!=0)
			{
				ans=(ans+(i^j)*(i^j)%mod)%mod;
				ans=(ans*num[i]%mod)*num[j]%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
