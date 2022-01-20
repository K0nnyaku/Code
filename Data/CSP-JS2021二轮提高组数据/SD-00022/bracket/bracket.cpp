#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
bool check(string x,int k)
{
	int en=x.size()-1;
	if(x[0]=='*'||x[en]=='*')
		return false;
	int cnt=0;
	for(int i=1;i<=en;i++)
	{
		if(x[i]=='*')
			cnt++;
		else if(x[i]!='*'&&x[i-1]=='*')
		{
			if(cnt>k)
				return false;
			cnt=0;
		}
	}
	stack<char>stk;
	int cnt1=0,cnt2=0;
	char la=0;
	stk.push(x[0]);
	for(int i=1;i<=en;i++)
	{
		bool mark=false;
		if(x[i]=='*'&&x[i-1]=='(')
		{
			la=x[i-1];
		}
		else if(x[i]==')'&&x[i-1]=='*')
		{
			if(!stk.empty())
			{
				stk.pop(); mark=true;
			}
			if(la==0&&!stk.empty())
				return false;
		}
		if(x[i]=='(')
		{
			stk.push(x[i]);
			la=0;
		}
		else if(x[i]==')')
		{
			la=0;
			if(!stk.empty()&&!mark)
				stk.pop(),cnt2++;
			else if(!mark)
				return false;
		}
	}
	return true;
}
int dfs(int po,int k,string a,string &x)
{
	if(po>=x.size())
	{
		if(check(a,k))
		{
			return 1;
		}
	}
	int sum=0;
	if(x[po]=='?')
	{
		sum=(sum+dfs(po+1,k,a+'(',x))%mo;
		sum=(sum+dfs(po+1,k,a+'*',x))%mo;
		sum=(sum+dfs(po+1,k,a+')',x))%mo;
	}
	else
	{
		sum=(sum+dfs(po+1,k,a+x[po],x))%mo;
	}
	return sum;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;cin>>n>>k;
	string s;cin>>s;
	//cout<<check(s,k)<<" ";
	string a;
	cout<<dfs(0,k,a,s);
	return 0;
}
