#include<iostream>
#include<queue> 
#include<algorithm>
#include<cstdio>
using namespace std;
struct node
{
	long long dd,lk,f;
}a[2000000];
queue<node>q,q1;
priority_queue<int>qq,qq1;
node zz[100000];
bool cmp(node x,node y)
{
	return x.dd<y.dd;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2,i,j;
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(i=1;i<=m1;i++)
	{
		scanf("%lld %lld",&a[i].dd,&a[i].lk);
		a[i].f=0;
	}
	for(i=m1+1;i<=m1+m2;i++)
	{
		scanf("%lld %lld",&a[i].dd,&a[i].lk);
		a[i].f=1;
	} 
	sort(a+1,a+1+m1+m2,cmp);
	long long ans=0,k;
	for(i=0;i<=n;i++)
	{
		long long t=i,t1=n-i,sum=0;
		while(!q.empty()||!q1.empty())
		{
			if(!q.empty())
			q.pop();
			if(!q1.empty())
			q1.pop(); 
		}
		for(j=1;j<=m1+m2;j++)
		{
			if(a[j].f==0)
			{
				if(q.size()<t)
				{
					q.push(a[j]);
					sum++;
				}
				else if(q.size()!=0)
				{
					int top=0;
					bool f=0;
					while(!q.empty())
					{ 
						if(q.front().lk>a[j].dd)
						{
							zz[++top]=q.front();
						}
						else
						{
							f=1;
						} 
						q.pop();
					}
					for(k=1;k<=top;k++)
					{
						q.push(zz[k]);
					}
					if(f==1)
					{
					 	q.push(a[j]);
						 sum++; 	
					}
				}
			} 
			else if(a[j].f==1)
			{
				if(q1.size()<t1)
				{
					q1.push(a[j]);
					sum++;
				}
				else if(q1.size()!=0)
				{
					int top=0;
					bool f=0;
					while(!q1.empty())
					{
						if(q1.front().lk>a[j].dd)
						{
							zz[++top]=q1.front();
						}
						else
						{
							f=1;
						} 
						q1.pop();
					}
					for(k=1;k<=top;k++)
					{
						q1.push(zz[k]);
					}
					if(f==1)
					{
						q1.push(a[j]); 
						sum++;	
					}
				}
			}
		}
		ans=max(ans,sum);
	} 
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
