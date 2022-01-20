#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
	int main()
	{
		freopen("traffic.in","r",stdin);
		freopen("traffic.out","w",stdout);
		int n,m,t;
		int a[1005][1005]
			b[1005][1005];
		
		cin>>n>>m>>t;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>b[i][j];
			}
		}
		cout<<0£» 
		return 0;
	}
