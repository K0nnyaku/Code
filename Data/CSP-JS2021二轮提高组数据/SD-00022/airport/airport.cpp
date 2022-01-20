#include<bits/stdc++.h>
#define ma 100010
using namespace std;
struct node
{
	int a,b;
	bool operator <(const node x)const
	{
		return a<x.a;
	}
}pl1[ma];
node pl2[ma];
int c1=0,c2=0;
int b1[ma],b2[ma];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&pl1[i].a,&pl1[i].b);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&pl2[i].a,&pl2[i].b);
	}
	sort(pl1+1,pl1+m1+1);
	sort(pl2+1,pl2+m2+1);
	if(n<=100)
	{
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			int cnt1=i,cnt2=n-i,cnt3=0;
			memset(b1,0,sizeof(b1));
			memset(b2,0,sizeof(b2));
			for(int j=1;j<=m1;j++)
			{
				for(int k=1;k<=cnt1;k++)
				{
					if(b1[k]<pl1[j].a)
					{
						b1[k]=pl1[j].b;
						cnt3++;
						break;
					}
				}
			}
			for(int j=1;j<=m2;j++)
			{
				for(int k=1;k<=cnt2;k++)
				{
					if(b2[k]<pl2[j].a)
					{
						b2[k]=pl2[j].b;
						cnt3++;
						break;
					}
				}
			}
			ans=max(ans,cnt3);
		}
		cout<<ans;
	}
	else if(n<=5000)
	{
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			int cnt1=i,cnt2=n-i,cnt3=0;
			priority_queue<int,vector<int>,greater<int> >q1,q2;
			for(int j=1;j<=cnt1;j++)
				q1.push(0);
			for(int j=1;j<=cnt2;j++)
				q2.push(0);
			for(int j=1;j<=m1;j++)
			{
				if(!q1.empty()&&q1.top()<pl1[j].a)
				{
					q1.pop();
					q1.push(pl1[j].b);
					cnt3++;
				}
			}
			for(int j=1;j<=m2;j++)
			{
				if(!q2.empty()&&q2.top()<pl2[j].a)
				{
					q2.pop();
					q2.push(pl2[j].b);
					cnt3++;
				}
			}
			ans=max(ans,cnt3);
		}
		cout<<ans;
	}
	else
	{
		int ans=0,llim=max((n>>1)-30,0),ulim=min((n>>1)+30,n);
		for(int i=llim;i<=ulim;i++)
		{
			int cnt1=i,cnt2=n-i,cnt3=0;
			priority_queue<int,vector<int>,greater<int> >q1,q2;
			for(int j=1;j<=cnt1;j++)
				q1.push(0);
			for(int j=1;j<=cnt2;j++)
				q2.push(0);
			for(int j=1;j<=m1;j++)
			{
				if(!q1.empty()&&q1.top()<pl1[j].a)
				{
					q1.pop();
					q1.push(pl1[j].b);
					cnt3++;
				}
			}
			for(int j=1;j<=m2;j++)
			{
				if(!q2.empty()&&q2.top()<pl2[j].a)
				{
					q2.pop();
					q2.push(pl2[j].b);
					cnt3++;
				}
			}
			ans=max(ans,cnt3);
		}
		cout<<ans;
	}
	return 0;
}
