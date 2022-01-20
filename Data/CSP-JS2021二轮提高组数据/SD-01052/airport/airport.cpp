#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct pr
{
	int s,t;
	bool operator < (pr b) const
	{
		return s<b.s;
	}
}p[100010],q[100010];
struct segtree
{
	int l,r;
	int min;
}t[400010];
int n,m1,m2,ans;
int cntN[100010],cntY[100010];
int read()
{
	int f=1,s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return f*s;
}
void build(int l,int r,int p)
{
	t[p].l=l;t[p].r=r;t[p].min=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(l,mid,p*2);build(mid+1,r,p*2+1);
}
int getmin() {return t[1].min;}
int ask(int x,int p)
{
	if(t[p].l==t[p].r) return t[p].l;
	if(t[p*2].min<x) return ask(x,p*2);
	else return ask(x,p*2+1);
}
void change(int k,int x,int p)
{
	if(t[p].l==t[p].r)
	{
		t[p].min=x;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(k<=mid) change(k,x,p*2);
	else change(k,x,p*2+1);
	t[p].min=min(t[p*2].min,t[p*2+1].min);
}
void solve()
{
	build(1,n,1);
	for(int i=1;i<=m1;i++)
	{
		int tim=getmin();
		if(tim>=p[i].s) continue;
		int pos=ask(p[i].s,1);
		cntN[pos]++;
		change(pos,p[i].t,1);
	}
	build(1,n,1);
	for(int i=1;i<=m2;i++)
	{
		int tim=getmin();
		if(tim>=q[i].s) continue;
		int pos=ask(q[i].s,1);
		cntY[pos]++;
		change(pos,q[i].t,1);
	}
	for(int i=2;i<=n;i++)
	{
		cntN[i]+=cntN[i-1];
		cntY[i]+=cntY[i-1];
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
	{
		p[i].s=read();
		p[i].t=read();
	}
	for(int i=1;i<=m2;i++)
	{
		q[i].s=read();
		q[i].t=read();
	}
	sort(p+1,p+m1+1);
	sort(q+1,q+m2+1);
	solve();
	for(int i=0;i<=n;i++) ans=max(ans,cntN[i]+cntY[n-i]);
	printf("%d\n",ans);
	return 0;
}
