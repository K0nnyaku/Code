#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#pragma GCC optimize(2)
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int n,m,m1,m2;
int ans=0;
int sum1[N],sum2[N];

struct Plane
{
	int l,r;
	bool operator < (const Plane& g) const
	{
		if(l!=g.l) return l<g.l;
		return r<g.r;
	}
}plane[N];

void get1()
{
	priority_queue<PII,vector<PII>,greater<PII> > q;
	priority_queue<int,vector<int>,greater<int> > ne;
	for(int i=1;i<=n;i++) ne.push(i);
	for(int i=1;i<=m1;i++)
	{
		while(q.size()&&q.top().first<=plane[i].l)
		{
			PII t=q.top();
			q.pop();
			ne.push(t.second);
		}
		if(ne.size())
		{
			int t=ne.top();
			ne.pop();
			q.push({plane[i].r,t});
			sum1[t]++;
		}
	}
}

void get2()
{
	priority_queue<PII,vector<PII>,greater<PII> > q;
	priority_queue<int,vector<int>,greater<int> > ne;
	for(int i=1;i<=n;i++) ne.push(i);
	for(int i=m1+1;i<=m;i++)
	{
		while(q.size()&&q.top().first<=plane[i].l)
		{
			PII t=q.top();
			q.pop();
			ne.push(t.second);
		}
		if(ne.size())
		{
			int t=ne.top();
			ne.pop();
			q.push({plane[i].r,t});
			sum2[t]++;
		}
	}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	m=m1+m2;
	for(int i=1;i<=m;i++) scanf("%d%d",&plane[i].l,&plane[i].r);
	
	sort(plane+1,plane+1+m1);
	sort(plane+1+m1,plane+1+m);
	
	get1();
	get2();
	for(int i=1;i<=n;i++) sum1[i]+=sum1[i-1];
	for(int i=1;i<=n;i++) sum2[i]+=sum2[i-1];
	
	for(int i=0;i<=n;i++)
		ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
