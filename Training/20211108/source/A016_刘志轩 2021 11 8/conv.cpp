#include<bits/stdc++.h>
using namespace std;
const int maxn=200008;
int n,a[maxn],b[maxn],c[maxn];
int main()
{
	freopen("conv.in","w",stdin);
	freopen("conv.out","r",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++)
		cin>>a[i];
	for(int i=0;i<=n-1;i++)
		cin>>b[i];
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			c[i]=max(c[i] , (a[j]+b[(i-j+n)%n]));
		} 
	} 
	for(int i=0;i<n;i++)
		cout<<c[i]<<" ";
	return 0;
} 
