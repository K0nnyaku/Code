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

const ll maxn=510;
const ll mod=1e9+7;
ll n,K;
ll dp[2][maxn][maxn][3];
char s[maxn];

namespace sub1
{
	ll ans=0;
	ll a[maxn];
	inline void dfs(ll x)
	{
		if(x>n)
		{
			ll flag=0,c=0,len=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='('||a[i]==1) cnt++,len=0;
				if(s[i]==')'||a[i]==2)
				{
					cnt--;
					len=0;
					if(cnt==0) flag=0;
					else if(cnt<0) c=1;
					else flag=2;
				}
				if(s[i]=='*'||a[i]==3)
				{
					len++;
					if(len>K) c=1;
					if(flag==2) c=1;
				}
			}
			if(c==0) ans++;
			return ;
		}
		if(s[x]=='?')
		{
			for(int i=1;i<=3;i++)
			{
				 a[x]=i;
				 dfs(x+1);
				 a[x]=0;
			}
		}
		else dfs(x+1);
	}
	
	inline void sol()
	{
		dfs(1);
		printf("%lld\n",ans);
	}
}

namespace sub2
{
	inline void sol()
	{
		dp[0][0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			ll now=i&1,lst=(i-1)&1;
			for(int j=0;j<=K;j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(s[i]=='('||s[i]=='?')
					{
						if(k) (dp[now][0][k][1]+=dp[lst][j][k-1][0]+dp[lst][j][k-1][1]+dp[lst][j][k-1][2])%=mod;
					}
					if(s[i]==')'||s[i]=='?')
					{
						if(k==0) (dp[now][0][k][0]+=dp[lst][j][k+1][1]+dp[lst][j][k+1][2])%=mod;
						else (dp[now][0][k][2]+=dp[lst][j][k+1][0]+dp[lst][j][k+1][1]+dp[lst][j][k+1][2])%=mod;
					}
					if(s[i]=='*'||s[i]=='?')
					{
						if(j&&i!=1&&i!=n)
						{
							(dp[now][j][k][0]+=dp[lst][j-1][k][0])%=mod;
							(dp[now][j][k][1]+=dp[lst][j-1][k][1])%=mod;
						}
					}
				}
			}
			memset(dp[lst],0,sizeof(dp[lst]));
		}
		printf("%lld\n",dp[n&1][0][0][0]);
	}
}

int main(void)
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),K=read();
	scanf("%s",s+1);
//	if(n<=15) sub1::sol();
	sub2::sol();
	
	return 0;
}

