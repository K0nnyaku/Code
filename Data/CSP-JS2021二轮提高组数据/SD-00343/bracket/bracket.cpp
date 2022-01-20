#include<iostream>
#include<cstdio>
#define int long long
#define p 1000000007
using namespace std;
int n, m;
char c[510];
int dp[510][510], dp1[510][510];
int cnt[510][510];
signed main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++){
//		if((c[i] == '(' || c[i] == '?') && (c[i + 1] == ')' || c[i + 1] == '?'))
//			dp[i][i + 1]++, dp[i][i + 1] %= p;
		if(c[i] == '(' || c[i] == '?')
			for(int j = 0; j <= m; j++){
				int k = i + j + 1;
				if(k > n)
					break;
				if(c[k] == '(')
					break;
				if(c[k] == '?')
					dp[i][k]++, dp[i][k] %= p/*, cout << i <<" "<<k<<"\n"*/, dp1[i][k] = dp[i][k];
				else if(c[k] == ')'){
					dp[i][k]++, dp[i][k] %= p/*, cout << i <<" "<<k<<" \n"*/, dp1[i][k] = dp[i][k];
					break;
				}
			}
	}
//	for(int i = 1; i <= n; i++)
//		for(int j = i + 1; j <= n; j++)
//			cnt[i][j] += cnt[i][j - 1];
	for(int len = 3; len <= n; len++)
		for(int i = 1; i + len - 1 <= n; i++){
			int j = i + len - 1;
			if((c[i] == '(' || c[i] == '?') && (c[j] == ')' || c[j] == '?')){
				for(int k = j - 1; k > i + 1 && j - k <= m; k--){
					if(c[k] == '(' || c[k] == ')')
						break;
					(dp[i][j] += dp[i + 1][k - 1]) %= p;
				}
//			cout <<dp[i][j] <<" ";
				for(int k = i + 1; k < j - 1 && k - i <= m; k++){
					if(c[k] == '(' || c[k] == ')')
						break;
					(dp[i][j] += dp[k + 1][j - 1]) %= p;
				}
//			cout <<dp[i][j] <<" ";
				(dp[i][j] += dp[i + 1][j - 1]) %= p;
//			cout <<dp[i][j] <<" ";
				dp1[i][j] = dp[i][j];
			}
//			bool flag = 0;
			for(int k = i + 1; k + 1 < j; k++){
//				if(!flag)
//					(dp[i][j] += (dp[i][k] * cnt[k + 1][j]) % p) %= p;
//				else
					(dp[i][j] += (dp1[i][k] * cnt[k + 1][j]) % p) %= p;
//				if(cnt[k + 1][j] != 0)
//					flag = 1;
//				if(!flag)
					(dp[i][j] += dp1[i][k] * dp[k + 1][j] % p) %= p;
//				else
//					(dp[i][j] += dp1[i][k] * dp[k + 1][j] % p) %= p;
//				if(dp[k + 1][j] != 0)
//					flag = 1;
			}
//			cout <<dp[i][j] <<" ";
			for(int k = 0; k < m && i + k < j; k++){
				if(c[i + k] == '(' || c[i + k] == ')')
					break;
				(cnt[i][j] += dp[i + k + 1][j]) %= p;
//				if(i == 2 && j == 9)
//					cout << i + 1 + k<<" "<<dp[i + k + 1][j]<<"\n";
			}
//			cout <<cnt[i][j]<<" "<< dp[i][j] <<" "<<i<<" "<<j<<"\n";
		}
//	cout << dp[3][4]<<" ";
	printf("%lld", dp[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
