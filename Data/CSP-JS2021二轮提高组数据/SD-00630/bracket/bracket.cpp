#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int N=1005,mod=1e9+7;
int n,K,dp[N][N][2],s1[N],s2[N],ne[N],sum[N];
char s[N];

inline bool check(int l,int r)
{
	if(r-l+1>K) return 0;
	if(s1[r]-s1[l-1]!=0) return 0;
	if(s2[r]-s2[l-1]!=0) return 0;
	return 1;
}

inline int MOD(int x)
{
	return x>mod?x-mod:x;
}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();K=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		s1[i]=s1[i-1]+(s[i]=='(');
	for(int i=1;i<=n;++i)
		s2[i]=s2[i-1]+(s[i]==')');
	for(int l=2;l<=n;++l)
		for(int i=1;i+l-1<=n;++i)
		{
			int j=i+l-1,flag=1;
			if(s[i]!='('&&s[i]!='?') flag=0;
			if(s[j]!=')'&&s[j]!='?') flag=0;
			if(l==2)
			{
				dp[i][j][1]=flag;
				continue;
			}
			if(flag)
			{
				dp[i][j][1]=MOD(dp[i][j][1]+dp[i+1][j-1][1]);
				dp[i][j][1]=MOD(dp[i][j][1]+dp[i+1][j-1][0]);
				if(check(i+1,j-1)) dp[i][j][1]=MOD(dp[i][j][1]+1);
				for(int k=i+1;k<=j-2;++k)
					if(check(i+1,k))
					{
						dp[i][j][1]=MOD(dp[i][j][1]+dp[k+1][j-1][0]);
						dp[i][j][1]=MOD(dp[i][j][1]+dp[k+1][j-1][1]);
					}
				for(int k=j-1;k>=i+2;--k)
					if(check(k,j-1))
					{
						dp[i][j][1]=MOD(dp[i][j][1]+dp[i+1][k-1][0]);
						dp[i][j][1]=MOD(dp[i][j][1]+dp[i+1][k-1][1]);
					}
			}
			for(int k=i;k<=j-1;++k)
				dp[i][j][0]=MOD(dp[i][j][0]+dp[i][k][1]*1ll*(dp[k+1][j][0]+dp[k+1][j][1])%mod);
			ne[j+1]=j+1;sum[j+1]=0;
			for(int k=j;k>=i;--k)
			{
				if(s[k]==')'||s[k]=='(')
					ne[k]=k;
				else ne[k]=ne[k+1];
				sum[k]=MOD(sum[k+1]+dp[k][j][0]);
				sum[k]=MOD(sum[k]+dp[k][j][1]);
			}
			for(int k1=i;k1<=j-2;++k1)
				if(s[k1+1]!='('&&s[k1+1]!=')')
				{
					int lim=ne[k1+1]-1;
					lim=min(lim,k1+K);
					lim=min(lim,j-1);
					if(k1+2<=lim+1)
					{
						int qwq=MOD(sum[k1+2]-sum[lim+2]+mod);
						dp[i][j][0]=MOD(dp[i][j][0]+dp[i][k1][1]*1ll*qwq%mod);
					}
				}
		}
	printf("%d\n",(dp[1][n][0]+dp[1][n][1])%mod);
	return 0;
}
