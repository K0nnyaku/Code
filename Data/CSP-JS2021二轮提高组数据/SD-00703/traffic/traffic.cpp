#include<iostream>
#include<cstdio>
using namespace std;
int n,m,T,a[10][10],b[10][10],ans;
struct add
{
	int x,p,t;
}c[100];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			ans+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=T;i++)
	{
		cin>>c[i].x>>c[i].p>>c[i].t;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
