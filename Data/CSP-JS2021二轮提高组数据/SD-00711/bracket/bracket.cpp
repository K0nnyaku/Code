#include<iostream>
#include<cstdio>
#include<cmath>//fuck you ccf,cnm,nmsl!为什么这一题情况会重复啊！！为什么AB也是合法的啊！！！ 
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const ll N=505,mod=1e9+7;
ll read(){
	ll a=0,x=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')	x=-x;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*x;
}
ll dp[N][N][N],s[N][N];
ll n,K;
char c[N];
bool pd(ll i,ll j){
	if((c[i]=='('&&c[j]==')')||(c[i]=='('&&c[j]=='?')||(c[i]=='?'&&c[j]==')')||(c[i]=='?'&&c[j]=='?'))	return true;
	return false;
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),K=read();
	for(int i=1;i<=n;i++)
		c[i]=getchar();
	for(ll i=1;i<=n;i++)	
	{	
		if(c[i]=='*'||c[i]=='?'&&K>=1)	s[i][i]=1;
	}
	for(ll i=1;i<=n;i++){
		for(ll l=2;l+i-1<=n&&l<=K;l++){
			ll j=l+i-1;
			if(s[i][j-1]&&s[j][j])	s[i][j]=1;
		}
	}
	for(ll l=2;l<=n;l++){
		for(ll i=1;l+i-1<=n;i++){
			ll j=l+i-1;
			if(c[i]==')'||c[i]=='*'||c[j]=='('||c[j]=='*')	continue;
			ll maxn=0;
			for(int k=i;k<j;k++){
				dp[i][j][0]=(dp[i][j][0]+dp[i][k][1]*(dp[k+1][j][1]+dp[k+1][j][0]))%mod;
			}
			for(int k=i;k<j;k++){
				
				for(int p=k+1;p<=j&&p-1-k<=K;p++){
					if(s[k+1][p-1]){
						dp[i][j][0]=(dp[i][j][0]+(dp[i][k][1])*(dp[p][j][1]+dp[p][j][0]))%mod;
					}
					
				}
			}
			if(pd(i,j)){
				if(l==2){
					dp[i][j][1]=1;
					dp[i][j][1]%=mod;continue;
				}
				dp[i][j][1]+=dp[i+1][j-1][1]+dp[i+1][j-1][0];
				dp[i][j][1]%=mod;
				if(s[i+1][j-1])	dp[i][j][1]++;
				dp[i][j][1]%=mod;
				for(int k=i+1;k<=i+K&&k<j;k++){
					if(c[k]=='*'||c[k]=='?')	dp[i][j][1]+=(dp[k+1][j-1][0]+dp[k+1][j-1][1]),dp[i][j][1]%=mod;
					else break;
				}
				for(int k=j-1;k>=j-K&&k>i;k--){
					if(c[k]=='*'||c[k]=='?')	dp[i][j][1]+=(dp[i+1][k-1][0]+dp[i+1][k-1][1]),dp[i][j][1]%=mod;
					else break;
				}
			}
			
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
		}
	}*/
	printf("%lld",(dp[1][n][0]+dp[1][n][1])%ll(1e9+7));
	return 0;
}

