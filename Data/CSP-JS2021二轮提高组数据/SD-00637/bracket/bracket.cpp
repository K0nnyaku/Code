#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int n,k,ans,d;
string a,f;
int pan()
{
	int rtn=1,l=0,cnt,g;
	for(int i=0;i<n;i++)
	{
		if(f[i]=='(')
		{
			l++;
			if(i-1>=0)
				if(f[i-1]=='*')
					g=1;			
		}
		if(f[i]==')')
		{
			if(l>0)
			{
				if(g==1&&f[i+1]=='*')
					rtn=0;
				else
				{
					g=0;
					l--;
				}			
			}
			else
				{
					rtn=0;
					break;
				}
		}
		if(f[i]=='*')
		{
			cnt=1;
			while(f[i+1]=='*')
			{
				cnt++;
				i++;
			}
			if(cnt>k)
				rtn=0;
		}
	}
	if(l>0)
		rtn=0;
	if(f[0]=='*'||f[n-1]=='*')
		rtn=0;
	return rtn;
}
void dfs(int now)
{
	if(now==d)
	{
		for(int i=d+1;i<n;i++)
			f[i]=a[i];
		int mm=pan();
		ans+=pan();
	}
	int i;
	for(i=now+1;i<n;i++)
	{
		if(a[i]=='?')
			break;
		f[i]=a[i];
	}
	if(i!=n)
	{
		f[i]='*';
		dfs(i);
		f[i]='(';
		dfs(i);
		f[i]=')';
		dfs(i);
	}
	return ;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>a;
	for(int i=0;i<n;i++)
		if(a[i]=='?')
			d=i;
	dfs(-1);
	printf("%d\n",ans);
	return 0;
}
