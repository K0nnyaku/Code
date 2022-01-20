#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const long long mod=1000000007;
int n;
long long a[100001],k,ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(register int i=1;i<n;i++)
		for(register int j=i+1;j<=n;j++)
			k=a[i]^a[j],ans=(ans+k*k*2)%mod;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
