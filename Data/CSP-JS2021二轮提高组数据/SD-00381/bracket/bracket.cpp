#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
char s[507];
int n,K;
long long dp[507][507];
bool b[507][507];
bool qwq[507][507];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),K=read();
	scanf("%s",s+1);
	if(s[1]==')'||s[1]=='*'||s[n]=='('||s[n]=='*')
	{
		puts("0");
		return 0;
	}
	s[1]='(',s[n]=')';
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='('||s[i]=='*')
		continue;
		for(int j=i-1;j>=1;--j)
		{
			int len=i-j-1;
			if(s[j]==')'||s[j]=='*')
			continue;
			if(j==i-1)
			{
				if((s[j]=='('||s[j]=='?')&&(s[i]==')'||s[i]=='?'))
				dp[j][i]=1;
				continue;
			}
			for(int k=j+1;k<i-1;++k)
			{
				for(int k2=0;k2<=K;++k2)
				{
					if(k+k2+1>i)
					break;
					if(k2!=0&&s[k+k2]!='*'&&s[k+k2]!='?')
					break;
					dp[j][i]=(dp[j][i]+dp[j][k]*dp[k+k2+1][i]%mod)%mod;
			//		if(i==7&&j==2)
		//	cout<<dp[j][i]<<" "<<k2<<" "<<k+k2+1<<endl;
				}
			//	if(i==7&&j==1)
			//	cout<<k<<endl;
			}
		//	if(i==7&&j==2)
		//	cout<<dp[j][i]<<endl;
			for(int k0=1;k0<=min(len-1,K);++k0)
			{
				if(s[j+k0]!='*'&&s[j+k0]!='?')
				break;
				dp[j][i]=(dp[j][i]+dp[j+k0+1][i-1])%mod;
			}
			for(int k0=1;k0<=min(len-1,K);++k0)
			{
				if(s[i-k0]!='*'&&s[i-k0]!='?')
				break;
				dp[j][i]=(dp[j][i]+dp[j+1][i-k0-1])%mod;
			}
			
			if(len>K)
			continue;
			bool pd=0;
			for(int l=j+1;l<=i-1;++l)
			{
				if(s[l]!='*'&&s[l]!='?')
				{
					pd=1;
					break;
				}
			}
			if(!pd)
			++dp[j][i];
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=i;j<=n;++j)
//		{
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//		}
//	}
	printf("%lld",dp[1][n]%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
