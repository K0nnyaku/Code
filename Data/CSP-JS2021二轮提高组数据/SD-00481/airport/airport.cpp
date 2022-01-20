#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int size = 1e5+10;
struct node
{
	long long st,en;
}ft1[size],ft2[size],pre1[size],pre2[size];
int f1[size],f2[size];
long long ans;
bool cmp(node a,node b)
{
	return a.st<b.st;
}

int main()
{
	//É¾×¢ÊÍ É¾×¢ÊÍ É¾×¢ÊÍ É¾×¢ÊÍ É¾×¢ÊÍ 
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2;
	cin>>n>>m1>>m2;
	if(n>=m1+m2)
	{
		cout<<m1+m2;
	}
	for(int i=1;i<=m1;i++)
	{
		int a;int b;
		cin>>a>>b;
		ft1[i].st=a;ft1[i].en=b;
	}
	for(int i=1;i<=m2;i++)
	{
		int a;int b;
		cin>>a>>b;
		ft2[i].st=a;ft2[i].en=b;
	}
	sort(ft1+1,ft1+1+m1,cmp);
	sort(ft2+1,ft2+1+m2,cmp);
	
	long long a,b;
	for(int k=0;k<=n;k++)
	{
		for(int i=1;i<=m1;i++)
		{
			pre1[i]=ft1[i];
		}
		for(int i=1;i<=m2;i++)
		{
			pre2[i]=ft2[i];
		}
		long long t1=0;
		for(int i=k+1;i<=m1;i++)
		{
			if(pre1[i].st<pre1[i-k].en)
			{
				t1++;
				//pre1[i].en=pre1[i-1].en;//·½±ãºóÃæÔÙ½øÐÐ±È½Ï
				
				for(int j=i;j>=i-k+1;j--)
				{
					pre1[j].en=pre1[j-1].en;
				}
			}
		}
		if(k==0)
		{
			t1=m1;
		}
		long long t2=0;
		int k2=n-k;
		for(int i=k2+1;i<=m2;i++)
		{
			if(pre2[i].st<pre2[i-k2].en)
			{
				t2++;
				//pre2[i].en=pre2[i-1].en;
				for(int j=i;j>=i-k2+1;j--)
				{
					pre2[j].en=pre2[j-1].en;
				}
			}
		}
		if(k==n)
		{
			t2=m2;
		}
		ans=max(ans,m1+m2-t1-t2);
	}
	cout<<ans<<endl;
//	cout<<b;
//	cout<<a<<endl<<b;
	return 0;
 } 
