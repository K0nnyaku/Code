#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int n,m1,m2,ans=-1;
priority_queue <int> q;
struct node1
{
	int l,r;
}e1[100005];
struct node2
{
	int l,r;
}e2[100005];
int cmp1(node1 a,node1 b)
{
	return a.l<b.l;
}
int cmp2(node2 a,node2 b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)
	{
		scanf("%d %d",&e1[i].l,&e1[i].r);
	}
	for(int i=0;i<m2;i++)
	{
		scanf("%d %d",&e2[i].l,&e2[i].r);
	}
	sort(e1,e1+m1,cmp1);
	sort(e2,e2+m2,cmp2);
	
	int f,l1,l2;
	for(int i=0;i<=n;i++)
	{
		l1=i;
		f=0;
		if(l1!=0)
		{
			for(int j=0;j<m1;j++)
			{
				if(q.size()<l1)
				{
					q.push(-e1[j].r);
					f++;
				}
				else
				{
					if((-q.top())<=e1[j].l)
					{
						q.pop();
						q.push(-e1[j].r);
						f++;
					}
				}
			}			
		}

		while(q.size()!=0)
			q.pop();
		l2=n-i;
		if(l2!=0)
		{
			for(int j=0;j<m2;j++)
			{
				if(q.size()<l2)
				{
					q.push(-e2[j].r);
					f++;
				}
				else
				{
					if((-q.top())<=e2[j].l)
					{
						q.pop();
						q.push(-e2[j].r);
						f++;
					}
				}
			}			
		}
		while(q.size()!=0)
			q.pop();
		if(f>ans)
			ans=f;
	}
	
	printf("%d\n",ans);
	return 0;
}
