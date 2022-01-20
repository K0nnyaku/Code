#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int n,m1,m2;
int a[2][100005],b[2][100005];
int f1[100005],t1=1,ma1[100005],mi1,mii1;
int f2[100005],t2=1,ma2[100005],mi2,mii2;
int sum;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
		cin>>a[0][i]>>a[1][i];
	for(int i=0;i<m2;i++)
		cin>>b[0][i]>>b[1][i];//输入 
	
	for(int i=0;i<m1;i++)
		for(int j=0;j<i;j++)
		{
			if(a[0][j]>a[0][i])
			{
				swap(a[0][j],a[0][i]);
				swap(a[1][j],a[1][i]);
			}
		}
	for(int i=0;i<m2;i++)
		for(int j=0;j<i;j++)
		{
			if(b[0][j]>b[0][i])
			{
				swap(b[0][j],b[0][i]);
				swap(b[1][j],b[1][i]);
			}
		}//排序 
	
	for(int i=0;i<m1;i++)
	{
		mi1=-1;
		mii1=0;
		for(int j=1;j<t1;j++)
		{
			if(ma1[j]<a[0][i]&&ma1[j]>mi1)
			{
				mi1=ma1[j];
				mii1=j;
			}
		}
		if(mi1==-1)
		{
			f1[t1]++;
			ma1[t1]=a[1][i];
			t1++;
		}
		else
		{
			f1[mii1]++;
			ma1[mii1]=a[1][i];
		}
	}
	for(int i=0;i<n;i++)
	{
		f1[i+1]+=f1[i];
	}//计算有i条跑道时能停几架飞机 
	
	for(int i=0;i<m2;i++)
	{
		mi2=-1;
		for(int j=1;j<t2;j++)
		{
			if(ma2[j]<b[0][i]&&ma2[j]>mi2)
			{
				mi2=ma2[j];
				mii2=j;
			}
		}
		if(mi2==-1)
		{
			f2[t2]++;
			ma2[t2]=b[1][i];
			t2++;
		}
		else
		{
			f2[mii2]++;
			ma2[mii2]=b[1][i];
		}
	}
	for(int i=0;i<n;i++)
	{
		f2[i+1]+=f2[i];
	}//同上 
	 
	for(int i=0;i<=n;i++)
	{
		sum=max(sum,f1[i]+f2[n-i]);
	}
	cout<<sum;
	//输出 
	return 0;
}

