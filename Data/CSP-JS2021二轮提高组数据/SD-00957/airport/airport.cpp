#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define lb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1e5+10;
const int MAXM=1e5+10;

int n,m1,m2;
pii seg1[MAXM],seg2[MAXM];

inline int calc(int x)
{
	int cnt1=x,cnt2=n-x;
	int res1=0,res2=0;
	
	priority_queue<int> pq;
	for(int i=1;i<=m1;i++)
	{
		while(!pq.empty() && seg1[i].fi>=-pq.top())
		{
			cnt1++;
			pq.pop();
		}
		
		if(cnt1)
		{
			res1++; cnt1--;
			pq.push(-seg1[i].se);
		}
	}
	
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=m2;i++)
	{
		while(!pq.empty() && seg2[i].fi>=-pq.top())
		{
			cnt2++;
			pq.pop();
		}
		
		if(cnt2)
		{
			res2++; cnt2--;
			pq.push(-seg2[i].se);
		}
	}
	
	return res1+res2;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&seg1[i].fi,&seg1[i].se);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&seg2[i].fi,&seg2[i].se);
		
	sort(seg1+1,seg1+m1+1);
	sort(seg2+1,seg2+m2+1);
	
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,calc(i));
	printf("%d\n",ans);
	
	return 0;
}





