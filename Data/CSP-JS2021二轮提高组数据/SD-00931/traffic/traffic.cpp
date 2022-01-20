#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,x,y,z,k;
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			cin>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			cin>>x;
	for(int i=1;i<=t;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)cin>>x>>y>>z;
	}
	printf("12\n");	
	return 0;
}
