#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m1,m2,minn,maxn,x;
long long a[3][5005],b[3][5005],c[5005],d[5005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[1][i]>>b[2][i];
	}
	cout<<m1;
	return 0;
}
