#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int l,r;
}a[100010],b[100010],a2[100010],b2[100010]; 
int n,m1,m2,l,maxn=-1;
int a1[100010],b1[100010],a3[100010],b3[100010],tot;
bool cmp(node x,node y)
{
	return x.l<y.l;
}
bool cmp1(node x,node y)
{
	return x.r<y.r;
}
priority_queue<int,vector<int>,greater<int> >q,q1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m1;i++)
		a2[i].l=i,a2[i].r=a[i].r;
	sort(a2+1,a2+m1+1,cmp1);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].l,&b[i].r);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m2;i++)
		b2[i].l=i,b2[i].r=b[i].r;
	sort(b2+1,b2+m2+1,cmp1);
	l=1;
	for(int i=1;i<=m1;i++)
	{
		while(a2[l].r<a[i].l)
			q.push(a3[a2[l].l]),++l;
		if(!q.empty())
			++a1[q.top()],a3[i]=q.top(),q.pop();
		else
			a3[i]=tot+1,a1[++tot]++;
	}
	l=1,tot=0;
	for(int i=1;i<=m2;i++)
	{
		while(b2[l].r<b[i].l)q1.push(b3[b2[l].l]),++l;
		if(!q1.empty())
			++b1[q1.top()],b3[i]=q1.top(),q1.pop();
		else
			b3[i]=tot+1,b1[++tot]++;
	}
	for(int i=1;i<=m1;i++)
		a1[i]+=a1[i-1];
	for(int i=1;i<=m2;i++)
		b1[i]+=b1[i-1];
	if(n<=max(m1,m2))
	{
		if(m1>m2)
			for(int i=0;i<=min(m1,n);i++)
			{
				if(a1[i]+b1[n-i]>maxn)
					maxn=a1[i]+b1[n-i];
			}
				
		else
			for(int i=0;i<=min(m2,n);i++)
				if(b1[i]+a1[n-i]>maxn)
					maxn=b1[i]+a1[n-i];
	}
	else
	{
		for(int i=n-m2;i<=m1;i++)
			if(a1[i]+b1[n-i]>maxn)
					maxn=a1[i]+b1[n-i];
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
