#include <iostream>
#include <stdio.h>
using namespace std;
const int M=100005;
int n,m1,m2,sum=-1,minnc;
int a1[M],b1[M],c1[M];
int a2[M],b2[M],c2[M];
void ssort()
{
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a1[i],&b1[i]);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&a2[i],&b2[i]);
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=m1;j++)
			if(a1[j-1]>a1[j])
			{
				swap(a1[j],a1[j-1]);
				swap(b1[j],b1[j-1]);
			}
	for(int i=1;i<=m2;i++)
		for(int j=1;j<=m2;j++)
			if(a2[j-1]>a2[j])
			{
				swap(a2[j],a2[j-1]);
				swap(b2[j],b2[j-1]);
			}
}
void check(int x)
{
	if(x==-1) return;
	int t=0;//计数,和sum比较 
	int t1=0,t2=0;//国内和国外廊桥数 
	int xx=n-x;//国外廊桥数 
	if(x){
	for(int i=1;i<=m1;i++)//取点 
	{
		if(t1<x) //能停 
		{
			t++;
			t1++;
			c1[t1]=b1[i];//记录当前飞机要离开的时刻 
			if(t1==x)
			{
				for(int k=1;k<=t1;k++)
					for(int j=1;j<=t1;j++)
					if(c1[j]<c1[j-1]) 
						swap(c1[j],c1[j-1]); 
			}
			continue;
		}
		if(a1[i]>c1[1])
		{ 
			c1[1]=b1[i];
			for(int j=2;j<=x;j++)
				if(c1[j-1]>c1[j]) swap(c1[j],c1[j-1]);
			t++;
		}
	}
	}
	if(xx) {
	for(int i=1;i<=m2;i++)
	{
		if(t2<xx) 
		{
			t++;
			t2++;
			c2[t2]=b2[i];
			if(t2==xx)
			{
				for(int k=1;k<=xx;k++)
					for(int j=1;j<=xx;j++)
					if(c2[j]<c2[j-1]) 
						swap(c2[j],c2[j-1]); 
			}
			continue;
		}
		if(a2[i]>c2[1])
		{ 
			c2[1]=b2[i];
			for(int j=2;j<=xx;j++)
				if(c2[j]<c2[j-1]) swap(c2[j],c2[j-1]);
			t++;
		}
	}
	}
	if(t>sum) sum=t;
	check(x-1);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ssort();
	check(n);
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 
