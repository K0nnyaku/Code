#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

namespace _yz
{
	typedef long long ll;
	const ll N=100000+10;
	struct node
	{
		ll l,r;
	}a[N],b[N];
	ll n,m1,m2,s1[N],s2[N];
	ll num1[N],num2[N];
	ll n1,n2,ans=0;
	void cheat()
	{
		for(ll i=0;i<=n;i++)
		{
			n1=i;n2=n-i;
			ll cnt=0;
			for(ll j=1;j<=n1;j++)
			{
				s1[j]=0;
			}
			for(ll j=1;j<=n2;j++)
			{
				s2[j]=0;
			}
			for(ll j=1;j<=m1;j++)
			{
				for(ll k=1;k<=n1;k++)
				{
					if(s1[k]<a[j].l)
					{
						//printf("ok: %lld <- %lld\n",s1[k],a[j].l);
						s1[k]=a[j].r;
						cnt++;
						break;
					}
				}
				/*printf("s1: ");
				for(ll k=1;k<=n1;k++)
				{
					printf("%lld ",s1[i]);
				}
				printf("\n");*/
			}
			for(ll j=1;j<=m2;j++)
			{
				for(ll k=1;k<=n2;k++)
				{
					if(s2[k]<b[j].l)
					{
						//printf("ok: %lld <- %lld\n",s2[k],b[j].l);
						s2[k]=b[j].r;
						cnt++;
						break;
					}
				}
				/*printf("s2: ");
				for(ll k=1;k<=n2;k++)
				{
					printf("%lld ",s2[i]);
				}
				printf("\n");*/
			}
			//printf("(%lld,%lld): %lld\n",n1,n2,cnt);
			ans=max(ans,cnt);
		}
		return;
	}
	void solve()
	{
			n1=n;n2=n;
			ll cnt=0;
			for(ll j=1;j<=m1;j++)
			{
				for(ll k=1;k<=n1;k++)
				{
					if(s1[k]<a[j].l)
					{
						//printf("ok: %lld <- %lld\n",s1[k],a[j].l);
						s1[k]=a[j].r;
						num1[k]++;
						cnt++;
						break;
					}
				}
				/*printf("s1: ");
				for(ll k=1;k<=n1;k++)
				{
					printf("%lld ",s1[i]);
				}
				printf("\n");*/
			}
			for(ll j=1;j<=m2;j++)
			{
				for(ll k=1;k<=n2;k++)
				{
					if(s2[k]<b[j].l)
					{
						//printf("ok: %lld <- %lld\n",s2[k],b[j].l);
						s2[k]=b[j].r;
						num2[k]++;
						cnt++;
						break;
					}
				}
				/*printf("s2: ");
				for(ll k=1;k<=n2;k++)
				{
					printf("%lld ",s2[i]);
				}
				printf("\n");*/
			}
			//printf("(%lld,%lld): %lld\n",n1,n2,cnt);
			//ans=max(ans,cnt);
			
		
		//printf("s1: ");
		for(ll k=1;k<=n1;k++)
		{
			//printf("%lld ",num1[k]);
			num1[k]+=num1[k-1];
		}
		//printf("\n");
		
		//printf("s2: ");
		for(ll k=1;k<=n2;k++)
		{
			//printf("%lld ",num2[k]);
			num2[k]+=num2[k-1];
		}
		//printf("\n");
		
		for(ll i=0;i<=n;i++)
		{
			ans=max(ans,num1[i]+num2[n-i]);
		}
		return;
	}
	bool cmp(node a,node b)
	{
		return a.l<b.l;
	}
	void main()
	{
		scanf("%lld%lld%lld",&n,&m1,&m2);
		for(ll i=1;i<=m1;i++)
		{
			scanf("%lld%lld",&a[i].l,&a[i].r);
		}
		for(ll i=1;i<=m2;i++)
		{
			scanf("%lld%lld",&b[i].l,&b[i].r);
		}
		sort(a+1,a+1+m1,cmp);
		sort(b+1,b+1+m2,cmp);
		if(n<=100)
		{
			cheat();
			printf("%lld\n",ans);
			return;
		}
		else
		{
			solve();
			printf("%lld\n",ans);
			return;
		}
		return;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	_yz::main();
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

7
--------
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

4
*/
