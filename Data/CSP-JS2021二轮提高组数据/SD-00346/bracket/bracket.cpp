#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod = 1e9+7;
ll dp[600][600],c[600];
int cnt [600];
int k;
int main()
{
//freopen("bracket.in","r","stdin");
//freopen("bracket.out","w","stdout");
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		if(c[i]=='('||c[i]=='?'&&c[i+1]==')'||c[i+1]=='?')
        	dp[i][i+1]=cnt[i][i+1]=1;
        if(c[i]=='('||c[i]=='?')
        	for(int j=1;i<=m;j++)
        		int k=j+i;
        		if(k>n) 
					break;
        		if(c[k]==')')
					break;
        		if(c[k]=='?') 
					dp[i][k]++,dp[i][k]%=mod;
                else if(c[k]=='(')dp[i][k]++,dp[i][k]%=mod;
                break;
    for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	for(int len=3;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=len-1+i;
			int l=k+len-1;
			if(c[i]=='('||c[i]=='?'&&c[j]==')'||c[j]=='?')
				for(int k=j-1;k>i+1;k--)
					if(c[k]=='('||c[k]==')')
						break;
					(dp[i][j]+dp[k+1][j-1])%=mod;
				for(int k=i+1;k+1<j;k++)
				{
					(dp[i][j]+=(dp[i][k]*cnt[k+1][j])%mod)%=mod;
					(dp[i][j]+=(dp[i][k]*dp[k+1][j])%mod)%=mod;
				} 
			for(int k=0;k<m&&k+i<j;k++)
			{
				if(c[k+i]=='('||c[k+i]==')')
				{
					break;
				}
			}
	    }
	}            
 cout<<dp[1][n]<<endl;
 return 0;
}


