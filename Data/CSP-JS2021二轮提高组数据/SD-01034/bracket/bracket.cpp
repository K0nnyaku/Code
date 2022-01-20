#include<stdio.h>
#include<string.h>

const int P=1e9+7;
inline void mod(int &x){ (x>=P)&&(x-=P); }

int n,k;
char s[502];
int dp[502][502][3],sum[502][502];

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)
	{
		dp[i+1][i][0]=sum[i+1][i]=1;
		if(s[i]=='*'||s[i]=='?') dp[i][i][2]=sum[i][i]=1;
	}
	for(int len=2;len<=n;len++)
		for(int l=1,r=l+len-1;r<=n;l++,r++)
		{
			if(s[l]=='('||s[l]=='?')
				for(int i=l+1;i<=r;i++)
					if(s[i]==')'||s[i]=='?')
						dp[l][r][0]=(dp[l][r][0]+(long long)sum[l+1][i-1]*(dp[i+1][r][1]+dp[i+1][r][0]))%P;
			for(int i=1;(s[l+i-1]=='*'||s[l+i-1]=='?')&&i<len&&i<=k;i++) mod(dp[l][r][1]+=dp[l+i][r][0]);
			for(int i=1;(s[r-i+1]=='*'||s[r-i+1]=='?')&&i<=len&&i<=k;i++) mod(dp[l][r][2]+=dp[l][r-i][0]);
			sum[l][r]=((long long)dp[l][r][0]+dp[l][r][1]+dp[l][r][2])%P;
		}
	printf("%d\n",dp[1][n][0]);
	return 0;
}
