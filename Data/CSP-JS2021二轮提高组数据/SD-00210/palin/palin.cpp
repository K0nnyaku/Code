#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#define ll long long

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

const ll inf=1e9+10;
const ll maxn=1e3+10;
ll T,n,sum;
ll a[maxn],b[maxn];
char ans[maxn];

inline bool check()
{
	for(int i=1;i<=2*n;i++)
	{
		if(b[i]==b[2*n-i+1]) continue;
		else return false;
	}
	return true;
}

inline char trans(ll x)
{
	return x ? 'L' : 'R';
}

int main(void)
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		sum=0;
		for(int i=1;i<=2*n;i++) a[i]=read();
		for(int i=0;i<2*n;i++) ans[i]='R';
		for(ll S=0;S<(1<<(2*n));S++)
		{
			ll top=0,l=1,r=2*n;
			for(int i=1;i<=2*n;i++)
			{
				if(S&(1<<(i-1)))
				{
					b[++top]=a[l++];
				}
				else b[++top]=a[r--];
			}
			if(check())
			{
				sum=1;
				ll flag=0;
				for(int i=0;i<2*n;i++)
				{
					if(ans[i]>trans(S>>i&1)||flag)
					{
						ans[i]=trans(S>>i&1);
						flag=1;
					}
					else if(ans[i]<trans(S>>i&1)) break;
					else continue;
				}
			}
		}
		if(!sum) printf("-1");
		else for(int i=0;i<2*n;i++) printf("%c",ans[i]);		
		putchar(10);
	}
	return 0;
}

