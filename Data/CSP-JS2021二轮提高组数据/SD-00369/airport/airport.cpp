#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct time
{
	int a,b;
}t1[100005],t2[100005];
bool cmp1(time x,time y)
{
	return x.a<y.a;
}
int l[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int k,n,m1,m2,maxs=0,sum=0;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>t1[i].a>>t1[i].b;
	}
	sort(t1,t1+m1,cmp1);
	for(int i=0;i<m2;i++)
	{
		cin>>t2[i].a>>t2[i].b;
	}
	sort(t2,t2+m2,cmp1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m1;j++)
		{
			for(int k=1;k<=i;k++)
			{
				if(l[k]<=t1[j].a)
				{
					l[k]=t1[j].b;
					sum++;
					break;
				}
			}
		}
		for(int j=0;j<m2;j++)
		{
			for(int k=i+1;k<=n;k++)
			{
				if(l[k]<=t2[j].a)
				{
					l[k]=t2[j].b;
					sum++;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			l[i]=0;
		}
		maxs=max(maxs,sum);
		sum=0;
	}
	cout<<maxs;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
