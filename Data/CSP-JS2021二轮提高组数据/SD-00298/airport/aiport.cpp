#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int read()
{
	int an=0,f=1;
	char a;
	a=getchar();
	while(a!='-'&&(a<'0'||a>'9'))
	{
		a=getchar();
	}
	if(a=='-')
	{
		f=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		an=an*10+a-'0';
		a=getchar();
	}
	return an*f;
}
struct air
{
	long long start,finish;
};
int cmp(air o,air p)
{
	return o.start<p.start;
}
long long n,m1,m2,ans=0,maxn=0;
air in[100001],out[100001];
int time[100000008]={0,};
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		in[i].start=read();
		in[i].finish=read();
	}
	for(int i=1;i<=m2;i++)
	{
		out[i].start=read();
		out[i].finish=read();
	}
	sort(in+1,in+m1+1,cmp);
	sort(out+1,out+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int num_in=i;
		int num_out=n-i;
		ans=0;
		for(int j=1;j<=100000001;j++)
		{
			time[j]=0;
		}
		if(num_in!=0)
		{
			for(int j=1;j<=m1;j++)
			{
				if(time[in[j].start]<num_in)
				{
					for(int k=in[j].start;k<=in[j].finish;k++)
					{
						time[k]++;
					}
					ans++;
				}
			}
		}
		for(int j=1;j<=100000001;j++)
		{
			time[j]=0;
		}
		if(num_out!=0)
		{
			for(int j=1;j<=m2;j++)
			{
				if(time[out[j].start]<num_out)
				{
					for(int k=out[j].start;k<=out[j].finish;k++)
					{
						time[k]++;
					}
					ans++;
				}
			}
		}
		if(maxn<ans)
		{
			maxn=ans;
		}
	}
	cout<<maxn<<endl;
	return 0;
 } 
