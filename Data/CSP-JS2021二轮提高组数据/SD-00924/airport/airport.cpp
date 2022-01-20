#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m1,m2,xh;
struct ap
{
	int fm;
	int to; 
}; 
ap h1[maxn],h2[maxn];
int cmp(ap a,ap b)
{
	return a.fm<b.fm;
}
int num1[maxn],num2[maxn],sum1=0,sum2=0,s1=0,s2=0,mx=0;
int ss1[maxn],ss2[maxn],d1[maxn],d2[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>h1[i].fm>>h1[i].to; 
	}
	sort(h1+1,h1+m1+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		if(i==1)
		{
			sum1=1;
			num1[1]=h1[i].to;
			ss1[1]=1;
		}
		else
		{
			xh=0;
			for(int j=1;j<=sum1;j++)
			{
				if(h1[i].fm>num1[j])
				{
					num1[j]=h1[i].to;
					xh=1;
					ss1[j]++;
					break;
				}	
			}
			if(xh==0)
			{
				sum1++;
				num1[sum1]=h1[i].to;
				ss1[sum1]=1;
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>h2[i].fm>>h2[i].to; 
	}
	sort(h2+1,h2+m2+1,cmp);
	for(int i=1;i<=m2;i++)
	{
		if(i==1)
		{
			sum2++;
			num2[sum2]=h2[i].to;
			ss2[sum2]=1;
		}
		else
		{
			xh=0;
			for(int j=1;j<=sum2;j++)
			{
				if(h2[i].fm>num2[j])
				{
					num2[j]=h2[i].to;
					xh=1;
					ss2[j]++;
					break;
				}
			}
			if(xh==0)
			{
				sum2++;
				num2[sum2]=h2[i].to;
				ss2[sum2]++;
			}
		}
	}
	for(int i=1;i<=sum1;i++)
	{
		d1[i]=d1[i-1]+ss1[i];
	}
	for(int i=1;i<=sum2;i++)
	{
		d2[i]=d2[i-1]+ss2[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(d1[i]+d2[n-i]>mx)
		{
			mx=d1[i]+d2[n-i];
		}
	}
	cout<<mx<<endl;
/*	for(int i=0;i<=10;i++)
	{
		cout<<d2[i]<<endl;
	}*/
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
