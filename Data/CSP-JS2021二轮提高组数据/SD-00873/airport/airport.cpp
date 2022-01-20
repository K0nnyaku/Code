#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;int temp1;long long temp;
int n;int m1,m2;int flag1[100030];int Tier1=0;int Tier2=0;int flag2[100030];
struct PLA1
{
	long long a;long long b;
}nei[100030];
struct time
{
	long long shijian;int Tier;
};
time TT;
queue <PLA1> rua[3];
queue <time> timetogo[3];
PLA1 wai[100030];
int main()
{	
	freopen("airport1.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m1);scanf("%d",&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d",&nei[i].a);scanf("%d",&nei[i].b);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d",&wai[i].a);scanf("%d",&wai[i].b);
	}
	if(n>=(m1+m2))
	{
		printf("%d",m1+m2);return 0;
	}
	for(int i=1;i<=m1;i++)
		{
			temp=0xffff;temp1=0xffff;
			for(int j=1;j<=m1;j++)
			{
				if(temp>nei[j].a)
				{
					temp1=j;
					temp=nei[j].a;
				}
			}
			rua[1].push(nei[temp1]);
			nei[temp1].a=0xffff;
		}
	for(int i=1;i<=m2;i++)
		{
			temp=0xffff;temp1=0xffff;
			for(int j=1;j<=m2;j++)
			{
				if(temp>wai[j].a)
				{
					temp1=j;
					temp=wai[j].a;
				}
			}
			rua[2].push(wai[temp1]);
			wai[temp1].a=0xffff;
		}

	PLA1 tem;
	while(rua[1].size()!=0)
	{
	tem=rua[1].front();rua[1].pop();
	Tier1++;
	while(1)
	{
		if(timetogo[1].size()!=0&&tem.a>=timetogo[1].front().shijian)
		{
			Tier1=timetogo[1].front().Tier;
			timetogo[1].pop();Tier1--;
		}
		else break;
	}
	for(int i=Tier1;i<=n;i++)flag1[i]++;
	TT.shijian=tem.b;TT.Tier=Tier1; 
	timetogo[1].push(TT);
	}

	tem=rua[2].front();
	while(rua[2].size()!=0)
	{
	tem=rua[2].front();rua[2].pop();
	Tier2++;
	while(1)
	{
		if(timetogo[2].size()!=0&&tem.a>=timetogo[2].front().shijian)
		{
			Tier2=timetogo[2].front().Tier;
			timetogo[2].pop();
		}
		else break;
	}
	for(int i=Tier2;i<=n;i++)flag2[i]++;
	TT.shijian=tem.b;TT.Tier=Tier2; 
	timetogo[2].push(TT);
	}
	int gg=0;
	for(int i=0;i<=n;i++)
	{
		gg=max(gg,flag1[i]+flag2[n-i]);
	}
	printf("%d",gg);
	return 0;
}
