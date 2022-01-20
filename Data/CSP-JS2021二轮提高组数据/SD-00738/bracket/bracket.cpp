#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 1000000007
using namespace std;
int n,k,ans;
char s[510];
int st[510];
bool check()
{
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			top++;
			st[top]=i;
		}
		if(s[i]==')')
		{
			top--;
			if(top<0)
				return 0;
		}
	}
	if(top>0)
		return 0;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*')
		{
			tot++;
			if(tot>k)
				return 0;
		}
		else
			tot=0;
	}
	if(s[1]=='*'||s[n]=='*')
		return 0;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(check())
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	if(s[x]=='?')
	{
		s[x]='(';
		dfs(x+1);
		s[x]=')';
		dfs(x+1);
		s[x]='*';
		dfs(x+1);
		s[x]='?';
	}
	else
		dfs(x+1); 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
