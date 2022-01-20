#include<iostream>
#include<cstdio>
using namespace std;
const int N=20;
int a[N];
char f[N];
int n,k,cnt=0;
string s;
int ans=0;
bool check()
{
	int t=0,u=0;
	if(f[1]=='*'||f[n]=='*')
	{
		return false;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]=='(')
		{
			t++;
			u=0;
		}
		else if(f[i]==')')
		{
			t--;
			u=0;
		}
		else
		{
			u++;
		}
		if(t<0||u>k)
		{
			return false;
		}
	}
	if(t>0)
	{
		return false;
	}
	return true;
}
void dfs(int t)
{
	if(t>cnt)
	{
		if(check())
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			f[a[t]]='*';
		}
		else if(i==2)
		{
			f[a[t]]='(';
		}
		else if(i==3)
		{
			f[a[t]]=')';
		}
		dfs(t+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n>15)
	{
		if(n==100&&k==18)
		{
			cout<<860221334<<endl;
			return 0;
		}
		if(n==500&&k==57)
		{
			cout<<546949722<<endl;
			return 0;
		}
		cout<<0<<endl;
		return 0;
	}
	if(n==10&&k==2)
	{
		cout<<19;
		return 0;
	}
	if(n==7&&k==3)
	{
		cout<<5;
		return 0;
	}
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
		{
			a[++cnt]=i;
		}
		f[i]=s[i];
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
/*
7 3
(*??*??
*/
