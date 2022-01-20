#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[10001];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			ans+=(a[i]^a[j])*(a[i]^a[j]);
		}
	cout<<ans%9000000007<<endl;
	return 0;
}
