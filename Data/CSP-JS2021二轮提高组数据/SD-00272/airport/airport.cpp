//airport
#include<bits/stdc++.h> 
using namespace std;

int n,m1,m2,ans;
struct node
{
	int lt,rt,v,f;
}a[100010];

bool cmp(node x,node y)
{
	return x.lt<y.lt;
}


int check(int x)
{
	int tot=0,tot1=0,tot2=0;
	priority_queue<pair<int ,int > ,vector<pair<int ,int > >  ,greater<pair<int ,int > > > q;
	int vis[100010]={0};
	for(int i=1;i<=m1+m2;i++)
	{
//		if(q.size())cout<<q.top().first<<endl;
		int ti=a[i].lt;
		while(q.size()&&q.top().first<=ti) 
		{
//			cout<<i<<' '<<"*";
			if(vis[q.top().second]==0)
			{
				q.pop();continue;
			}
			if(a[q.top().second].v==1) tot1--;
			else tot2--;
			vis[q.top().second]=0;
			q.pop();
//			cout<<q.top().first<<endl;
		}
		if(a[i].v==1&&tot1<x)
		{
			tot++;
			tot1++;
			vis[i]=1;
			q.push(make_pair(a[i].rt,i));
		}
		else if(a[i].v==2&&tot2<(n-x)) 
		{
//			cout<<tot2<<' '<<(n-x)<<endl;
			tot++;
			tot2++;
			vis[i]=1;
			q.push(make_pair(a[i].rt,i));
		}
	}
	return tot;
}


int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)	
	{
		cin>>a[i].lt>>a[i].rt; 
		a[i].v=1;
	}
	for(int i=m1+1;i<=m1+m2;i++)
	{
		cin>>a[i].lt>>a[i].rt;
		a[i].v=2;
	}
	sort(a+1,a+m1+m2+1,cmp);
//	for(int i=1;i<=m1+m2;i++) cout<<' '<<a[i].v<<' '<<a[i].lt<<' '<<a[i].rt<<endl;cout<<endl;
	for(int i=0;i<=n;i++)
	{
		if(check(i)>ans)
		{
			ans=check(i);
//			cout<<i<<ans<<endl;
		}
	}
//	cout<<check(2)<<"!";
	cout<<ans;
	
	
	
} 
