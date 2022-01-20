#include<bits/stdc++.h>
using namespace std;
const int maxn=50008;
const int Mod=1e9+7;
long long n,a[maxn],ans;
int main()
{
	freopen("sum.in","w",stdin);
	freopen("sum.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=(ans%Mod+((a[i]^a[j])%Mod*(a[i]^a[j])%Mod)%Mod)%Mod;
		}
	}
	cout<<ans;
	return 0;
}
