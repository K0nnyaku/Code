#include<bits/stdc++.h>

#define int long long

using namespace std;

int ans,n,k,l,len;
string s;
int sum[510];

void dfs(int x)
{
	if(x==n)
	{
		if(l<=0)return;
		s[x]=')';
		dfs(x+1);
		return;
	}
	if(x==n+1)
	{
		stack<int>st;
		for(int i=1;i<=n;i++)
		{
			sum[i]=0;
			if(s[i]=='(')
			{
				st.push(i);
			}
			if(s[i]=='*')
			{
				sum[i]=sum[i-1]+1;
			}
			if(s[i]==')')
			{
				if(st.empty())return;
				int p=st.top();
				st.pop();
				if(s[i-1]=='*'&&sum[i-1]!=i-p-1)return;
			}
		}
		if(!st.empty())return;
		//cout<<s<<'\n';
		ans++;
		return;
	}
	if(s[x]!='?')
	{
		if(s[x]=='*')
		{
			len++;
			if(len>k)return;
			dfs(x+1);
		}
		len=0;
		if(s[x]==')')
		{
			if(l<=0)return;
			l--;
			dfs(x+1);
		}
		if(s[x]=='(')
		{
			l++;
			dfs(x+1);
		}
	}
	else
	{
		if(len<k)
		{
			s[x]='*';
			len++;
			dfs(x+1);
			s[x]='?';
		}
		len=0;
		if(l>0)
		{
			l--;
			s[x]=')';
			dfs(x+1);
			l++;
			s[x]='?';
		}
		s[x]='(';
		l++;
		dfs(x+1);
		s[x]='?';
	}
}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	cin>>s;
	s=" "+s;
	if(s[1]==')'||s[n]=='('||s[1]=='*'||s[n]=='*')
	{
		puts("0");
		return 0;
	}
	s[1]='(';
	l=1;
	dfs(2);
	printf("%lld\n",ans);
	return 0;
}

