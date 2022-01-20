#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const long long mod=1e9+7;
string s;
long long a[100000],top=0,ans=0;
long long xh[10000];
long long f[10000];
long long n,m;
void dfs(long long t,long long kh,long long cs)
{ 
	if(t==s.size())
	{
		if(s[0]=='*')
		{
			return ;
		}
		if(s[s.size()-1]=='*')
		{
			return ;
		}
		if(kh>0)
		{
			return ;
		} 
		if(xh[0]>0)
		{
			return ;
		}
		ans++;
		ans%=mod;
		return ;
	}
	if(s[t]=='(')
	{
		long long hf=xh[cs];
		if(xh[cs]!=0)
		{
			f[cs]++;
		}
		xh[cs]=0;
		dfs(t+1,kh+1,cs+1);
		if(hf!=0)
		{
			f[cs]--;
		} 
		xh[cs]=hf;
	}
	else if(s[t]==')')
	{
		long long f1=0,hf=0,hf1=0;
		if(f[cs]==2&&xh[cs]!=0)
		{
			f1=1;
		}
		hf=xh[cs];
		hf1=f[cs];
		xh[cs]=0;
		f[cs]=0;
		f[cs-1]++;
		if(kh-1<0)
		{
			f1=1;
		}
		if(f1==0)
		{
			dfs(t+1,kh-1,cs-1);
		}
		xh[cs]=hf;
		f[cs]=hf1;
		f[cs-1]--;
	}
	else if(s[t]=='*')
	{
		xh[cs]++;
		dfs(t+1,kh,cs);
		xh[cs]--;
	}
	else
	{
		bool f1=0;
		s[t]='(';
		long long hf=xh[cs],hf1=0;
		if(xh[cs]!=0)
		{
			f[cs]++;
		}
		xh[cs]=0;
		dfs(t+1,kh+1,cs+1);
		if(hf!=0)
		{
			f[cs]--;
		}
		xh[cs]=hf;
		s[t]=')';
		if(f[cs]==2&&xh[cs]!=0)
		{
			f1=1;
		}
		hf=xh[cs];
		hf1=f[cs];
		xh[cs]=0;
		f[cs]=0;
		f[cs-1]++;
		if(kh-1<0)
		{
			f1=1;
		}
		if(f1==0)
		{
			dfs(t+1,kh-1,cs-1);
		}
		xh[cs]=hf;
		f[cs]=hf1;
		f[cs-1]--;
		s[t]='*';
		f1=0;
		if(xh[cs]+1>m)
		{
			f1=1;
		}
		xh[cs]++;
		if(f1==0)
		dfs(t+1,kh,cs);
		xh[cs]--;
		s[t]='?';	
	}
	return ; 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	long long i;
	cin>>n>>m>>s;
	dfs(0,0,0);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
