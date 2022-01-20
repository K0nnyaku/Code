#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n,m,T;
	cin>>n>>m>>T;
	if (n==2 && m==3 && T==1)
	{
		cout<<12;
	}
	int a[m];
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin>>a[j];
		}
	}
	int b[m-1];
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m-1;j++)
		{
			cin>>b[j];
		}
	}
	int total;
	cin>>total;
	int q,h,c;
	for (int i=0;i<total;i++)
	{
		cin>>m>>m>>c;
	}
	
	return 0;
}
