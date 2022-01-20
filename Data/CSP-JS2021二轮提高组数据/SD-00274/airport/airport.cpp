#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node{
	long long x,y;
}air1[100010],air2[100010];
int br1[100010],br2[100010];
int cnt1,cnt2;
long long ans,ansn;
bool cmp (node x,node y)
{
	return x.x<y.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&air1[i].x,&air1[i].y);
	for(int i=1;i<=m2;i++) scanf("%d%d",&air2[i].x,&air2[i].y);
	sort(air1+1,air1+m1+1,cmp);
	sort(air2+1,air2+m2+1,cmp);
	for(int t1=0;t1<=n;t1++)
	{
		memset(br1,0,sizeof(br1));
		memset(br2,0,sizeof(br2));
		int t2=n-t1;
		cnt1=1;
		cnt2=1;
		ans=0;
		for(int i=1;i<=m1;i++)
		{
			for(int j=1;j<=t1;j++)
			{
				if(br1[j]<=air1[i].x)
				{
					ans++;
					br1[j]=air1[i].y;
					break;
				}
			}
		}
		for(int i=1;i<=m2;i++)
		{
			for(int j=1;j<=t2;j++)
			{
				if(br2[j]<=air2[i].x)
				{
					ans++;
					br2[j]=air2[i].y;
					break;
				}
			}
		}
		ansn=max(ans,ansn);
	}
	cout<<ansn;
	return 0;
}
