#include<iostream>
#include<cstdio>
int n,m1,m2;
int q1[100005],l1[100005],q2[100005],l2[100005],a[100005],b[100005];
int ansa[100005],ansb[100005],zong[100005];
using namespace std;
int main()
{
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout); 
		scanf("%d%d%d",&n,&m1,&m2);
		for(int i=1;i<=m1;i++)
			scanf("%d%d",&q1[i],&l1[i]);
		for(int i=1;i<=m2;i++)
			scanf("%d%d",&q2[i],&l2[i]);
		for(int i=1;i<=m1;i++)
			for(int j=m1;j>=i;j--)
				if(q1[j]<q1[j-1]&&j!=i)
				{
					int k1=q1[j],k2=l1[j];
					q1[j]=q1[j-1];l1[j]=l1[j-1];
					q1[j-1]=k1;l1[j-1]=k2;
				}
		for(int i=1;i<=m2;i++)
			for(int j=m2;j>=i;j--)
				if(q2[j]<q2[j-1]&&j!=i)
				{
					int k1=q2[j],k2=l2[j];
					q2[j]=q2[j-1];l2[j]=l2[j-1];
					q2[j-1]=k1;l2[j-1]=k2;
				}
		for(int i=0;i<=n;i++)
		{
			int a[100005]={0},b[100005]={0};
			int j=n-i;
			int aans=0,bans=0;
			for(int m=1;m<=m1;m++)
			{
				 	int x=q1[m];
 				 	for(int n=1;n<m;n++)
				 	{
						if(l1[n]<x&&a[n]==1)
						{
							a[n]=0;
							aans--;
						}
				 	}
				 	if(aans<i)
						{
							aans++;
							ansa[i]++;
							a[m]=1;
						}
			}
			for(int m=1;m<=m2;m++)
			{
				int x=q2[m];
				 	for(int n=1;n<m;n++)
				 	{
						if(l2[n]<x&&b[n]==1)
						{
							b[n]=0;
							bans--;
						}
				 	}
				 	if(bans<j)
						{
							bans++;
							ansb[i]++;
							b[m]=1;
						}
			}
		}
		for(int i=0;i<=n;i++)
		{
			zong[i]=ansa[i]+ansb[i];
		}
		int maxx=0;
		for(int i=0;i<=n;i++)
		{
			if(zong[i]>maxx)
			maxx=zong[i];
		}
		printf("%d",maxx);
		return 0;
		/*  n     廊桥个数
			  m1    国内飞机
				m2		国外飞机
				q1[n]	国内第n个飞机降落
				l1[n]	国内第n个飞机出发
				q2[n]	国外第n个飞机降落
				l2[n]	国外第n个飞机起飞
				a[n]	国内第n个飞机是否在廊桥上 
				b[n]	国外第n个飞机是否在廊桥上 
				aans	国内廊桥占用个数
				bans	国外廊桥占用个数 
				ansa	国内飞机停在廊桥总个数
				ansb	国外飞机停在廊桥总个数
		*/ 
}
