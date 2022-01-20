#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100;
ll n,k,a[N],ans=0;
bool st[N];

int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	
	for(ll temp=1;temp<=k;temp++)
	{
		ll minn=1e9+10,maxn=0,cnt=0;
		for(ll i=1;i<=n;i++)
		{
			if(st[i]) continue;
			if(a[i]==a[i+1]&&!st[i+1]) continue;
			minn=min(minn,a[i]),maxn=max(maxn,a[i]);
			st[i]=true;
			cnt++;
			if(cnt==n/k) break;
		}
		ans+=maxn-minn;
	}
	printf("%lld\n",ans);
	return 0;
}
