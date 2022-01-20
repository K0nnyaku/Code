#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,m,t;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int x;
			cin>>x;
		}
	}
	while(t--)
	{
		int k;
		cin>>k;
		int k1[3],k2[3],k3[3];
		for(int i=1;i<=k;i++)
		{
			cin>>k1[i]>>k2[i]>>k3[i];
		}
		if(k==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(k==2)
		{
			if(k3[1]==k3[2])
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<min(k1[1],k1[2])<<endl;
				continue; 
			}
		}
	}
	return 0;
}
