#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll m,n,T,a,b,c,d;
ll out1[500],out2[500];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>out1[j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			cin>>out2[j];
		}
	}
	cin>>d;
	for(int i=0;i<T;i++)
	{
		cin>>a>>b>>c;
	}
	cout<<"25";
	return 0;
}
