#include<iostream>
#include<cstdio>
#define MOD 1000000007
#define LL long long
using namespace std;
LL n,ans;
LL a[50010];
inline LL qread()
{
	LL x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1);
		x+=ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++)
		a[i]=qread();
	for(LL i=1;i<=n;i++)
		for(LL j=i+1;j<=n;j++)
			ans+=(a[i]^a[j])*(a[i]^a[j])%MOD,ans%=MOD;
	ans*=2ll;
	ans%=MOD;
	printf("%lld",ans);
	return 0;
}
