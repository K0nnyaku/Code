#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[50005],ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=(ans%mod+((a[i]^a[j])*(a[i]^a[j]))%mod)%mod;
		}
	}
	cout<<(ans*2)%mod;
	return 0;
}
