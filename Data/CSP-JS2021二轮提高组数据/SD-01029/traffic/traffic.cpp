#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,T;
	int qw_wq[101]={0,12,15,0,23,0,32,0,56,0,66,86,75,69,85,89,67,90,100,107,122,114,124,123,136,142,146,188,2021,1023};
	cin>>n>>m>>T;
	int a[10001],b[10010],c[1001];
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
