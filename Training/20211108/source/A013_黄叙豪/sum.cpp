#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010,MOD=1e9+7;
int n,ans,a[N];
signed main()
{
	clock_t c1=clock();
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);

	//======================================
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) ans=(ans+(a[i]^a[j])*(a[i]^a[j])%MOD)%MOD;
	printf("%lld",ans);	
	//======================================
	cerr<<endl<<"Time:"<<clock()-c1<<"(ms)"<<endl;
	return 0;
}
