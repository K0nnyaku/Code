/*
检查
修改数组大小 
freopen
静态差错
存档 
删文件 !!
*/
#include<bits/stdc++.h>
//#include<iostream>
//#include<utility>
//#include<cmath>
//#include<cstdio>
//#include<cmath>
//#include<queue>
//#include<map>
//#include<stack>
//#include<list>
//#include<string>
using namespace std;
typedef long long ll;
ll n;
ll w[50005],dic[100005];
ll p=1,pT=1;

string fun(ll begin,ll end,ll begin_,ll end_,string a)
{
	if(begin_==-1)
	{
		string c,d,maxx="Z";
		c=fun(begin+1,end,begin,begin,"L");
		d=fun(begin,end-1,end,end,"R");
		if(c!="Z")
		{
			maxx=c;
		}
		if(d!="Z")
		{
			if(maxx!="Z")
			{
				if(d>maxx)
				{
					maxx=d;
				}
			}
			maxx=d;
		}
		return maxx;
	}
	if(begin_-end_==n)
	{
		return a;
	}
	else
	{
		string c,maxx="Z";
		if(begin_>p)
		{
			if(dic[begin+1]==dic[begin_-1]&&begin<p-1)
			{
				c=fun(begin+1,end,begin-1,end_,a+"L");
				if(c<maxx)
				{
					maxx=c;
				}
			}
			if(dic[end-1]==dic[begin_-1]&&end>pT+1)
			{
				c=fun(begin,end-1,begin_-1,end_,a+"R");
				if(c<maxx)
				{
					maxx=c;
				}
			}
		}
		if(end_<pT)
		{
			if(dic[begin+1]==dic[end_+1]&&begin<p-1)
			{
				c=fun(begin+1,end,begin,end_+1,a+"L");
				if(c<maxx)
				{
					maxx=c;
				}
			}
			if(dic[end-1]==dic[end_+1]&&end>pT+1)
			{
				c=fun(begin,end-1,begin_,end_+1,a+"R");
				if(c<maxx)
				{
					maxx=c;
				}
			}
		}
		return maxx;
	}
}

int main()
{
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	//priority_queue <int,vector<int>,greater<int>> a;
	//priority_queue<int,vector<int>,less<int>> b;
	//pair<int,int> c;
	string c,maxx;
	ll T;
	cin>>T;
	for(ll t=0;t<T;t++)
	{
		cin>>n;
		maxx="Z";
		for(ll i=0;i<2*n;i++)
		{
			cin>>dic[i];
		}
		memset(w,0,sizeof(w));
		p=1;
		pT=1;
		for(ll i=0;i<2*n;i++)
		{
			if(w[i]>p)
			{
				p=w[i];
			}
			w[i]=pT;
			pT++;
			if(pT-p+1==n)
			{
				c=fun(0,2*n-1,-1,-1,"0");
				if(c<maxx)
				{
					maxx=c;
				}
			}
		}
		if(maxx=="Z")
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<maxx<<endl;
		}
	}
	return 0;
}
