#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,n1,n2,m1,m2,ans,sum;
priority_queue<int> q;
struct node{
	int l,r;
}a[100005],b[100005];
inline bool cmp(node a,node b)
{
	return a.l<b.l;
}
void work()
{
	int len=0;
	while(!q.empty())
		q.pop();
	for(int i=1;i<=m1;i++)
	{
		while((!q.empty())&&(-q.top())<a[i].l)
			q.pop(),len--;
		if(len<n1)
		{
			q.push(-a[i].r);
			len++;
			sum++;
		}
	}
	len=0;
	while(!q.empty())
		q.pop();
	for(int i=1;i<=m2;i++)
	{
		while((!q.empty())&&(-q.top())<b[i].l)
			q.pop(),len--;
		if(len<n2)
		{
			q.push(-b[i].r);
			len++;
			sum++;
		}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		n1=i,n2=n-i,sum=0;
		work();
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
} 
