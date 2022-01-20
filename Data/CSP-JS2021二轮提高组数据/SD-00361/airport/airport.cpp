#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int sum1,sum2,n,m1,m2,Max=-9999999;
//int n,m1,m2;
struct PM1
{
	int l,r;
}Pm1[100200];
struct PM2
{
	int l,r;
}Pm2[100200];

struct AirP1
{
	bool us;
	int l,r;
}Airp1[100200];
struct AirP2
{
	bool us;
	int l,r;
}Airp2[100200];
bool cmp1(PM1 a,PM1 b)
{
	return a.l<b.l;
}
bool cmp2(PM2 a,PM2 b)
{
	return a.l<b.l;
}
int Inboard(int lim)
{
	sum1=0;
	for(int k=1;k<=lim;k++)
		Airp1[k].us=0/*,Airp1[k].l=Pm1[k].l*/,Airp1[k].r=0;
	for(int k=1;k<=lim;k++)
		Airp1[k].us=1/*,Airp1[k].l=Pm1[k].l*/,Airp1[k].r=Pm1[k].r,sum1++;
	for(int k=lim+1;k<=m1;k++)  //Plane
		for(int x=1;x<=lim;x++)  //Airport
			if(Pm1[k].l>Airp1[x].r)
			{
				Airp1[x].r=Pm1[k].r;
				sum1++;
				break;
			}
	return sum1;
}
int Outboard(int lim)
{
	sum2=0;
	for(int k=1;k<=lim;k++)
		Airp2[k].us=0/*,Airp1[k].l=Pm1[k].l*/,Airp2[k].r=0;
	for(int k=1;k<=lim;k++)
		Airp2[k].us=1,/*Airp2[k].l=Pm2[k].l,*/Airp2[k].r=Pm2[k].r,sum2++;
	for(int k=lim+1;k<=m2;k++)  //Plane
		for(int x=1;x<=lim;x++)  //Airport
			if(Pm2[k].l>Airp2[x].r)
			{
				Airp2[x].r=Pm2[k].r;
				sum2++;
				break;
			}
	return sum2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.ans","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&Pm1[i].l,&Pm1[i].r);
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&Pm2[i].l,&Pm2[i].r);
	sort(Pm1+1,Pm1+1+m1,cmp1);
	sort(Pm2+1,Pm2+1+m2,cmp2);
	for(int i=0;i<=n;i++)
	{
		//for(int j=n-i;j>=0;j--)
		{
			//memset(,0,sizeof());
			//memset(,0,sizeof());
			int tem1=Inboard(i);
			int tem2=Outboard(n-i);
			Max=max(Max,(tem1+tem2)); 
		}
	}
	printf("%d",Max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
