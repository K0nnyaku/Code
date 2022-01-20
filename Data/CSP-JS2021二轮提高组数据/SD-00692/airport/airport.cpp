#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m1,m2;
const int N=1e5+5;
struct ai
{
	int id,tim;
};
struct ww
{
	int w;
	bool operator < (const ww &n1) const 
	{
		return w > n1.w; 
	}
};
ai a[2*N];
int s[2*N],okk[N],num1[N],num2[N];
bool check[N];
priority_queue<ww> q;
bool px1(ai c,ai d)
{
	return c.tim < d.tim;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return f*x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	m1*=2,m2*=2;
	for(int i=1;i<=m1;i+=2)
	{
		int u=(i+1)/2;
		a[i].tim=read(),a[i].id=u;
		a[i+1].tim=read(),a[i+1].id=u;
	}
	sort(a+1,a+1+m1,px1);
	int v=1; 
	q.push((ww){1});
	for(int i=1;i<=m1;i++)
	{
		int u=a[i].id;
		if(!check[u])
		{
			if(!q.empty())
			{
				int t=q.top().w;
				q.pop();
				okk[u]=t;
				num1[okk[u]]++;
			}
			else
			{
				okk[u]=++v;
				num1[okk[u]]++;
			}
			check[u]=true;	
		}
		else
		{
			q.push((ww){okk[u]});
			check[u]=false;
		}
	}
	while(!q.empty())
	{
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		num1[i]+=num1[i-1];
	}
	for(int i=1;i<=m2;i+=2)
	{
		int u=(i+1)/2;
		a[i].tim=read(),a[i].id=u;
		a[i+1].tim=read(),a[i+1].id=u;
	}
	sort(a+1,a+1+m2,px1);
	v=1; 
	q.push((ww){1});
	for(int i=1;i<=m2;i++)
	{
		int u=a[i].id;
		if(!check[u])
		{
			if(!q.empty())
			{
				int t=q.top().w;
				q.pop();
				okk[u]=t;
				num2[okk[u]]++;
			}
			else
			{
				okk[u]=++v;
				num2[okk[u]]++;
			}
			check[u]=true;	
		}
		else
		{
			q.push((ww){okk[u]});
			check[u]=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		num2[i]+=num2[i-1];
	}
	int t1,t2;
	int mx=0;
	for(int i=0;i<=n;i++)
	{
		t1=i,t2=n-i;
		mx=max(mx,num1[t1]+num2[t2]);
	}
	cout<<mx<<endl;
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
