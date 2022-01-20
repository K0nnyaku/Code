#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long
namespace name
{
	
	const ll N=1e6+5; 
	
	ll T,n;
	ll shu[N]; 
	
	ll mir[N];
	ll an[N],top;
	ll re;
	void check()
	{
		ll l=0;
		ll r=n*2+1;
		top=0;
		for(ll i=1;i<=n*2;++i)
		{
			if(mir[i]==1)
			{
				an[++top]=shu[++l];	
			}
			if(mir[i]==2)
			{
				an[++top]=shu[--r];	
			}
		}//system("pause");
	
		for(ll i=1;i<=n;++i)
		{
			if(an[i]!=an[2*n+1-i])
			{
				return ;
			}
		}
		
		for(ll i=1;i<=n*2;++i)
		{
			if(mir[i]==1)
			{
				printf("L");
			}
			else if(mir[i]==2)
			{
				printf("R");
			}
		}
		printf("\n");
		re=1;
		return ;
	}
	
	void dfs(ll step)
	{	
		if(step>n*2)
		{
			check();
			return;
		}
		if(re) return;
		mir[step]=1;
		dfs(step+1);
		if(re) return;
		mir[step]=2; 
		dfs(step+1);
	}
	
	void mymain()
	{
		scanf("%lld",&T);
		
		while(T--)
		{
			scanf("%lld",&n);
			
			for(ll i=1;i<=n*2;++i)
			{
				scanf("%lld",&shu[i]);
			}
			
			if(n>1000)
			{
				printf("-1\n");
				continue;
			}
			
//			if(n<=10)
//			{
			
				re=0;
				dfs(1);	
				if(re==0)
				{
					printf("-1\n");
				}
				continue;
//			}
//			else
//			{
//				
//			}
		} 
		
		return; 
	}
	
}


int main()
{
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	name::mymain();

	return 0;
}
/*
2
3
3 2 1 2 1 3
5
4 1 2 4 5 3 1 2 3 5


*/
