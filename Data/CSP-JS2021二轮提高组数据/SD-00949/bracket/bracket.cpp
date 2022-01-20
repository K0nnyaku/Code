#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

namespace name
{
	#define ll long long
	
	const ll N=500+5; 
	const ll mod=1e9+7;
	ll n,k;
	string a;
	char s[N];
	ll ans=0;
	
	void check()
	{
		ll now=0,lef=0;
		ll ok=1;
//		ll mir[N];
//		ll zh[N];
		
		for(ll i=0;i<n;++i)
		{
			if(s[i]=='(')
			{
				ok=0;
				++lef;
			
			}
			if(s[i]==')')
			{
				--lef;
			}
			if(s[i]=='*')
			{
				if(ok)
				return;
				++now;
			}
			else
			{
				now=0;
			}
			if(now>k)
			{
				return; 
			}
			if(lef<0)
			{
				return;
			}
		}
		if(lef!=0)
		{
			return;
		}
		for(ll i=n-1;i>=0;--i)
		{
			if(s[i]=='*')
			{
				return;
			}
			else
			{
				break;
			}
		}
		
		
		ll zhan[N];
		ll vis[N];
		lef=0;
		for(ll i=0;i<n;++i)
		{
			zhan[i]=0;
			vis[i]=0;
		}
		for(ll i=0;i<n;++i)
		{
			if(s[i]=='(')
			{
			
				zhan[lef]=0;
				vis[lef]++;
				++lef;
			}
			if(s[i]==')')
			{
				if(zhan[lef]==1&&vis[lef]>1)
				{
					return; 
				}
				--lef;
			}
			if(s[i]=='*')
			{
				zhan[lef]=1;
			}
		} 
//		puts(s);
//		cout<<endl;
		++ans;
		return; 
	}
	
	void dfs(ll step)
	{
		if(step==n)
		{
			check();
		}
		if(a[step]=='?')
		{
			s[step]='(';
			dfs(step+1);
			s[step]=')';
			dfs(step+1);
			s[step]='*';
			dfs(step+1); 
		}
		else
		{
			if(a[step]=='(')
			{
				s[step]='(';
				dfs(step+1);
			}
			if(a[step]=='*')
			{
				s[step]='*';
				dfs(step+1);	
			} 
			if(a[step]==')')
			{
				s[step]=')';
				dfs(step+1);
			}
		}
	}
	
	void mymain()
	{
		cin>>n>>k;
		cin>>a;
		
		dfs(0);
		
		printf("%lld",ans);
		return; 
	}
	
}


int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	name::mymain();
	
	return 0;
}

/*

7 3
(*??*??

*/
