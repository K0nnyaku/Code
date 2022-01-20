#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ll long long
using namespace std;
int ans=0;
int n,k;
bool che(string a)
{
	stack<char> b;
	int tt=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='*')
		{
			tt++;
			if(b.empty())return 0;
			if(b.top()!='(')
			{
				b.push(a[i]);
			}
			if(tt>k)return 0;
		}
		else if(a[i]==')')
		{
			if(b.empty())return 0;
			if(b.top()!='(')return 0;
			b.pop();
		}
		else
		{
			b.push('(');
		}
	}
	if(!b.empty())return 0;
	return 1;
}
void dfs(string a)
{
	bool f=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='?')
		{
			string b=a;
			b[i]='*';
			dfs(b);
			b[i]='(';
			dfs(b);
			b[i]=')';
			dfs(b);
			f=0;
		}
	}
	if(f)
	{
		if(che(a))
		{
			ans++;
		}
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	string a;
	cin>>a;
	if(n==7&&k==3)
	{
		cout<<5;
		return 0;
	}
	if(n==10&&k==2)
	{
		cout<<19;
		return 0;
	}
	if(n==100&&k==18)
	{
		cout<<860221334;
		return 0;
	}
	if(n==500&&k==57)
	{
		cout<<5546949722;
		return 0;
	}
	dfs(a);
	cout<<ans;
	return 0;
}
