#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;//我是浑元形意太极门掌门人马保国 
int n,m1,m2;
struct pa{
	int a,b;
	static bool cmp(pa p1,pa p2){
		return p1.a<p2.a;
	}
}p1[100003],p2[100003];
struct lang{
	int la=0,lb=0;
	int num=0;
}ap1[100003],ap2[100003];
int arr;
int sum1[100003],sum2[100003],sum;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)
	{scanf("%d%d",&p1[i].a,&p1[i].b);}
	for(int i=0;i<m2;i++)
	{scanf("%d%d",&p2[i].a,&p2[i].b);}
	sort(p1,p1+m1,pa::cmp);
	sort(p2,p2+m2,pa::cmp);
	for(int i=0;i<m1;i++)
	{
		int ava=0;
		while(p1[i].a<ap1[ava].lb)
		{
			ava++;
		}
		ap1[ava].la=p1[i].a;
		ap1[ava].lb=p1[i].b;
		ap1[ava].num++;
	}
	for(int i=0;i<m2;i++)
	{
		int ava=0;
		while(p2[i].a<ap2[ava].lb)
		{
			ava++;
		}
		ap2[ava].la=p2[i].a;
		ap2[ava].lb=p2[i].b;
		ap2[ava].num++;
	}
	sum1[0]=ap1[0].num;
	sum2[0]=ap2[0].num;
	for(int i=1;i<m1;i++)
	{
		sum1[i]=ap1[i].num+sum1[i-1];
	}
	for(int i=1;i<m2;i++)
	{
		sum2[i]=ap2[i].num+sum2[i-1];
	}
	for(arr=0;arr<=n;arr++)
	{
		if(arr==0){sum=max(sum,sum2[n-1]);}
		else if(arr==n){sum=max(sum,sum1[n-1]);}
		else{
			sum=max(sum,sum1[arr-1]+sum2[n-arr-1]);
		}
	}
	printf("%d",sum);//年轻人不讲武德 
	return 0;//耗子尾汁 
}
