#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#include<set>
#define ll long long
using namespace std;
set<ll> s[80];
ll a[10002],sz; 
ll ans=0x3fffffff,n,k;
void dfs(ll x,ll k)
{
	if(x==n+1)	
	{       
		  ll jc=0;
		   for(ll i=1;i<=k;i++)
			{
				if(s[i].size()<sz)
			 return;
			}
			for(ll i=1;i<=k;i++)
			{
				jc+=(*(--s[i].end()))-*s[i].begin();	
			}
			ans=min(ans,jc);
			return;
	}
	for(ll i=1;i<=k;i++)
	{
		ll nw=a[x];
		if(s[i].find(nw)==s[i].end()&&s[i].size()<sz)
		{
			s[i].insert(nw);
	
		    dfs(x+1,k);
		    s[i].erase(nw);
		}
    }
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
  scanf("%lld%lld",&n,&k);
  for(ll i=1;i<=n;i++)
  {
  	scanf("%lld",&a[i]);
  }
  sz=n/k;
  dfs(1,k);
  printf("%lld",ans);
	return 0;
}
