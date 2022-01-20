#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int nlangqiao, mnational, minternational;
int a[5001][101]={0},b[5001][101]={0};
int nationalarrival[5001], nationaldeparture[5001], internationalarrival[5001], internationaldeparture[5001];
int finter(int emps1)
{
	int ans1=0; 
	for(int i=1;i<=minternational;i++)
	{
		for(int k=1;k<=emps1;k++)
		{
			if(b[internationalarrival[i]][k]==0)
			{
				ans1++;
				for(int j=internationalarrival[i];j<=internationaldeparture[i];j++)
				{
					b[j][k]=1;
				}
				break;
			}
		}
	}
	for(int i=1;i<=5001;i++)
		for(int j=1;j<=101;j++)
		{
			b[i][j]=0;
		}
	return ans1;
}
int fna(int emps2)
{
	int ans2=0; 
	for(int i=1;i<=mnational;i++)
	{
		for(int k=1;k<=emps2;k++)
		{
			if(a[nationalarrival[i]][k]==0)
			{
				ans2++;
				for(int j=nationalarrival[i];j<=nationaldeparture[i];j++)
				{
					a[j][k]=1;
				}
				break;
			}
		}
	}
	for(int i=1;i<=5001;i++)
		for(int j=1;j<=101;j++)
		{
			a[i][j]=0;
		}
	return ans2;
}
int main()
{
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    cin>>nlangqiao>>mnational>>minternational;
    for(int i=1;i<=mnational;i++)
    {
    	cin>>nationalarrival[i]>>nationaldeparture[i];
	}
	for(int i=1;i<=minternational;i++)
    {
    	cin>>internationalarrival[i]>>internationaldeparture[i];
	}
	for(int i=1;i<=mnational-1;i++)
		for(int j=mnational;j>i;j--)
		{
			if(nationalarrival[i]>nationalarrival[j])
			{
				int k=nationalarrival[i];
				nationalarrival[i]=nationalarrival[j];
				nationalarrival[j]=k;
				int q=nationaldeparture[i];
				nationaldeparture[i]=nationaldeparture[j];
				nationaldeparture[j]=q;
			}
		}
	for(int i=1;i<=minternational-1;i++)
		for(int j=minternational;j>i;j--)
		{
			if(internationalarrival[i]>internationalarrival[j])
			{
				int k=internationalarrival[i];
				internationalarrival[i]=internationalarrival[j];
				internationalarrival[j]=k;
				int q=internationaldeparture[i];
				internationaldeparture[i]=internationaldeparture[j];
				internationaldeparture[j]=q;
			}
		}
	int anss=-1;
	int r[101],p[101];
	for(int i=0;i<=nlangqiao;i++)
	{
		r[i]=fna(i);
	}
	for(int i=0;i<=nlangqiao;i++)
	{
		p[i]=finter(nlangqiao-i);
	}
	for(int i=0;i<=nlangqiao;i++)
	{
		anss=max(anss,p[i]+r[i]);
	}
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

