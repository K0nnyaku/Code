#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
char a[510];
int k,n,next[510],lb=1,maxx,sum1,sum2,ans;
bool check(int le,int ri)
{
	if((le+ri)%2!=0)
	{
		return 0;
	}
	stack<char> s;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='('||a[i]=='*')
		{
			s.push(a[i]);
		}
		if(a[i]==')')
		{
			int sum=0;
			bool ch=0;
			while(!s.empty())
			{
				if(s.top()=='(')
				{
					s.pop();
					ch=1;
					break;
				}
				else if(s.top()=='*'&&sum<k)
				{
					s.pop();
					sum++;
				}
				else if(s.top()=='*'&&sum>=k)
				{
					break;
				}
			}
			if(!ch)
			{
				return 0;
			}
		}
	}
	if(s.empty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int dfs(int now,int le,int ri)
{
	int sum=0;
	if(next[now]==0)
	{
		if(check(le,ri))
		{
			return 1;
		}
		else
		{
			return 0;			
		}
	}
	a[next[now]]='(';
	sum+=dfs(now+1,le+1,ri);
	a[next[now]]='?';
	a[next[now]]=')';
	sum+=dfs(now+1,le,ri+1);
	a[next[now]]='?';
	a[next[now]]='*';
	sum+=dfs(now+1,le,ri);
	a[next[now]]='?';
	return sum%1000000007;	
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	char iji;
	scanf("%c",&iji);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='?')
		{						
			next[lb++]=i;
		}
		if(a[i]=='(')
			sum1++;
		if(a[i]==')')
			sum2++;
	}
	maxx=(sum1+sum2+lb)/2;
	ans=dfs(1,sum1,sum2);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

