#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[5001],b[5001],c[5001];
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	cin>>b[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			c[i]=max(a[j]+b[i-j+n]%n,a[j-1]+b[i-j+1+n]%n);
		}
	for(int i=0;i<n;i++)
	cout<<c[i]<<" ";
	return 0;
}
