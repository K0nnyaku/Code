#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int n,m1,m2,book1[100100],book2[1000100],sum1[100100],sum2[100100],cnt=0,ans; 
struct node1
{
	int index,dist;
	bool operator < (const node1 &x) const
	{
		return dist>x.dist;
	}
};

struct node2
{
	int index,dist;
	bool operator < (const node2 &x) const
	{
		return index>x.index;
	}
};
priority_queue<node1> q1;
priority_queue<node1> q2;
priority_queue<node2> q3;
priority_queue<node2> q4;
struct node
{
	int l,r;
}a1[100100],a2[100100];
bool cmp(const node &x,const node &y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a1[i].l,&a1[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&a2[i].l,&a2[i].r);
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	for(int i=1;i<=m1;i++)
	{
		cnt++;
		node1 t={cnt,a1[i].r};
		q1.push(t);
		while(q1.top().dist<a1[i].l&&!q1.empty())
		{
			cnt--;
			node1 o=q1.top();
			node2 u={o.index,o.dist};
			q3.push(u);
			q1.pop();
			node1 o2=q1.top();
			if(o2.index==o.index&&o2.dist==o2.index) q1.pop();
		}
		if(!q3.empty())
		{
			node2 u=q3.top();
			int x=u.index;
			node1 o={u.index,a1[i].r};
			q1.push(o);
			q3.pop();
			book1[x]++;
			continue;
		} 
		book1[cnt]++;
	}
	cnt=0;
	for(int i=1;i<=m2;i++)
	{
		cnt++;
		node1 t={cnt,a2[i].r};
		q2.push(t);
		while(q2.top().dist<a2[i].l&&!q2.empty())
		{
			cnt--;
			node1 o=q2.top();
			node2 u={o.index,o.dist};
			q4.push(u);
			q2.pop();
			node1 o2=q2.top();
			if(o2.index==o.index&&o2.dist==o2.index) q2.pop();
		}
		if(!q4.empty())
		{
			node2 u=q4.top();
			int x=u.index;
			node1 o={u.index,a2[i].r};
			q2.push(o);
			q4.pop();
			book2[x]++;
			continue;
		} 
		book2[cnt]++;
	}
	for(int i=1;i<=n;i++)
	{
		book1[i]+=book1[i-1];
		book2[i]+=book2[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,book1[i]+book2[n-i]);
	}
	//for(int i=1;i<=n;i++) cout<<book1[i]<<" ";
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
