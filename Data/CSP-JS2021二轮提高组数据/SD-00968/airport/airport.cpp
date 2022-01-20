#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ll long long
using namespace std;
struct node{
	int s,e;
} pl1[100005],pl2[100005];
bool cmp(node a,node b){
	return a.s<b.s;
}
int mem[100005]={0};
int n,m1,m2;
int check(int x1)
{
	if(mem[x1])
	{
		return mem[x1];
	}
	int x2=n-x1,na=0;
	priority_queue<int,vector<int>,greater<int> > q1,q2;
	for(int i=1;i<=m1;i++)
	{
		if(x1==0)break;
		if(q1.size()<x1)
		{
			q1.push(pl1[i].e);
			na++;
			continue;
		}
		int fr=q1.top();
		if(fr<=pl1[i].s)
		{
			q1.pop();
			q1.push(pl1[i].e);
			na++;
		}
	}
	for(int i=1;i<=m2;i++)
	{
		if(x2==0)break;
		if(q2.size()<x2)
		{
			q2.push(pl2[i].e);
			na++;
			continue;
		}
		int fr=q2.top();
		if(fr<=pl2[i].s)
		{
			q2.pop();
			q2.push(pl2[i].e);
			na++;
		}
	}
	mem[x1]=na;
	return na;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		scanf("%d%d",&pl1[i].s,&pl1[i].e);
	}
	for(int i=1;i<=m2;++i)
	{
		scanf("%d%d",&pl2[i].s,&pl2[i].e);
	}
	sort(pl1+1,pl1+m1+1,cmp);
	sort(pl2+1,pl2+m2+1,cmp);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,check(i));
	}
	cout<<ans<<endl;
	return 0;
}
//CNMCCF
