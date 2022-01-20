/*
检查
修改数组大小 
freopen!!
静态差错
存档 
删文件 !!
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<cstdio>
#include<cmath>
#include<queue>
//#include<map>
#include<stack>
//#include<list>
#include<string>
//#include<cstdlib>
//#include<iomanip>
//#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	//priority_queue <int,vector<int>,greater<int>> a;
	//priority_queue<int,vector<int>,less<int>> b;
	//pair<int,int> c;
	ll n,m_a,m_b;
	cin>>n>>m_a>>m_b;
	vector<pll> dic_a,dic_b;
	priority_queue<pll,vector<pll>,greater<pll> > dic_a1,dic_b1;
	ll a,b;
	for(ll i=0;i<m_a;i++)
	{
		cin>>a>>b;
		dic_a1.push(make_pair(a,b));
	}
	for(ll i=0;i<m_b;i++)
	{
		cin>>a>>b;
		dic_b1.push(make_pair(a,b));
	}
	for(ll i=0;i<m_a;i++)
	{
		dic_a.push_back(dic_a1.top());
		dic_a1.pop();
	}
	for(ll i=0;i<m_b;i++)
	{
		dic_b.push_back(dic_b1.top());
		dic_b1.pop();
	}
	
	priority_queue<ll,vector<ll>,greater<ll> > a_1,b_1;
	ll sum_a,sum_b,time,maxx=0;
	for(ll i=0;i<=n;i++)
	{
		while(!a_1.empty())
		{
			a_1.pop();
		}
		while(!b_1.empty())
		{
			b_1.pop();
		}
		a=i;
		b=n-i;
		sum_a=0;
		sum_b=0;
		for(ll j=0;j<m_a;j++)
		{
			time=dic_a[j].first;
			while((!a_1.empty()))
			{	if(a_1.top()<time)
				{
					a_1.pop();
				}
				else
				{
					break;
				}
			}
			if(a_1.size()<a)
			{
				sum_a++;
				a_1.push(dic_a[j].second);
			}
		}
		for(ll j=0;j<m_b;j++)
		{
			time=dic_b[j].first;
			while((!b_1.empty()))
			{	if(b_1.top()<time)
				{
					b_1.pop();
				}
				else
				{
					break;
				}
			}
			if(b_1.size()<b)
			{
				sum_b++;
				b_1.push(dic_b[j].second);
			}
		}
		maxx=max(maxx,sum_a+sum_b);
		//cout<<i<<' '<<sum_a<<' '<<sum_b<<endl;
	}
	cout<<maxx;
	return 0;
}
