#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n1,m1,m2;
	cin>>n1>>m1>>m2;
	int total[n1];
	int a[n1+1][m1];
	int b[n1+1][m2];
	int num=m1;
	int m[num],n[num];
	int leave=0;
	for (int i=0;i<=n1;i++)//国内
	{
		for (int j=0;j<m1;j++)
		{
			cin>>m[i]>>n[i];
			if (i==0)
			{
				a[i][j]==0;
			}
			else if (i>0)
			{
				if (i>=m1)
				{
					a[i][j]==1;
				}
				else if (i<m1)
				{
					for (int k=0;k<i;k++)
					{
						a[i][k]==1;
					}
					leave=n[i];
					if (leave<m[i])
					{
						a[i][j+1]==1;
					}
				}
				
			}
		}
	}
	for (int i=0;i<=n1;i++)
	{
		for (int j=0;j<m1;j++)
		{
			if (a[i][j]==1)
			{
				total[i]++;
			}
		}
	}
	int total2;
	int z[m2],x[m2];
	for (int i=0;i<=n1;i++)//国外
	{
		for (int j=0;j<m1;j++)
		{
			cin>>z[i]>>x[i];
			if (i==0)
			{
				b[i][j]==0;
			}
			else if (i>0)
			{
				if (i>=m2)
				{
					b[i][j]==1;
				}
				else if (i<m2)
				{
					for (int k=0;k<i;k++)
					{
						b[i][k]==1;
					}
					leave=x[i];
					if (leave<z[i])
					{
						b[i][j+1]==1;
					}
				}
			}
		}
	} 
	for (int i=0;i<=n1;i++)
	{
		for (int f=0;f<m2;f++)
		{
			if (b[i][f]==1)
			{
				total2[n-i]++;
			}
		}
	}
	int big=0;
	for (int i=0;i<=n1;i++)
	{
		if (total[i]+total2[n-i]>=big)
		{
			big=total[i]+total2[n-i];
		}
		else 
		{
			big=big;
		}
	}
	cout<<big;
	return 0;
}
