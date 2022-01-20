#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,lim;
char a[505];
char finnn[505];
int ans;
void dfs(int stp)
{
	if(stp==n+1)
	{
		ans++;
		ans%=MOD;
	}
	if(a[stp]=='('||a[stp]=='?')
	{
		finnn[stp]='(';
		dfs(stp+1);
		finnn[stp]=0;
	}
	if(a[stp]==')'||a[stp]=='?')
	{
		finnn[stp]=')';
		dfs(stp+1);
		finnn[stp]=0;	
	}
	if(a[stp]=='*'||a[stp]=='?')
	{
		int flag=0;
		for(int i=stp;i>=1;i++)
		{
			if(finnn[i]!='*'&&stp-i+1<=lim)
			{
				flag=1;
				break;
			}
			if(stp-i+1>lim)
			{
				break;
			}
		}
		if(!flag)
		{
			finnn[stp]='*';
			dfs(stp+1);
			finnn[stp]=0;		
		}

	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&lim);
	scanf("%s",a+1);
	dfs(1);
	printf("0\n");
	return 0;
}
//goodbye,OI
//R.I.P
