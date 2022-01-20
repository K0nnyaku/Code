#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define N 100005
using namespace std;
int n,k,h;
char s[N];
int ta[N],tot;
int flag;
int p=1000000007;
void dfs(int num)
{
	if(num>h)
	{
		return ;
	}
	for(int i=ta[num]-1;i>=ta[num]-k-1;i--)
	{
		if(s[i]!='*')
		{
			flag=1;break;
		}
	}
	if(flag)
	{
		tot++;
		if(tot>p)
		tot-=p;
		s[ta[num]]='*';
		dfs(num+1);
	}
	int a=0,b=0;
	for(int i=1;i<=ta[num]-1;i++)
	{
		if(s[i]=='(')a++;
	}
	if(a%2==1)
	{
		tot++; 
		if(tot>p)
		tot-=p;
		s[ta[num]]=')';
	}
	for(int i=ta[num];i<=n;i++)
	{
		if(s[i]==')')b++;
	}
	if(b%2==1)
	{
		tot++;
		if(tot>p)
		tot-=p;
		s[ta[num]]='(';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
		{
			if(i==n)
			s[i]=')';
			else 
			{
				h++;
				ta[h]=i;
			}
		}
		
	}
	dfs(1);
	tot=tot%p;
	printf("%d",tot);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
