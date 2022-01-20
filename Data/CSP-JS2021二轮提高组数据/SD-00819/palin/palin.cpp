#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

namespace _yz
{
	typedef long long ll;
	const ll N=1000000+10;
	
	ll n,a[N],b[N],ans[N],ok=0;
	
	void dfs(ll step,ll l,ll r)
	{
		if(ok) return;
		if(step>n*2)
		{
			for(ll i=1;i<=n;i++)
			{
				if(b[i]!=b[2*n+1-i])
					return;
			}
			for(ll i=1;i<=n*2;i++)
			{
				if(ans[i]==1) printf("L");
				else printf("R");
			}
			printf("\n");
			ok=1;
			return;
		}
		b[step]=a[l]; ans[step]=1;
		dfs(step+1,l+1,r);
		if(ok) return;
		b[step]=a[r]; ans[step]=2;
		dfs(step+1,l,r-1);
		return;
	}
	void main()
	{
		ll T;
		scanf("%lld",&T);
		while(T--)
		{
			scanf("%lld",&n);
			for(ll i=1;i<=n*2;i++)
			{
				scanf("%lld",a+i);
			}
			ok=0;
			dfs(1,1,n*2);
			if(ok==0)
			{
				printf("-1\n");
			}
		}
		return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	_yz::main();
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

LRRLLRRRRL
-1
-----------------
2
3
3 2 1 2 1 3
5
4 1 2 4 5 3 1 2 3 5

*/
