#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[101];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	if(n==k)
	{
		for(int i=0;i<n;i++)
		ans+=a[i];
		cout<<ans;
		return 0;
	}
/*	sort(a,a+n);
	for(int i=0;i<n;i++)
	for(int j=i;j<n;j++)
	{
		if(a[i]!=a[j]&&a[j]!=0)
		{
			ans+=a[j]-a[i];
			a[j]=0;
		}
	}*/
}
