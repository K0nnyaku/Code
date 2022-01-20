#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,k;
int ans;
int num;
int num1;
int temp;
int temp2;
string s;
int a[200];
bool check()
{
	num=0;
	num1=0;
	int flag=0;
	int nn=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==2)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]==a[i])
				{
					nn++;
					if(nn>k)	return 0;
				}
				if(a[j]!=a[i])	nn=0;
			}
		}
		if(a[i]==2)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]!=a[j])
				{
					if(a[j]==3&&a[i-1]==3&&a[i-2]==1)
						return 0;
					if(a[i-1]!=1&&a[i-1]!=2&&a[i-1]!=3)
						return 0;
					if(a[i-1]==1&&a[j]==1&&a[j+1]==3)
						return 0;
					break;
				}
			}
		}
		if(a[i]==3)	num++;
		if(num>num1)	return 0;
		if(a[i]==1)	num1++; 
	}
	if(num!=num1)	return 0;
	return 1;
}
void dfs(int now)
{
	if(now>n)	return ;
	if(now==n)
	{
		if(a[now]==4)
		{
			for(int i=1;i<=3;i++)
			{
				a[now]=i;
				if(check())	
				{
					ans=(ans+1)%mod;
				}
			}
			return ;
		}
		else 
		{
			if(check())	
			{
				ans=(ans+1)%mod;
			}
			return ;
		}	
	}
	if(a[now]==4)
	{
		for(int i=1;i<=3;i++)
		{
		int t=a[now];
		a[now]=i;
		dfs(now+1);
		a[now]=t;
		}	
	}
	else 
		dfs(now+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='(')	a[i]=1;
		if(c=='*')	a[i]=2;
		if(c==')')	a[i]=3;
		if(c=='?')	a[i]=4;
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
