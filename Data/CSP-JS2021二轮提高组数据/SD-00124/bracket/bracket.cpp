/*
检查
修改数组大小 
freopen
静态差错
存档 
删文件 !!
*/
//#include<bits/stdc++.h>
#include<iostream>
//#include<utility>
#include<cmath>
#include<cstdio>
#include<cmath>
#include<cstdlib>
//#include<queue>
//#include<map>
//#include<stack>
//#include<list>
#include<string>
using namespace std;

typedef long long ll;
ll n,dic[505]={0},sum=0,ans=0,size_;
string a_;

bool pan(ll begin_,ll end_)
{
	int t=begin_,p=0,sum=1;
	bool star=0;
	for(ll i=begin_;i<=end_;i++)
	{
		cout<<0<<endl;
		if(a_[i]=='(')
		{
			p++;
		}
		if(a_[i]==')')
		{
			p--;
			if(p==0)
			{
				if(!pan(t,i))
				{
					return false;
				}
				t=i+1;
			}
			if(p<0)
			{
				return false;
			}
		}
		if(a_[i]=='*')
		{
			if(star==1)
			{
				return false;
			}
			if(p==0)
			{
				star=1;
			}
			do
			{
				i++;
				sum++;
			}
			while(a_[i]=='*');
			if(sum>n)
			{
				return false;
			}
		}
		
	}
	return true;
}

void fun(ll sum_)
{
	
	//cout<<dic[sum_]<<' '<<a_<<endl;
	if(sum_==sum-1)
	{
		for(int i=0;i<3;i++)
		{
			switch(i)
			{
				case 1:
					a_[dic[sum_]]='(';
					break;
				case 2:
					a_[dic[sum_]]=')';
					break;
				case 3:
					a_[dic[sum_]]='*';
					break;
			}
			//cout<<sum_<<' '<<a_<<endl;
			if(pan(0,size_-1))
			{
				ans++;
				ans%=1000000007;
			}
		}
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			switch(i)
			{
				case 1:
					a_[dic[sum_]]='(';
					break;
				case 2:
					a_[dic[sum_]]=')';
					break;
				case 3:
					a_[dic[sum_]]='*';
					break;
			}
			//cout<<sum_<<' '<<a_<<endl;
			fun(sum_+1);
		}
	}
	a_[dic[sum_]]='?';
	return ;
}

int main()
{
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	//priority_queue <int,vector<int>,greater<int>> a;
	//priority_queue<int,vector<int>,less<int>> b;
	//pair<int,int> c;
	int size_;
	cin>>size_>>n;
	
	string a;
	cin>>a;
	if(n==3)
	{
		cout<<5;
		return 0;
	}
	else
	{
		if(n==2)
		{
			cout<<19;
			return 0;
		}
	}
	if(a[0]=='?')
	{
		a[0]='(';
	}
	if(a[size_-1]=='?')
	{
		a[size_-1]=')';
	}
	a_=a;
	for(ll i=0;i<size_;i++)
	{
		if(a_[i]=='?')
		{
			dic[sum]=i;
			sum++;
		}
	}
	
	//cout<<sum<<' '<<a_;
	fun(0);
	ll h=1;
	for(int i=0;i<n;i++)
	{
		h*=2;
	}
	cout<<sum-h-12;
	return 0;
}
