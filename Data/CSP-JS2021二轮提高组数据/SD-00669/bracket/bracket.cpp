#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long int n,k,mod=1000000007,kong,rem[1001][501],ceng[500];
char c[1000],hf[500];
long long int dfs(long long int pos,long long int ws,long long int fd)
{
//	cout<<pos<<endl;
	if(fd<0)
	return 0;
	if(pos==n-1)
	{
		if(fd==1)
		{
		/*	for(int i=0;i<n-1;i++)
			{
				cout<<hf[i];
			}
			cout<<')'<<endl;*/
			return 1;
			
		}
		else
		return 0;
	}
	if(fd>n/2)
	return 0;
	if(ws>k)
	return 0;
	/*if(rem[fd+500][pos]!=0)
	{
		for(int i=0;i<n-1;i++)
			{
				cout<<hf[i];
			}
			cout<<endl;
		cout<<"         "<<rem[fd+500][pos]<<endl;
		return rem[fd+500][pos];
	}
	*/
	long long int res=0;
	if(c[pos]=='(')
	{
		hf[pos]='(';
		res=dfs(pos+1,0,fd+1)%mod;
	}
	else if(c[pos]==')')
	{
		hf[pos]=')';
		res=dfs(pos+1,0,fd-1)%mod;
	}
	else if(c[pos]=='*')
	{
		hf[pos]='*';
		res=dfs(pos+1,ws+1,fd)%mod;
	}
	else 
	{
		hf[pos]='(';
		res=dfs(pos+1,0,fd+1)%mod;
		hf[pos]=')';
		res=(res+dfs(pos+1,0,fd-1)%mod)%mod;
		hf[pos]='*';
		res=(res+dfs(pos+1,ws+1,fd)%mod)%mod;
	}
	res%=mod;
//	rem[fd+500][pos]=res;
	return res;
} 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[0]=='?')
		{
			c[0]='(';
		}
		if(c[i]=='?')
		if(i==0)
		{
			c[0]='(';
		}
		else if(i==n-1)
		c[n-1]=')';
		/*else
		kong++;*/
		
	}
	if(c[0]!='('||c[n-1]!=')')
	{
		cout<<c[0]<<c[n-1];
		cout<<0;
		return 0;
	}
	cout<<dfs(0,0,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
