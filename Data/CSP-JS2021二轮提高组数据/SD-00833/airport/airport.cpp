#include<bits/stdc++.h>
using namespace std;//21!9-324@emb
#define N 100005
struct node1
{
	int s,t;
}a[N];
struct node2
{
	int s,t;
}b[N];
int ans=0,n,m1,m2;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		    f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void input()
{
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;++i)
	{
		a[i].s=read();
		a[i].t=read();
	}
	for(int i=1;i<=m2;++i)
	{
		b[i].s=read();
		b[i].t=read();
	}
}
bool cmp1(node1 a1,node1 a2)
{
	return a1.s<a2.s;
}
bool cmp2(node2 b1,node2 b2)
{
	return b1.s<b2.s;
}
int check(int s1,int s2)
{
	int res=m1+m2,sizz=0;
	priority_queue<int>q1;
	for(int i=1;i<=m1;++i)
	{	
		while(sizz>0)
		{
			if(-q1.top()<a[i].s)
			{
	    		--sizz;
	    		q1.pop();
	    	}
	    	else
	    	    break;
		}
		if(sizz<s1)
		{
			++sizz;
			q1.push(-a[i].t);
		}
		else
		    --res;
	}
	priority_queue<int>q2;
	sizz=0;
	for(int i=1;i<=m2;++i)
	{
		while(sizz>0)
		{
			if(-q2.top()<b[i].s)
			{
    			--sizz;
	    		q2.pop();
	    	}
	    	else
	    	    break;
		}
		if(sizz<s2)
		{
			++sizz;
			q2.push(-b[i].t);
		}
		else
		    --res;
	}
	return res;
}
void meiju()
{
	sort(a+1,a+1+m1,cmp1);
	sort(b+1,b+1+m2,cmp2);
	for(int i=0,j=n;i<=n;++i,--j)
	{
		if(check(i,j)>ans)
		    ans=check(i,j);
	}
}
void print()
{
	printf("%d\n",ans);
}
void solve()
{
	input();
	meiju();
	print();
	return;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int tests=1;
	for(int i=1;i<=tests;++i)
	    solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
