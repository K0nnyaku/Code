#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#define MAXN 101000
#define MAXM 
#define INF 0x3f3f3f3f
#define BASE 131
#define ll long long
#define ull unsigned long long
using namespace std;
struct Plane
{
	int l,r;
}gn[MAXN],gj[MAXN];
priority_queue<int>q1,q2;
int q,n,m,ans,maxx,ans2;
int cmp(struct Plane a,struct Plane b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int x,y;
	scanf("%d%d%d",&q,&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		gn[i].l=x,gn[i].r=y;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		gj[i].l=x,gj[i].r=y;
	}
	sort(gn+1,gn+1+n,cmp);
	sort(gj+1,gj+1+m,cmp);
	int ot,gns,gjs;
	for(int k=0;k<=q;k++)
	{
		gns=k,gjs=q-k;ans=0,ans2=0;
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		if(gns)
		{
			for(int i=1;i<=n;i++)
			{
				if(q1.empty()||q1.size()<gns)
				{
					q1.push(-gn[i].r);
					ans++;
				}
				else if(gns)
				{
					ot=-q1.top();
					if(ot>gn[i].l)continue;
					else
					{
						while(-q1.top()<gn[i].l&&!q1.empty())q1.pop();
						q1.push(-gn[i].r);
						ans++;
					}
				}
			}
		}
		if(gjs)
		{
			for(int i=1;i<=m;i++)
			{
				if(q2.empty()||q2.size()<gjs)
				{
					q2.push(-gj[i].r);
					ans2++;
				}
				else
				{
					ot=-q2.top();
					if(ot>gj[i].l)continue;
					else
					{
						while(-q2.top()<gj[i].l&&!q2.empty())q2.pop();
						q2.push(-gj[i].r);
						ans2++;
					}
				}
			}
		}
		maxx=max(maxx,ans+ans2);
	}
	printf("%d",maxx);
	return 0;
}
