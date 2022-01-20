#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int n,k;
int sum,a[100005];
char s[100005];
long long f;
int hf(char x[])
{
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		if(ans1<0||ans2>k)
			return 0;
		if(s[i]=='(')
		{
			ans1++;
			ans2=0;
		}		
		if(s[i]==')')
		{
			ans1--;
			ans2=0;
		}
		if(s[i]=='*')
			ans2++;
	}
	return 1;
}
void dfs(int x,int y)
{
	if(x==sum)
	{
		if(hf(s)==1)
		{
			f+=1;
			f%=1000000007;
		}
		return;
	}
	if(y==0)
	{
		s[a[x]]='*';
	}
	if(y==1)
	{
		s[a[x]]='(';
	}
	if(y==2)
	{
		s[a[x]]=')';
	}
	dfs(x+1,0);
	dfs(x+1,1);
	dfs(x+1,2);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]=='?')
			a[sum++]=i;
	}
	dfs(0,0);
	dfs(0,1);
	dfs(0,2);
	cout<<f;
	return 0;
}
//1000000007
