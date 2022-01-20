#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e4+10;
const ll mod=1e9+7;
ll n,a[N];
ll ans=0;

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		ans=(ans+(a[i]^a[j])*(a[i]^a[j]))%mod;
	printf("%lld\n",ans);
	return 0;
}
