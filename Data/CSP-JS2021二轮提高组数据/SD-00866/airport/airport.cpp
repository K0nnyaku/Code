#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int res;
struct node
{
	int co,num,v;
}a[100010],b[100010];
int now[100010];
int ans[100010],sum1[100010],sum2[100010];
priority_queue<int>q;
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=2*m1;i+=2)
	{
		scanf("%d%d",&a[i].v,&a[i+1].v);
		a[i].co=0,a[i+1].co=1;
		a[i].num=a[i+1].num=i/2+1;
	}
	for(int i=1;i<=2*m2;i+=2)
	{
		scanf("%d%d",&b[i].v,&b[i+1].v);
		b[i].co=0,b[i+1].co=1;
		b[i].num=b[i+1].num=i/2+1;
	}
	sort(a+1,a+2*m1+1,cmp);
	sort(b+1,b+2*m2+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		q.push(i);
	}
	for(int i=1;i<=2*m1;i++)
	{
		if(a[i].co==0)
		{
			now[a[i].num]=q.top();
			q.pop();
		}
		else
		{
			q.push(now[a[i].num]);
		}
	}
	for(int i=1;i<=m1;i++)
	{
		ans[m1-now[i]+1]++;
		q.pop();
	}
	for(int i=1;i<=m1;i++)
	{
		sum1[i]=sum1[i-1]+ans[i];
		ans[i]=now[i]=0;
	}
	for(int i=1;i<=m2;i++)
	{
		q.push(i);
	}
	for(int i=1;i<=2*m2;i++)
	{
		if(b[i].co==0)
		{
			now[b[i].num]=q.top();
			q.pop();
		}
		else
		{
			q.push(now[b[i].num]);
		}
	}
	for(int i=1;i<=m2;i++)
	{
		ans[m2-now[i]+1]++;
	}
	for(int i=1;i<=m2;i++)
	{
		sum2[i]=sum2[i-1]+ans[i];
	}
	for(int i=0;i<=n;i++)
	{
		res=max(res,sum1[i]+sum2[n-i]);
	}
	printf("%d",res);
	return 0;
}
