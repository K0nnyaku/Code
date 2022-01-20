#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{   freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int a[100],b[100],c[100],d[100];
	int n,m1,m2,b1=1,d1=1,i,j;
	cin>>n;
	cin>>m1;
	cin>>m2;
	for( i=1;i<=m1;i++)
	cin>>a[i]>>b[i];
	for(i=1;i<=m2;i++)
	cin>>c[i]>>d[i];
	int n1,n2,sum1[100],sum2[100],sum[100];
	for(i=0;i<=100;i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
		d[i]=0;
		sum1[i]=0;
		sum2[i]=0;
		sum[i]=0;
	}	
	
	for(n1=0;n1<=n;n1++)
	{   if(n1!=0)
		{
			for(i=1;i<=m1;i++)
			{
				if(a[i+1]>=b[b1])
				b1++;
			}
			sum1[n1]+=n1;
			sum1[n1]+=b1;
			if((n1+b1)>m1)
			sum1[n1]-=(n1+b1-m1);
		}else sum1[n1]=0;
		n2=n-n1;
		if(n2!=0)
		{
			for(i=1;i<=m2;i++)
			{
				if(c[i+1]>=d[d1])
				d1++;
			}
			sum2[n1]+=n2;
			sum2[n1]+=d1;
			if((n2+d1)>m2)
			sum2[n1]-=(n2+d1-m2);
		}else sum2[n1]=0;
		sum[n1]=sum1[n1]+sum2[n1];
	}
	for(n1=0;n1<=n;n1++)
	{
		if(sum[n1+1]>sum[0])
		sum[0]=sum[n1+1];
	}
	cout<<sum[0];
	return 0;
	fclose(stdin);
	fclose(stdout);
	
 } 
