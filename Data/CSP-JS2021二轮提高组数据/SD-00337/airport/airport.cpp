#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define int long long
const int MAXN=1e5+5;
struct node
{
	int x,y;
}a[MAXN],b[MAXN],lq[MAXN];
int n,m1,m2,maxn,last[MAXN];
int cmp(node x,node y)
{
	if(x.x==x.y)return x.y<y.y;
	return x.x<y.x;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m2;i++)cin>>b[i].x>>b[i].y;
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	int ansz,ansg;
	for(int nn=0;nn<=n;nn++)
	{
		priority_queue<int,vector<int>,greater<int> >q;
		int zg=nn,gj=n-nn,ans1=0,ans2=0,cnt1=0,cnt2=0;
		if(zg)for(int i=1;i<=m1;i++)
		{
			if(q.size())while(q.size()&&a[i].x>q.top())q.pop();
			if(q.empty())
			{
				q.push(a[i].y);
				ans1++;
				continue;
			}
			if(q.size()<zg)q.push(a[i].y),ans1++;
		}
		while(!q.empty())q.pop();
		if(gj)for(int i=1;i<=m2;i++)
		{
			if(q.size())while(q.size()&&b[i].x>q.top())q.pop();
			if(q.empty())
			{
				q.push(b[i].y);
				ans2++;
				continue;
			}
			if(q.size()<gj)q.push(b[i].y),ans2++;
		}
		while(!q.empty())q.pop();
		maxn=max(maxn,ans1+ans2);
	}
	cout<<maxn;
	return 0;
}
