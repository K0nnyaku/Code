#include<iostream>
#include<cstdio>
#define MOD 1000000007
#define ll long long
using namespace std;
int n;
ll a[50050],ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1+i;j<=n;j++){
			ans+=(a[i]^a[j])*(a[i]^a[j]);
			ans%=MOD;
		}
	ans=(ans*2)%MOD;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
