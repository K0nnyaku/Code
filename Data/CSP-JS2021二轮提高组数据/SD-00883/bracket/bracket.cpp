#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define N 510
using namespace std;
const int mod=1000000007;
int n,k;
int dp[N][N];
int dp2[N][N];
int dp3[N][N];
string a;
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	a=" "+a;
	for(int i=1;i<=n;i++){
		dp3[i][i-1]=dp[i][i-1]=1;
	}
	for(int i=1;i<n;i++){
		if((a[i]=='('||a[i]=='?')&&(a[i+1]==')'||a[i+1]=='?')){
			dp3[i][i+1]=dp[i][i+1]=dp2[i][i+1]=1;
		}
	}
	for(int len=3;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if((a[l]=='('||a[l]=='?')&&(a[r]==')'||a[r]=='?')){
				for(int i=0;i<=k&&l+i+1<=r;i++){
					if(i!=0&&a[l+i]!='*'&&a[l+i]!='?'){
						break;
					}
					dp[l][r]+=dp3[l+i+1][r-1];
					dp[l][r]%=mod;
				}
				for(int i=1;i<=k&&r-i-1>l;i++){
					if(i!=0&&a[r-i]!='*'&&a[r-i]!='?'){
						break;
					}
					dp[l][r]+=dp3[l+1][r-i-1];
					dp[l][r]%=mod;
				}
				for(int i=l+1;i<r-1;i++){
					dp3[l][r]+=dp[l][i]*dp2[i+1][r]%mod;
					dp3[l][r]%=mod;
				}
				dp3[l][r]+=dp[l][r];
				dp3[l][r]%=mod;
			}
			for(int i=0;i<=k&&l+i<r;i++){
				if(i!=0&&a[l+i-1]!='*'&&a[l+i-1]!='?'){
					break;
				}
				dp2[l][r]+=dp3[l+i][r];
				dp2[l][r]%=mod;
			}
		}
	}
	cout<<dp3[1][n];
	return 0;
}
