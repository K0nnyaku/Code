#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#define lll long long
using namespace std;
lll tr[100001];
lll n;
lll lowbit(lll x){
	return x&-x;
}
void add(lll x,lll k){
	for(lll i=x;i<=n;++i){
		tr[i]+=k;
	}
	return ;
}
lll que(lll x){
	lll ans=0;
	while(x){
		ans+=tr[x];
		x-=lowbit(x);
	} 
	return ans;
}

char s[600];
lll k;
lll sum[600];
lll mod=1000000007;
lll dp[600][600];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	scanf("%s",s+1); 
	for(lll i=1;i<=n;++i){
		if(s[i]=='*'||s[i]=='?'){
			sum[i]++;
		}
		sum[i]+=sum[i-1];
	//	cout<<sum[i];
	} 
	//cout<<sum[4]-sum[1];
	for(lll l=1;l<=n;++l){
		for(lll i=1;i+l<=n;++i){
			lll r=l+i; 
			//if(s[i]=='*'||s[r]=='*') continue;
			if((s[i]=='('&&s[r]==')')||(s[i]=='?'&&s[r]=='?')||(s[i]=='('&&s[r]=='?')||(s[r]==')'&&s[i]=='?')){
				if(r==i+1){
					dp[i][r]++;
			//		cout<<"L "<<i<<"R "<<r<<dp[i][r]<<" ";
					continue;
				}else{
	//				cout<<"F";
					if(sum[r-1]-sum[i]==(r-i-1)&&(r-i-1)<=k){
						dp[i][r]++;
					}
					dp[i][r]+=dp[i+1][r-1];
				}
				dp[i][r]%=mod;
				for(lll z=1;z<=k&&(i+z+1)<r;++z){
					if(s[i+z]=='*'||s[i+z]=='?'){
						dp[i][r]+=dp[i+z+1][r-1]; 
						dp[i][r]%=mod;
					} else{
						break;
					}
				} 
				dp[i][r]%=mod;
				for(lll z=1;z<=k&&(r-z-1)>i;++z){
					if(s[r-z]=='*'||s[r-z]=='?'){
						dp[i][r]+=dp[i+1][r-z-1];
						dp[i][r]%=mod;
					}else{
						break;
					}
				}
			//	if(i==1&&r==5){
			//		cout<<dp[i][r]<<endl;
			//	}
				for(lll k1=i+1;k1<r;++k1){
					if(dp[i][k1]==0) continue;
					for(lll k2=k1+1;k2<r&&k2<=k1+k+1;++k2){
						if(sum[k2-1]-sum[k1]==(k2-1-k1)){
							dp[i][r]+=(dp[i][k1]*dp[k2][r])%mod;
						}
					}
				}
			}
			//cout<<"L"<<i<<" R"<<r<<dp[i][r]<<" ";
		}
	//	cout<<endl;
	} 
	cout<<dp[1][n];
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

