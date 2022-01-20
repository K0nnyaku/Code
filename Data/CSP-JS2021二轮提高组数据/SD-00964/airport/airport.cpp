#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll n,m1,m2,ans;
struct node{
	int a;
	int b;
	int mark;
}plane[100010];
int num[100010],que[100010],num1[100010],que1[100010];
int vis[100010]={0};
int max(int a,int b)
{
	if(a>=b) return a;
	if(a<=b) return b;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1+m2;i++)
	{
		scanf("%d%d",&plane[i].a,&plane[i].b);
		plane[i].mark=i;
		num[i]=plane[i].a;
		num1[i]=plane[i].b;	
	}
	sort(num+1,num+m1+m2+1);
	sort(num1+1,num1+m1+m2+1);
	for(int i=1;i<=m1+m2;i++)
	{	
		for(int j=1;j<=m1+m2;j++)
		{
			if(num[i]==plane[j].a)
			{
				que[i]=plane[j].mark;
				continue;
			}
		}
	}
	for(int i=1;i<=m1+m2;i++)
	{	
		for(int j=1;j<=m1+m2;j++)
		{
			if(num1[i]==plane[j].b)
			{
				que1[i]=plane[j].mark;
				continue;
			}
		}
	}
	int port1=0,port2=0,now1=1,now2=1,sum=0;
	for(int i=0;i<=n;i++)
	{
		port1=i;
		port2=n-port1;
		for(int tim=0;tim<=plane[que1[m1+m2]].b;tim++)
		{
			if(tim==plane[que[now1]].a)
			{
				if(port1>=1&&que[now1]<=m1) 
				{
					port1=port1-1;
					vis[que[now1]]=1;
					sum++;
				}
				if(port2>=1&&que[now1]>m1)
				{
					port2=port2-1;	
					vis[que[now1]]=1;
					sum++; 
				}
				now1++;
				continue;
			}
			if(tim==plane[que1[now2]].b)
			{
				if(que1[now2]<=m1&&vis[que1[now2]]==1)
				{
					port1+=1;
				}
				if(que1[now2]>m1&&vis[que1[now2]]==1)
				{
					port2+=1;
				}
				now2+=1;
			}
		}
		ans=max(ans,sum);
		sum=0;
		int vis[100010]={0};
		now1=1;
		now2=1;
	}
	cout<<ans;
	return 0;
}
