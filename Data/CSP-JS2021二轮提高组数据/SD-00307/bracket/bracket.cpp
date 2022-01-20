#include<iostream>
#include<cstdio>
using namespace std;
const int N=510,mod=1e9+7;
int n,k,ans;
char s[N];
bool check(int l,int r)
{
	if(s[l]!='('||s[r]!=')') return false;
	int cnt=0,top=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='*')
		{
			cnt++;
			if(cnt>k) return false;
		}
		else if(s[i]=='(')
		{
			top++;
			cnt=0;
		}
		else
		{
			if(top==0) return false;
			top--;
			cnt=0;
		}
	}
	if(top) return false;
	if(r-l+1<2) return false;
	if(r-l+1==2) return true;
	cnt=0;
	for(int i=l+1;i<=r-1;i++)
	{
		if(s[i]=='*') cnt++;
		else break;
	}
	if(cnt>k) return false;
	if(cnt==r-l-1) return true;
	bool flag=check(l+cnt+1,r-1);
	cnt=0;
	for(int i=r-1;i>=l+1;i--)
	{
		if(s[i]=='*') cnt++;
		else break;
	}
	flag|=check(l+1,r-cnt-1);
	for(int k=l+1;k<=r-1;k++)
	{
		if(s[k]==')')
		{
			for(int i=k+1;i<=r-1;i++)
			{
				if(s[i]=='*') cnt++;
				if(s[i]=='(')
				{
					if(cnt>k) break;
					flag|=check(l,k)&&check(i,r);
				}
			}
		}
	}
	return flag;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(check(1,n))
		{
			ans=(ans+1)%mod; 
		}
		return;
	}
	if(s[x]!='?') dfs(x+1);
	else
	{
		s[x]='(';
		dfs(x+1);
		s[x]='?';
		s[x]=')';
		dfs(x+1);
		s[x]='?';
		s[x]='*';
		dfs(x+1);
		s[x]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if((s[1]!='('&&s[1]!='?')||(s[n]!=')'&&s[n]!='?'))
	{
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
