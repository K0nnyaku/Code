#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,ans=0,flag[10005],vis[105];
char ch[10005];
bool pan(int x)
{
	int res=0;
	while(x)
	{
		if(res>m)
		return 0;
		if(ch[x]!='*')
		break;
		res++;
		x--;
	}
	return res<=m;
}
bool dfs()
{
	int flag=0,pos=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='(')
		{
			pos++;
		}
		if(ch[i]==')')
		{
			pos--;
			if(pos==0)
			{
				memset(vis,0,sizeof(vis));
				flag=0;
			}
		}
		if(ch[i]=='*'&&ch[i+1]!='*')
		{
			if(vis[pos]&&flag)
			{
				int now=i;
				while(ch[now]=='*')
				now++;
				if(ch[now]==')')
				return 0;
				else
				continue;
			}
			flag=1;
			vis[pos]=1;
		}
	}
	return 1;
}
void dfs(int x,int l,int r)
{
    if(l<r)
	return; 
	if(x==n+1)
	{
		if(ch[x-1]=='*')
		return;
		if(l==r)
		{
	    	if(dfs())
	    	{
	    		ans=(ans+1)%mod;
			}	
		}
		return;
	}
	if(ch[x]!='?'&&flag[x]==0)
	{
		if(ch[x]=='(')
		dfs(x+1,l+1,r);
		else if(ch[x]==')')
		dfs(x+1,l,r+1);
		else
		dfs(x+1,l,r);
		return;
	}
	ch[x]='(';
	dfs(x+1,l+1,r);
	ch[x]=')';
	dfs(x+1,l,r+1);
	if(x!=1)
	{
		ch[x]='*';
    	if(pan(x))
    	{
    		dfs(x+1,l,r);
    	}
	}
	return;
}
//   (**(*)*())
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch+1);
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='?')
		flag[i]=1;
	}
	dfs(1,0,0);
	printf("%d\n",ans%mod);
	return 0;
}
