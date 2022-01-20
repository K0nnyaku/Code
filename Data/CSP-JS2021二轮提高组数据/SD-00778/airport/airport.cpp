#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
using namespace std;
int n,m1,m2,maxx=0;
inline int read()
{
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		r=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();
	}
	return w*r;
}
struct node
{
	int l,r,k;
	bool operator <(const node &y)const
	{
		return r>y.r;
	}
}a[100100];
priority_queue<node>q;
bool cmp(node a,node b)
{
	return a.l<b.l; 
}
void find(int x)
{
	int ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=m1+m2;i++)
	{
		while(!q.empty())
		{
			node t=q.top();
			if(t.r>=a[i].l)
			break;
			if(t.k==1&&ans1>0)
			ans1--;
			if(t.k==2&&ans2>0)
			ans2--;
			q.pop();
		}
		if(a[i].k==1&&ans1<x)
		{
			ans1++;
			ans3++;
			q.push(a[i]);
		}
		if(a[i].k==2&&ans2<n-x)
		{
			ans2++;
			ans3++;
			q.push(a[i]);
		}
		maxx=max(maxx,ans3);
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++)
	{
		a[i].l=read();
		a[i].r=read();
		a[i].k=1;
	}
	for(int i=1;i<=m2;i++)
	{
		a[i+m1].l=read();
		a[i+m1].r=read();
		a[i+m1].k=2;
	}
	sort(a+1,a+m1+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		find(i);
	}
	printf("%d",maxx);
	return 0;
}
