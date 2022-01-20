#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
using std::priority_queue;
using std::sort;
inline int read()
{
	register char c(getchar());
	register int x(0);
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
inline void write(int x)
{
	register int s[11],t(0),y;
	while(x)
	{
		y=x/10;
		s[++t]=x-(y<<1)-(y<<3);
		x=y;
	}
	while(t)putchar(s[t--]^48);
}
inline int max(int x,int y)
{
	return x^((x^y)&-(x<y));
}
int b[2][100001],c[2][100001],d[2][100001];
struct node1
{
	int a,b;
} a[2][100001];
inline bool cmp(const node1 &a,const node1 &b)
{
	return a.a<b.a;
}
struct node2
{
	int a,b;
};
inline bool operator<(const node2 &a,const node2 &b)
{
	return a.b^b.b?a.b>b.b:a.a>b.a;
}
priority_queue<node2>q;
inline int aa(int a,int x)
{
	register int l(1),m,r(b[a][0]);
	while(l<r)
	{
		m=(l+r)>>1;
		b[a][m]<x?l=m+1:r=m;
	}
	return l;
}
int main()
{
	freopen("airport.in","r",stdin);
	register int e,i(0),j(0),n(read()),m1(read()),m2(read());
	while(++i<=m1)
	{
		b[0][++b[0][0]]=a[0][i].a=read();
		b[0][++b[0][0]]=a[0][i].b=read();
	}
	i=0;
	while(++i<=m2)
	{
		b[1][++b[1][0]]=a[1][i].a=read();
		b[1][++b[1][0]]=a[1][i].b=read();
	}
	fclose(stdin);
	sort(b[0]+1,b[0]+b[0][0]+1),sort(b[1]+1,b[1]+b[1][0]+1),i=0;
	while(++i<=m1)a[0][i].a=aa(0,a[0][i].a),a[0][i].b=aa(0,a[0][i].b);
	i=0;
	while(++i<=m2)a[1][i].a=aa(1,a[1][i].a),a[1][i].b=aa(1,a[1][i].b);
	sort(a[0]+1,a[0]+m1+1,cmp),sort(a[1]+1,a[1]+m2+1,cmp),i=0;
	while(++i<=m1)
	{
		while(d[0][++j]);
		d[0][a[0][i].a]=d[0][a[0][i].b]=1,--j;
		while(!q.empty()&&j>q.top().b)
		{
			e=q.top().a;
			q.pop(),q.push(node2{e,j});
		}
		if(q.empty()||a[0][i].a<q.top().b)
		{
			++c[0][++c[0][0]];
			q.push(node2{c[0][0],a[0][i].b});
		}
		else
		{
			e=q.top().a;
			++c[0][e],q.pop(),q.push(node2{e,a[0][i].b});
		}
	}
	i=0;
	while(++i<n)c[0][i+1]+=c[0][i];
	i=j=0,q=priority_queue<node2>();
	while(++i<=m2)
	{
		while(d[1][++j]);
		d[1][a[1][i].a]=d[1][a[1][i].b]=1,--j;
		while(!q.empty()&&j>q.top().b)
		{
			e=q.top().a;
			q.pop(),q.push(node2{e,j});
		}
		if(q.empty()||a[1][i].a<q.top().b)
		{
			++c[1][++c[1][0]];
			q.push(node2{c[1][0],a[1][i].b});
		}
		else
		{
			e=q.top().a;
			++c[1][e],q.pop(),q.push(node2{e,a[1][i].b});
		}
	}
	i=0;
	while(++i<n)c[1][i+1]+=c[1][i];
	e=max(c[0][n],c[1][n]),i=0;
	while(++i<n)e=max(c[0][i]+c[1][n-i],e);
	freopen("airport.out","w",stdout);
	write(e);
	fclose(stdout);
	return 0;
}
