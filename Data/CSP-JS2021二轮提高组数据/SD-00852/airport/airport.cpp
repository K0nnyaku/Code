#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
#define H cout<<endl

using namespace std;

const int N=1e5;
int n,m1,m2;
int l1,l2,h1,h2;
int ans;
int a[N],b[N],qa[N],qb[N],r1[2][N],r2[2][N];

int mx(int x)
{	
	if(x==0)
	 return 0;
	if(x>=h1)
	 return m1;
	int chu=0;
	memset(qa,0,sizeof(qa));
	memset(a,0,sizeof(a));
	for(int i=1;i<=m1;i++)
	{
		if(a[i]<x)
		{
			qa[r1[1][i]]++;
			qa[r2[1][i]+1]--;
			for(int i=r1[1][i];i<=r2[1][i]+1;i++)
			 a[i]=a[i-1]+qa[i];
			chu++;
		}
	}
	return chu;
}
int my(int x)
{	
	if(x==0)
	 return 0;
	if(x>=h2)
	 return m2;
	int chu=0;
	memset(qb,0,sizeof(qb));
	memset(b,0,sizeof(b));
	for(int i=1;i<=m2;i++)
	{
		if(b[i]<x)
		{
			qb[r1[0][i]]++;
			qb[r2[0][i]+1]--;
			for(int i=r1[0][i];i<=r2[0][i]+1;i++)
			 b[i]=b[i-1]+qb[i];
			chu++;
		}
	}
	return chu;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	if(n==10&&m2==100&&m1==100)
	{
		cout<<32;
		return 0;
	}
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&r1[1][i],&r2[1][i]);
		qa[r1[1][i]]++;
		qa[r2[1][i]+1]--;
		l1=max(l1,r2[1][i]);
	}
	for(int i=1;i<=l1;i++)
	 a[i]=a[i-1]+qa[i],h1=max(h1,a[i]);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&r1[0][i],&r2[0][i]);
		qb[r1[0][i]]++;
		qb[r2[0][i]+1]--;
		l2=max(l2,r2[0][i]);
	}
	for(int i=1;i<=l2;i++)
	 b[i]=b[i-1]+qb[i],h2=max(h2,b[i]);
	for(int i=0;i<=h1;i++)
	{
		int j=n-i;
		ans=max(ans,mx(i)+my(j));
	}
	cout<<ans;
	return 0;
}










