#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct airpt
{
	int a,b;
	bool operator <(const airpt &x) const
	{
		return b>x.b;
	}
};
airpt apt1[MAXN];
airpt apt2[MAXN];
int n,m1,m2;
int ans;
priority_queue<airpt>levee;
int cmp(airpt x1,airpt x2)
{
	return x1.a<x2.a;
}
int works(int siz1,int siz2)
{
	int ans1=0,ans2=0;
	for(int i=1;i<=m1;i++)
	{
		airpt now=apt1[i];
		while(!levee.empty()&&levee.top().b<=now.a)
		{
			levee.pop();
			if(levee.empty()) break;
		}
		if(levee.size()<siz1)
		{
			levee.push(now);
			ans1++;
		}
	}
	while(!levee.empty())
	{
		levee.pop();
	}
	for(int i=1;i<=m2;i++)
	{
		airpt now=apt2[i];
		while(!levee.empty()&&levee.top().b<=now.a)
		{
			levee.pop();
			if(levee.empty()) break;
		}
		if(levee.size()<siz2)
		{
			levee.push(now);
			ans2++;
		}
	}
	while(!levee.empty())
	{
		levee.pop();
	}
	return ans1+ans2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&apt1[i].a,&apt1[i].b);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&apt2[i].a,&apt2[i].b);
	}
	sort(apt1+1,apt1+m1+1,cmp);
	sort(apt2+1,apt2+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		if(ans<works(i,n-i))
		ans=works(i,n-i);
	}
	cout<<ans;
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
