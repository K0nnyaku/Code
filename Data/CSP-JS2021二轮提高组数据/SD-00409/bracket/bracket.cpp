#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

const int p=1e9+7;
int n,k;

char s[505];

int ans=0;

bool check()
{
	int top=0;
	int num=0;
	int sta[550];
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='*')
		{
			num++;
			if(num>k)
			{
				return false;
			}
		}
		else
		{
			num=0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')
		{
			sta[top++]=i;
		}
		if(s[i]==')')
		{
			top--;
			if(top<0)
			{
				return false;
			}
			for(int j=sta[top]+1;j<i;++j)
			{
				if(s[j]!='*'&&s[sta[top]+1]=='*'&&s[i-1]=='*')
				{
					return false;
				}
			}
		}
	}
	if(top!=0)
	{
		return false;
	}
	return true;
}

void dfs(int nw)
{
	if(nw>n)
	{	
		if(check())
		{
//			printf("%s\n",s+1);
			ans++;
		}
		return;
	}
	if(s[nw]!='?')
	{
		dfs(nw+1);
	}
	else
	{
		if(nw!=n&&nw!=1)
		{
			s[nw]='(';
			dfs(nw+1);
			s[nw]='?';
			s[nw]=')';
			dfs(nw+1);
			s[nw]='?';
			s[nw]='*';
			dfs(nw+1);
			s[nw]='?';
		}
		if(nw==1)
		{
			s[nw]='(';
			dfs(nw+1);
		}
		if(nw==n)
		{
			s[nw]=')';
			dfs(nw+1);
		}
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//
//	s[1]='(';
//	s[2]='*';
//	s[3]='(';
//	s[4]=')';
//	s[5]='*';
//	s[6]=')';
//	n=6;
//	cout<<check();
	
	scanf("%d%d",&n,&k);
	if(n==0)
	{
		printf("0\n");
		return 0;
	}
	scanf(" %s",s+1);

	if(s[1]==')'||s[1]=='*'||s[n]=='('||s[n]=='*')
	{
		printf("0\n");
		return 0;
	}

	dfs(1);

	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
