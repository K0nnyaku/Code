#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,m1,m2;
long long a1[100005][2],a[100005][2],b1[100005][2],b[100005][2];
long long yz (int x1)
{
	int x2=n-x1,c1=0,c2=0;
	int y1=x1,y2=x2;
	x1-=1;x2-=1;
	bool cnt=0;
	if(x1!=-1)
	{
	c1=1;
	for(int i=2;i<=m1;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i][0]>a[j][1]&&a[j][1]!=-1)
			{
				c1++;
				if(cnt==1&&x1<y1) x1++;
				a[j][1]=-1;
				cnt=1;
			}
		}
		if(cnt==0) 
		{
			if(x1==0) a[i][1]=-1;
			if(x1>0)
			{
				x1--;
				c1++;
			}
		}
		cnt=0;
	}
	}
	cnt=0;
	if(x2!=-1)
	{
	c2=1;
	for(int i=2;i<=m2;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(b[i][0]>b[j][1]&&b[j][1]!=-1)
			{
				c2++;
				if(cnt==1&&x2<y2) x2++;
				b[j][1]=-1;
				cnt=1;
			}
		}
		if(cnt==0) 
		{
			if(x2==0) b[i][1]=-1;
			if(x2>0)
			{
				x2--;
				c2++;
			}
		}
		cnt=0;
	}
	}
	return c1+c2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long ans=0,an;
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	scanf("%d %d",&a1[i][0],&a1[i][1]);
	for(int i=1;i<=m2;i++)
	scanf("%d %d",&b1[i][0],&b1[i][1]);
	for(int o=0;o<=n;o++)
	{
		for(int i=1;i<=m1;i++)
		{
			a[i][0]=a1[i][0];
			a[i][1]=a1[i][1];
		}
		for(int i=1;i<=m2;i++)
		{
			b[i][0]=b1[i][0];
			b[i][1]=b1[i][1];
		}
		an=yz(o);
		if(an>ans) ans=an;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
