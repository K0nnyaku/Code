#include<bits/stdc++.h>
using namespace std;
//草
int n, maxk;
char s[505];
int ans;
int dp[505][505][505];  // 放到了第i位，前面有j个未闭合的左括号，k个*的方案数 
//第四维记录星后面有没有闭合过 
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> maxk;
	cin >> s + 1;
	dp[0][0][0] = 1;
	for(int i = 0; i <= n; i ++)
	{
		for(int j = 0; j <= n; j ++)
		{
			for(int k = 0; k <= n; k ++)
			{
				
				if(s[i + 1] == '(' || s[i + 1] == '?')
				{ 
					dp[i + 1][j + 1][0] += dp[i][j][k]; 
				}
				if(s[i + 1] == ')' || s[i + 1] == '?')
				{
					if(j - 1 >= 0)
					{
						dp[i + 1][j - 1][0] += dp[i][j][k];
					}
				}
				if(s[i + 1] == '*' || s[i + 1] == '?')
				{
					
					if(k + 1 <= maxk)
					{
						dp[i + 1][j][k + 1] += dp[i][j][k] + dp[i][j][k];
						//if(i + 1 == 6 && j  == 1 && k + 1 == 0) cout << i << " " <<j  <<" " << k << " " << dp[i][j][k] << endl;
						//if(i + 1 == 5) cout << i << " " <<j  <<" " << k << " " << dp[i][j][k] << endl;
					}
				}
			}
		}
	}
//	for(int i = 0; i <= maxk; i ++)
//	{
//		ans += dp[n][0][i];
//	}
	cout << dp[n][0][0] << endl;
	return 0;
}
