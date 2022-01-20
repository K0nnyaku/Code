#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
const int N=1e5+5;
int n,m1,m2;
pair<int,int> t1[N],t2[N];
int solve(int k)
{
	int ans=0;
	priority_queue<int,vector<int>,greater<int> > m;
	for(int i=1;i<=m1;i++)
	{
		while(!m.empty()&&m.top()<t1[i].first)
		{
			m.pop();
		}
		if(m.size()<k)
		{
			m.push(t1[i].second);ans++;
		}
	}
	return ans;
}
int solve2(int k)
{
	int ans=0;
	priority_queue<int,vector<int>,greater<int> > m;
	for(int i=1;i<=m2;i++)
	{
		while(!m.empty()&&m.top()<t2[i].first)
		{
			m.pop();
		}
		if(m.size()<k)
		{
			m.push(t2[i].second);ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int te,le;
	for(int i=1;i<=m1;i++) 
	{
		cin>>te>>le;
		t1[i]=make_pair(te,le);
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>te>>le;
		t2[i]=make_pair(te,le);
	}
	sort(t1+1,t1+m1+1);
	sort(t2+1,t2+m2+1);
	int re=0;
	for(int i=0;i<=n;i++)
	{
		re=max(re,solve(i)+solve2(n-i));
	}
	cout<<re;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
