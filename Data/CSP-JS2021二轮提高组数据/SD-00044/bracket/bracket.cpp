#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma GCC optimize(2)
using namespace std;
const int N=510;
const int mod=1e9+7;
int n,m,ans=0;
char ch[N];

bool check()
{
	if(ch[1]=='*'||ch[n]=='*'||(ch[1]=='*'&&ch[n]=='*')) return false;
	int stk[N],top=0;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='(') stk[++top]=i;
		else if(ch[i]==')')
		{
			int t=stk[top--],cnt=0,j,k;
			if(top<0) return false;
			for(j=t+1;j<i;j++)
				if(ch[j]=='*') cnt++;
				else break;
			for(k=i-1;k>j;k--)
				if(ch[k]=='*') cnt++;
				else break;
			
			if(ch[t+1]=='*'&&ch[i-1]=='*'&&j!=i) return false;
			if(cnt>m) return false;
		}
		
	}
	if(top!=0) return false;
	return true;
}

void dfs(int u)
{
	if(u==n+1)
	{
		if(check()) ans=(ans+1)%mod;
		return ;
	}
	
	if(ch[u]=='?')
	{
		ch[u]='(';
		dfs(u+1);
		ch[u]=')';
		dfs(u+1);
		ch[u]='*';
		dfs(u+1);
		ch[u]='?';
	}
	else dfs(u+1);
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch+1);
	dfs(0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
