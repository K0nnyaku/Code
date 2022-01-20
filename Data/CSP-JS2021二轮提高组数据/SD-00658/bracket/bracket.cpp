#include<bits/stdc++.h>
using namespace std;
int n,k,ans,t;
char a[100010];
string s,ss;
bool check()
{
	if(ss[0]=='*'||ss[n-1]=='*')
	return 0;
	int l=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(ss[i]=='(')
		{
			l++;
			continue;
		}
		if(ss[i]==')')
		{
			if(l<=0)
			return 0;
			else l--;
			continue;
		}
		if(ss[i]=='*'&&ss[i+1]=='*')
		{
			cnt++;
			if(cnt>k)
			return 0;
		}
		else cnt=1;
	}
	if(l!=0)
	return 0;
	else return 1;
}
void dfs(int x)
{
	if(x==n)
	{
		if(check())
		{
			ans++;
		}
		return ;
	}
	if(s[x]!='?')
	{
		ss[x]=s[x];
		dfs(x+1);
	}
	else
	{
		ss[x]='(';
		dfs(x+1);
		ss[x]=')';
		dfs(x+1);
		ss[x]='*';
		dfs(x+1);
	} 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<ans;
	return 0;
}
