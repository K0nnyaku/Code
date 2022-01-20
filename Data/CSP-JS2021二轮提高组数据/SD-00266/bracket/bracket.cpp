#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,k,d[555][555][2],sum[555];
char s[555];
bool can_bracket(ll i,ll j){
	return (s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?');
}bool can_star(ll i,ll j){
	return sum[j]-sum[i-1]==j-i+1&&j-i+1<=k; 
}
ll dp(ll i,ll j,ll p){
	ll&ans=d[i][j][p];
	if(ans!=-1)return ans;
	if(i>=j)return ans=0;
	if(p==0){
		ans=0;
		if(can_bracket(i,j)&&can_star(i+1,j-1))ans++;
		if(can_bracket(i,j)){
			ans=(ans+dp(i+1,j-1,1))%mod;
			for(ll len=1;len<=k&&i+1+len<=j-1;len++){
				if(can_star(i+1,i+len))ans=(ans+dp(i+len+1,j-1,1))%mod;
				if(can_star(j-len,j-1))ans=(ans+dp(i+1,j-len-1,1))%mod; 
			}
		}
		return ans;
	}
	ans=dp(i,j,0);
	for(ll x=i;x<j;x++){
		for(ll len=0;len<=k&&x+len+1<=j;len++)
			if(can_star(x+1,x+len))
				ans=(ans+dp(i,x,0)*dp(x+len+1,j,1)%mod)%mod;
	}
	ans=(ans%mod+mod)%mod;
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s+1;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]=='*'||s[i]=='?')sum[i]++;
	}memset(d,-1,sizeof(d));
	cout<<dp(1,n,1)<<endl; 
	return 0;
}
