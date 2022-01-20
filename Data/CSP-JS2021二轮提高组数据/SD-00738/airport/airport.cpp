#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int qread()
{
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,m1,m2,ans;
struct st
{
	int a,b;
}
t1[100010],t2[100010];
int t[200010],tot;
int cnt;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(st a,st b)
{
	return a.a<b.a;
}
int work1(int x)
{
	while(!q.empty())
		q.pop();
	int ans=0;
	int flag=1;
	int t=0;
	for(int i=1;i<=cnt;i++)
	{
		while(!q.empty()&&q.top()==i)
		{
			q.pop();
			t--;
		}
		while(flag<=m1&&t1[flag].a==i)
		{
			if(t<x)
			{
				q.push(t1[flag].b);
				t++;
				ans++;
			}
			flag++;
		}
	}
	return ans;
}
int work2(int x)
{
	while(!q.empty())
		q.pop();
	int ans=0;
	int flag=1;
	int t=0;
	for(int i=1;i<=cnt;i++)
	{
		while(!q.empty()&&q.top()==i)
		{
			q.pop();
			t--;
		}
		while(flag<=m2&&t2[flag].a==i)
		{
			if(t<x)
			{
				q.push(t2[flag].b);
				t++;
				ans++;
			}
			flag++;
		}
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		t1[i].a=qread();
		t1[i].b=qread();
		t[++tot]=t1[i].a;
		t[++tot]=t1[i].b;
	}
	for(int i=1;i<=m2;i++)
	{
		t2[i].a=qread();
		t2[i].b=qread();
		t[++tot]=t2[i].a;
		t[++tot]=t2[i].b;
	}
	sort(t+1,t+tot+1);
	cnt=unique(t+1,t+tot+1)-t-1;
	for(int i=1;i<=m1;i++)
	{
		t1[i].a=lower_bound(t+1,t+cnt+1,t1[i].a)-t;
		t1[i].b=lower_bound(t+1,t+cnt+1,t1[i].b)-t;
	}
	for(int i=1;i<=m2;i++)
	{
		t2[i].a=lower_bound(t+1,t+cnt+1,t2[i].a)-t;
		t2[i].b=lower_bound(t+1,t+cnt+1,t2[i].b)-t;
	}
	sort(t1+1,t1+m1+1,cmp);
	sort(t2+1,t2+m2+1,cmp);
	for(int i=0;i<=n;i++)
		ans=max(ans,work1(i)+work2(n-i));
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
