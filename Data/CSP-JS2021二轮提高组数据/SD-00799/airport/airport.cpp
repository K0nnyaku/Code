#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long m,n,m1,m2;
	int i,j;
	int a[6000],f[6000];
	cin>>n>>m1>>m2;
	for(int l=1;l<=m1+m2;l++)
	{
	for(int i=1;i<=m1;i++)
	{
		int a[6000];
		cin>>a[i];
	}		
	for(int j=1;j<=m2;j++)
	{
		int f[6000];
		cin>>f[j];
	}
	if(a[0]>a[i]&&f[0]>f[j])
	{
		m=n+1;
	}
	if(a[i]>a[i+1]&&f[i]>f[i+1])
	{
		m=n+1;
	}
		cout<<m;
	}
	return 0;
}
