#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
const int mod=1e9+7;
string o;
int n,k;
int ans=0;
bool check(string s)
{
	stack <char> ss;
	int pos=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='*')
		{
			if(!pos)
			pos=i;
			else
			{
				if(i-pos>k)
				{
					return 0;
				}
			}
		}
		else
		{
			if(s[i]==')' && ss.top()=='(')
			{
				ss.pop();
			}
			else
			ss.push(s[i]);
			pos=0;
		}
	}
	if(ss.size())
	{
		return 0;
	}
	return 1;
}
void dfs(string s,int now)
{
//	cout<<s<<endl wo shi sha bi ;
	int len=s.size();
	if(now==len)
	{
		ans+=check(s);
		return;
	}
	for(int i=now;i<len;i++)
	{
		if(s[i]=='?')
		{
			string t,x;
			if(i>0)
			{
				t=s.substr(0,i);
			}
			if(i<len-1)
			{
				x=s.substr(i+1);
			}
			if(i>0 && i<len-1)
			{
				dfs(t+'('+x,i+1);
				dfs(t+')'+x,i+1);
				dfs(t+'*'+x,i+1);
			}
			else
			{
				if(i<len-1)
				{
					dfs('('+x,i+1);
					dfs('*'+x,i+1);
					dfs(')'+x,i+1);	
				}
				if(i>0)
				{
					dfs(t+'(',i+1);
					dfs(t+')',i+1);
					dfs(t+'*',i+1);
				}
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>o;
	dfs(o,0);
	cout<<ans;
	return 0;
}

