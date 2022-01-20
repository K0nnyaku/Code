#include<bits/stdc++.h>
using namespace std;
#define debug1 cout<<"debug";
int n,m; 
const int mod=1e9+7;
const int maxn=510;
int dp[maxn][maxn][maxn];
char str[maxn];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m;
	cin>>str+1;
	
	if(str[1]=='?') dp[1][0][1]=1,dp[1][1][0]=1;
	if(str[1]=='(') dp[1][1][0]=1;
	if(str[1]=='*') dp[1][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(str[i]=='*') dp[i][j][k]+=dp[i-1][j][k-1];
				if(str[i]=='('&&j!=0) dp[i][j][k]+=dp[i-1][j-1][k];
				if(str[i]==')'&&j!=n) dp[i][j][k]+=dp[i-1][j+1][k];
				if(str[i]=='?')
				{
					dp[i][j][k]+=dp[i-1][j][k-1];
					if(j!=0) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k])%mod;
					if(j!=n) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k])%mod;
				}

			}
		}
	}
	
	cout<<dp[n][0][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
