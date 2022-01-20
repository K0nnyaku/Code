#include<bits/stdc++.h>
using namespace std;
long long  n,m1,m2,a1[10000]={0},a2[10000]={0},b1[10000]={0},b2[10000]={0};//分别表示廊桥的个数、国内航班飞机的数 量、国际航班飞机的数量。 
long long  time1[10000]={0},time2[10000]={0},g;
int arrive(int c)
{
	
	long long a;
	for(int x=1;x<=m1;x++)
			{
				if(a1[x]==c)
				{
					a=x;
				}
			}
	return a;
}
int arrive2(int c)
{
	
	long long a;
	for(int x=1;x<=m2;x++)
			{
				if(b1[x]==c)
				{
					a=x;
				}
				else a=0;
			}
	return a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(long long i=1;i<=m1;i++)
	{
		cin>>a1[i]>>a2[i];
	}
	for(long long i=1;i<=m2;i++)
	{
		cin>>b1[i]>>b2[i];
	}
	for(long long i=0;i<=n;i++)
	{
		time1[i]=i;
		time2[i]=n-i;
	}
	int maxtime1,maxtime2;
	for(int i=1;i<=10000;i++)
	{
		if(a1[i]>=maxtime1)
		{
			maxtime1=a1[i];
		}
	}
	for(int i=1;i<=10000;i++)
	{
		if(b1[i]>=maxtime2)
		{
			maxtime2=b1[i];
		}
	}
	int sum=0,maxsum=0;
	long long  c1[10000],num1=0,z1,c2[10000],num2=0,z2;
	for(long long i=1;i<=n*2;i++)
	{
		long long  bj1[10000],tin;
		long long  bn1[10000],tij;
		tin=time1[i+1];
		tij=time2[i+1];
		num1=0;
		num2=0;
		for(long long x=1;x<=maxtime1;x++)
			{
				for(int e=1;e<=n;e++)
				{
					bj1[e]=0;
					bn1[e]=0;
				}
				for(int o=1;o<=tin;o++)
				{
						z1=arrive(x);
						if(bn1[o]==0)
						{
							bn1[o]=a2[z1];
							num1++;
						}
						else if(bn1[o]>=x)
						{
							bn1[o]=0;
						}
				}
			}
			for(long long x=1;x<=maxtime2;x++)
			{
				for(int o=1;o<=tij;o++)
				{
					z2=arrive2(x);
						if(bj1[o]==0)
						{
							bj1[o]=b2[z2];
							num2++;
						}
						else if(bj1[o]>=x)
						{
							bj1[o]=0;
						}	
				}
			}
			sum=num1+num2;
			if(sum>=maxsum)
			{
				maxsum=sum;
			}
			sum=0;	
		}
		cout<<maxsum<<endl;
	return 0;
	} 
