#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<int> >q;
struct air
{
	long long a,b;
}gn[100001],gj[100001];
bool tj(air x,air y)
{
	return x.a<y.a;
}
int n,m1,m2,ans;
void s(int num)
{
	int cnt=0,lq=num;
	for(int j=0;j<m1;j++)
	{
		if(lq)
		{
			q.push(gn[j].b);
			lq--;
			cnt++;
		}
		while(q.size()&&q.top()<=gn[j+1].a)
		{
			q.pop();
			lq++;
		}
	}
	lq=n-num;
	for(int j=0;j<m2;j++)
	{
		if(lq)
		{
			q.push(gj[j].b);
			lq--;
			cnt++;
		}
		while(q.size()&&q.top()<=gj[j+1].a)
		{
			q.pop();
			lq++;
		}
	}
	ans=max(ans,cnt);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i;
	cin>>n>>m1>>m2;
	for(i=0;i<m1;i++)
		cin>>gn[i].a>>gn[i].b;
	gn[m1].a=100000001;
	for(i=0;i<m2;i++)
		cin>>gj[i].a>>gj[i].b;
	gj[m2].a=100000001;
	sort(gn,gn+m1,tj);
	sort(gj,gj+m2,tj);
	for(int i=0;i<=n;i++)
		s(i);
	cout<<ans;
	return 0;
}
