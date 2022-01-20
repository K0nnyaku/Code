#include<bits/stdc++.h>
using namespace std;

int n,k;
const int N=550;
char s[N];
const long long Y=1e9+7;
int idx;
int a[N];
long long ans=0;
bool check()
{
	stack<char> q;
	for(int i=2;i<=n+1;i++)
	{
		if(q.empty()&&s[i]!='(')
		return false;
		q.push(s[i]);
		if(s[i]==')')
		{
			q.pop();
			int p=0;
			while(q.top()!='('&&!q.empty())
			{
				q.pop();
				p++;
			}
			if(p>k)
			return false;
			if(!q.empty()) 
			q.pop();
			while(!q.empty())
			{
				if(q.top()=='*')
				q.pop();
			} 
			
		}
	}
	if(!q.empty())
	return false;
	return true;
}
void dfs(int t)
{
	if(t>idx)
	{
		if(check())
		{
			ans++;
			ans%=Y;
		}
		return;
	}
	s[a[t]]='(';
	dfs(t+1);
	s[a[t]]=')';
	dfs(t+1);
	s[a[t]]='*';
	dfs(t+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n+1;i++)
	{
		s[i]=getchar();
	}
	for(int i=1;i<=n+1;i++)
	{
		if(s[i]=='?')
		{
			idx++;
			a[idx]=i;
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
