//I hate dynamic programming
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
const int mod=1000000007;
int n,k,ans,a[510],qwq[510];
string s;
stack<int> st;
bool check()
{
	while(!st.empty())st.pop();
	int sum=0;
	for(int i=1;i<=n;i++)sum+=qwq[i];
	if(sum!=0)return 0;
	for(int i=1;i<=n;i++)
		if(qwq[i]==0)
		{
			int now=i;
			while(qwq[now]==0)now++;
			if(now-i>k)return 0;
			i=now-1;
		}
	for(int i=1;i<=n;i++)
		if(!st.empty()&&qwq[i]+st.top()==0&&qwq[i]==-1)
		{
			st.pop();
		}
		else if(qwq[i]!=0)st.push(qwq[i]);
	if(!st.empty())return 0;
	return 1;
}
void dfs(int xx)
{
	if(xx>n)
	{
		if(check())
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	if(a[xx]==2)
	{
		qwq[xx]=1;
		dfs(xx+1);
		qwq[xx]=2;
		qwq[xx]=-1;
		dfs(xx+1);
		qwq[xx]=2;
		qwq[xx]=0;
		dfs(xx+1);
		qwq[xx]=2;
	}
	else dfs(xx+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k >> s;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='(')a[i]=qwq[i]=1;
		if(s[i-1]==')')a[i]=qwq[i]=-1;
		if(s[i-1]=='?')a[i]=qwq[i]=2;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
