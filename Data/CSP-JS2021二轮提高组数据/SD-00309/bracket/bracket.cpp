#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int t,n,k,s[1000005],ans=0;
bool check1(int m)
{
	int c,d;
	for(int i=m;i<=n;i++)
	{
	    if(s[i]=='*')d++;
	    if((s[i]==')')||(s[i]=='('))break;
	}
	for(int i=m;i>=1;i--)
	{
	    if(s[i]=='*')c++;
	    if((s[i]==')')||(s[i]=='('))break;
	}
	if(c+d<k)return true;
	return false;
}
bool check2(int x)
{
	if(s[x]==')')
	{
		for(int i=1;i<x;i++)
		{
			if(s[i]=='(')return true;
		}
	}
	if(s[x]=='(')
	{
		for(int i=x;i<=n;i++)
		{
			if(s[i]==')')return true;
		}
	}
	if(s[x]=='*')check1(x);
	return false;
}
void dfs(int x)
{
	if(x == n)
	{
		ans++;
		dfs(1);
	} 
	for(int i=1;i<=n;i++)
	{
		if((s[i] == '?')&&check2(i))
			if(check1(i))
			{
				s[i]='*';
				dfs(x+1);
			}
			else{
				s[i]='(';
				dfs(x+1);
				s[i]=')';
				dfs(x+1);
			}
			s[i]='?';
	}
	
}
int main()
{
	freopen("bracket1.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	if(s[1]=='?')s[1]='(';
	if(s[n]=='?')s[n]=')';
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

