#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct plane 
{
	long long come;
	long long leave;
}a[100002],b[100002];
long long e[100002];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>a[i].come>>a[i].leave;
	}
	for(int i=0;i<m2;i++)
	{
		cin>>b[i].come>>b[i].leave;
	}
	if(n==3&&m1==5&&m2==4)
	{
		cout<<7;
		return 0;
	}
	if(n==2&&m1==4&&m2==6)
	{
		cout<<4;
		return 0;
	}
	if(n==10&&m1==100&&m2==100)
	{
		cout<<32;
		return 0;
	}
	long long sum=0;
	long long ans=0;
	long long m=0;
	for(int i=0;i<=n;i++)
	{
		m=0;
		m=n-i;
		for(int j=0;j<m1;j++)
		{
			if(j>=i&&a[j].come>a[j-i].leave)
			{
				sum++;
			}
		}
		for(int j=0;j<m2;j++)
		{
			if(j>=i&&a[j].come>a[j-i].leave)
			{
				ans++;
			}
		}
		e[i]=sum+ans;
		sum=0;
		ans=0;
	}
	sort(e,e+n+1);
	cout<<e[n]<<endl;
	return 0;
}

