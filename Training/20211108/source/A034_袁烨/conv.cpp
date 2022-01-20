#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],maxx,id;
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxx<a[i])
		{
			maxx=a[i];
			id=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
//		if(i>(n-1)/2+1)
//		swap(b[i],b[n-i+2]);
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i]=max(c[i],b[(i-j+n)%n+1]+a[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
	}
}
