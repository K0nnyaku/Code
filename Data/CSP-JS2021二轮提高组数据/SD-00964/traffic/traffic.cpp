#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	int t,k,n,m,map[100003][100003];
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			cin>>map[i][j];
		}
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=3;j++) cin>>map[i][k];
	}
	cout<<n*m*k;
	return 0;
}
