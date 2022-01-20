#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2,s=1,si=1;
int maxs,ans,end1,endm;
struct node{
	int begin1,end2;
}nation1[100009],ination1[100009];
int numn[100009],numi[100009],leaven[100009],leavei[100009];
int cmp(node a,node b)
{
	return a.begin1<b.begin1;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	printf("%d\n",n);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&nation1[i].begin1,&nation1[i].end2);//输入国内区的开始结束时间 
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&ination1[i].begin1,&ination1[i].end2);//输入国际区的开始结束时间 
	}
	if(n==m1+m2)
	{
		printf("%d",n);
		return 0;
	}
	sort(nation1+1,nation1+m1+1,cmp);
	sort(ination1+1,ination1+m2+1,cmp);
	for(int x=0;x<=n;x++)
	{
		ans=0;s=1;si=1;
		int sum=0,sumi=0;
		int cnt=x,cnti=n-x;
		if(cnt!=0)
		{
			for(int i=1;i<=cnt;i++)
				numn[i]=0;
			for(int i=1;i<=m1;i++)//枚举国内飞机 
			{
				if(sum==cnt)
				{
					for(int j=s;j<=i;j++)
					{
						if(nation1[j].end2<=nation1[i].begin1&&j!=i)
						{
							sum--;
							numn[j]=0;
							if(sum<=0)
							{
								sum=0;
								break;
							}
						}
						else 
						{
							s=j+1;
							if(j==1)s=1;
							else s=j-1;
							break;
						}
					}
				}
				if(sum==cnt)continue;
				ans++;
				sum++;
				for(int j=1;j<=cnt;j++)//将飞机停放在廊桥上
				{
					if(numn[j]==0)
					{
						numn[j]=i;
						break;
					}
				}
			}
		}
		if(cnti!=0)
		{
			for(int i=1;i<=cnti;i++)
				numi[i]=0;
			for(int i=1;i<=m2;i++)//枚举国外飞机 
			{
				if(sumi==cnti)
				{
					for(int j=si;j<=i;j++)
					{
						if(ination1[j].end2<=ination1[i].begin1&&j!=i)
						{
							sumi--;
							numi[j]=0;
							if(sumi<=0)
							{
								sumi=0;
								break;
							}
						}
						else 
						{
							if(j==1)si==1;
							else si=j-1;
							break;
						}
					}
				}
				if(sumi==cnti)continue;
				ans++;
				sumi++;
				for(int j=1;j<=cnti;j++)
				{
					if(numi[j]==0)
					{
						numi[j]=i;
						break;
					}
				}
			}
		}
		maxs=max(maxs,ans);
	}
	printf("%d",maxs);
	return 0;
}
