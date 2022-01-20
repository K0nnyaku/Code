#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#pragma GCC optimize(2)
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > q1,q2;
int c[100010],d[100100];
struct node
{
	int a,b;
}p1[100010],p2[100100];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int n,m1,m2;
int sv(int n1,int n2)
{
	int res=0;
	for(int i=1;i<=n1;i++)
	{
		res+=c[i];
	}
	for(int i=1;i<=n2;i++)
		res+=d[i];
	return res;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int n1=0,n2=0;
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&p1[i].a,&p1[i].b);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&p2[i].a,&p2[i].b);
	sort(p1+1,p1+m1,cmp);
	sort(p2+1,p2+m2,cmp);
	for(int i=1;i<=m1;i++)
	{
		int t=q1.size()+1;
		if(q1.size()&&q1.top().first<p1[i].a)
		{
			priority_queue<PII,vector<PII>,greater<PII> > q3;
			while(q1.top().first<p1[i].a&&q1.size())
			{
				q3.push({q1.top().second,q1.top().first});
				q1.pop();
			}
			t=q3.top().first,q3.pop();
			while(q3.size())
			{
				q1.push({q3.top().second,q3.top().first});
				q3.pop();
			}
		}

		q1.push({p1[i].b,t});
		c[t]++;	
	}
	n1=q1.size();
	for(int i=1;i<=m2;i++)
	{
		int t=q2.size()+1;
		if(q2.size()&&q2.top().first<p2[i].a)
		{
			priority_queue<PII,vector<PII>,greater<PII> > q3;
			while(q2.top().first<p2[i].a&&q2.size())
			{
				q3.push({q2.top().second,q2.top().first});
				q2.pop();
			}
			t=q3.top().first,q3.pop();
			
			while(q3.size())
			{
				
				q2.push({q3.top().second,q3.top().first});
				q3.pop();
			}
		}
		q2.push({p2[i].b,t});
		d[t]++;
	}
	n2=q2.size();
	if(n1+n2<=n)
		cout<<m1+m2;
	else
	{
		int maxx=0;
		for(int i=0;i<=n;i++)
		{
			int x=sv(i,n-i);
			maxx=max(x,maxx);
		}
		cout<<maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

