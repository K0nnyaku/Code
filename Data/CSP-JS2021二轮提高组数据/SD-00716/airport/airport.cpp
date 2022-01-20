#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long n,m1,m2;
long long cna[100005],cnb[100005],aba[100005],abb[100005];
long long allc[100005];
long long alla[100005];
long long ii;
void dfsc(long long x,long long A[],long long B[])
{
	long long all=0;
	long long book[10001]={};
	long long i=0;
	long long j=0;
	long long t[10001]={};
	for(i=1;i<=m1;i++)
	{
		for(j=1;j<=x;j++)
		{
			if(A[i]>t[j])
			{
				book[i]=1;
				t[j]=B[i];
				break;
			}
		}
	}
	for(i=1;i<=m1;i++)
	{
		if(book[i]==1)
		{
			all++;
		}
	}
	allc[ii]=all;
	return ;
} 
void dfsa(long long x,long long A[],long long B[])
{
	long long all=0;
	long long book[10001]={};
	long long  i=0;
	int j;
	int s=n;
	int t[10001]={};
	for(i=1;i<=m2;i++)
	{
		for(j=1;j<=x;j++)
		{
			if(A[i]>t[j])
			{
				book[i]=1;
				t[j]=B[i];
				break;
			}
		
		}
	}
	for(i=1;i<=m2;i++)
	{
		if(book[i]==1)
		{
			all++;
		}
	}
	alla[ii]=all;
	return ;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long i;
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++)
	{
		cin>>cna[i]>>cnb[i];
	} 
	for(i=1;i<=m2;i++)
	{
		cin>>aba[i]>>abb[i];
	}
    for(i=0;i<=n;i++)
	{
		dfsc(i,cna,cnb);
		dfsa(n-i,aba,abb);
		ii++;	
	}	
	long long sss=-1;
	for(i=0;i<ii;i++)
	{
		sss=max(sss,alla[i]+allc[i]);
	}
	cout<<sss;
	fclose(stdin);
	fclose(stdout);		
	return 0;
} 
