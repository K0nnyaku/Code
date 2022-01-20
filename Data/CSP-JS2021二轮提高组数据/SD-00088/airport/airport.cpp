#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m1,m2;
int maxx;
struct fj
{
	int a;
	int b;
};
fj gn[100010],gw[100010];
inline int js1(int k)
{
	priority_queue<int>q;
	int aans=0;
	for(int i=1;i<=m1;i++)
	{
		int now=gn[i].a ;
		while(!q.empty()&&q.top()>=-now)
		{
			q.pop();
		}
		if(q.size()<k)
		{
			q.push(-gn[i].b );
			aans++;
		}
	}
	return aans;
}
inline int js2(int k)
{
	priority_queue<int>q;
	int aans=0;
	for(int i=1;i<=m2;i++)
	{
		int now=gw[i].a ;
		while(!q.empty()&&q.top()>=-now)
		{
			q.pop();
		}
		if(q.size()<k)
		{
			q.push(-gw[i].b );
			aans++;
		}
	}
	return aans;
}
bool cmp(const fj &aa,const fj &bb)
{
	return aa.a <bb.a ;
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
		gn[i].a =read();
		gn[i].b =read();
	}
	for(int i=1;i<=m2;i++)
	{
		gw[i].a =read();
		gw[i].b =read();
	}
	sort(gn+1,gn+1+m1,cmp);
	sort(gw+1,gw+1+m2,cmp);
	for(int i=0;i<=n;i++)
	{
		maxx=max(maxx,js1(i)+js2(n-i));
	}
	printf("%d\n",maxx);
	return 0;
}
