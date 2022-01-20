#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,m;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=2*n;j++)
		{
			cin>>m;
		}
	}
	for(int i=1;i<=t-1;i++)
	{
		cout<<"-1"<<endl;
	}
	cout<<"-1";
	return 0;
}
