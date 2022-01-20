#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int m1,m2,n,a[100001][2],b[100001][2],ans=0,c[100001]={0};
int a1[100001],b1[100001];
int a2[100001],b2[100001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airprot.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j][0]>a[j+1][0]){
				swap(a[j][0],a[j+1][0]);
				swap(a[j][1],a[j+1][1]);
			}
		} 
	}
	for(int i=1;i<=m2;i++)
		cin>>b[i][0]>>b[i][1];
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(b[j][0]>b[j+1][0])
			{
				swap(b[j][0],b[j+1][0]);
				swap(b[j][1],b[j+1][1]);
			}
		} 
	}
	//int maxt=max(a[m1][0]+1,b[m2][0]+1);
	for(int i=1;i<=m1;i++)
	{
		int max1=0;
		for(int j=a[i][0];j<=a[i][1];j++)
		{
			a1[j]++;
			max1=max(a1[j],max1);
		}
		a2[max1]++;
	}
	for(int i=1;i<=m2;i++)
	{
		int max1=0;
		for(int j=b[i][0];j<=b[i][1];j++)
		{
			b1[j]++;
			max1=max(b1[j],max1);
		}
		b2[max1]++;
	}
	for(int i=0;i<=n;i++)
	{
		int sum1=0,sum2=0;
		for(int j=0;j<=i;j++)
			sum1+=a2[j];
		for(int j=0;j<=n-i;j++)
			sum2+=b2[j];
		ans=max(sum1+sum2,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
