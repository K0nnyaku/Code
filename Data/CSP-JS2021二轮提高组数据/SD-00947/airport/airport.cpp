#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
using namespace std;
int re()
{
	int x=0,p=1;
	char y=getchar();
	while(y>'9'||y<'0')
	{
		if(y=='-')
		p=-1;
		y=getchar();
	}
	while(y>='0'&&y<='9')
	{
		x=10*x+y-'0';
		y=getchar();
	}
	return x*p;
}
struct ZZS
{
	int first;
	int second;
};
struct cmp
{
	bool operator() (ZZS d,ZZS e)
	{
	return	d.first>=e.first;
	}
};
struct cmm
{
	bool operator() (ZZS d,ZZS e)
	{
	return	d.second>=e.second;
	}
};
ZZS a,b,c;
priority_queue<ZZS,vector<ZZS>,cmp>q;
priority_queue<ZZS,vector<ZZS>,cmp>p;
priority_queue<ZZS,vector<ZZS>,cmp>z;
priority_queue<ZZS,vector<ZZS>,cmm>l;
int zzs[100005];
int szz[100005];
int k,n,m;
int lenth1,lenth2;
int maxx,maxx2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	k=re(),n=re(),m=re();
	for(int i=1;i<=n;++i)
	{
		 a.first=re(),a.second=re();
		q.push(a);
	}
	a=q.top();
	a.first=a.second;
	a.second=++lenth1;
	++zzs[lenth1];
	p.push(a);
	q.pop();
	while(!q.empty())
	{
		a=q.top();
		q.pop();
		b=p.top();
		if(a.first>b.first)
		{
			while(a.first>b.first&&!p.empty())
			{
				l.push(p.top());
				p.pop();
				b=p.top();
			}
			b=l.top();
			l.pop();
			++zzs[b.second];
			c.first=a.second;
			c.second=b.second;
			p.push(c);
			while(!l.empty())
			p.push(l.top()),l.pop();
		}
		else if(lenth1<k)
		{
			++zzs[++lenth1];
			c.first=a.second;
			c.second=lenth1;
			p.push(c);
		}
	}
	for(int i=1;i<=m;++i)
	{
		a.first=re(),a.second=re();
		q.push(a);
	}
	a=q.top();
	a.first=a.second;
	a.second=++lenth2;
	++szz[lenth2];
	maxx++;
	z.push(a);
	q.pop();
	while(!q.empty())
	{
		a=q.top();
		q.pop();
		b=z.top();
		if(a.first>b.first)
		{
			z.pop();
			++szz[b.second];
			++maxx;
			c.first=a.second;
			c.second=b.second;
			z.push(c);
		}
		else if(lenth2<k)
		{
			++szz[++lenth2];
			++maxx;
			c.first=a.second;
			c.second=lenth2;
			z.push(c);
		}
	}
	for(int i=0;i<=k;++i)
	{
		maxx+=zzs[i];
		maxx-=szz[k-i+1];
		maxx2=max(maxx,maxx2);
	}
	cout<<maxx2;
	return 0;
}
