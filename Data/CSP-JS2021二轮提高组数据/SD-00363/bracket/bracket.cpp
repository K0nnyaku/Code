#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long lli;
const lli mod=1000000007;
lli n,k,dp[502][502],dpp[502][502],ge[502];
string s;
bool vi[502][502],vii[502][502];
lli gee(lli x) {
	if(x<1||x>n) {
		return 4;
	}
	if(s[x-1]=='*') {
		return 1;
	}
	if(s[x-1]=='(') {
		return 2;
	}
	if(s[x-1]==')') {
		return 3;
	}
	return 0;
}
bool hf(lli l,lli r) {
	if(l>=r||l<1||r>n) {
		return 1;
	}
	if(ge[l]&1||ge[r]==1||ge[r]==2) {
		return 1;
	}
	return 0;
}
lli mmaxi[502];
lli maxi(lli x) {
	if(ge[x]!=0&&ge[x]!=1) {
		return 0;
	}
	if(mmaxi[x]) {
		return mmaxi[x];
	}
	return mmaxi[x]=min(k,maxi(x+1)+1);
}
lli dfs(lli l,lli r);
lli df(lli l,lli r) {
	if(vii[l][r]) {
		return dpp[l][r];
	}
	vii[l][r]=1;
	if(hf(l,r)) {
		return 0;
	}
	if(l==r-1) {
		return dpp[l][r]=1;
	}
	if(maxi(l+1)+l>=r-1) {
		dpp[l][r]=1;

	}
	dpp[l][r]+=dfs(l+1,r-1);
	for(lli i=1; i<=min(r-l-3,maxi(l+1)); i++) {
		dpp[l][r]+=dfs(l+i+1,r-1);
		dpp[l][r]%=mod;
	}
	for(lli i=l+2; i<=r-2; i++) {
		if(i+maxi(i+1)>=r-1) {
			dpp[l][r]+=dfs(l+1,i);
			dpp[l][r]%=mod;
		}
	}
	return (dpp[l][r]%=mod);
}
lli hee[502][502],pu[502];
void chu(lli z) {
	if(pu[z]) {
		return;
	}
	pu[z]=1;
	for(lli i=1; i<z; i++) {
		hee[z][i]=(hee[z][i-1]+df(i,z))%mod;
	}
}
lli he(lli x,lli y,lli z) {
	chu(z);
	return (mod+mod+mod+hee[z][y]-hee[z][x-1])%mod;
}
lli dfs(lli l,lli r) {
	if(vi[l][r]) {
		return dp[l][r];
	}
	vi[l][r]=1;
	if(hf(l,r)) {
		return 0;
	}
	dp[l][r]+=df(l,r);
	for(lli i=l+1; i<=r-2; i++) {
		dp[l][r]+=dfs(l,i)*he(i+1,min(r-1,i+1+maxi(i+1)),r);
		dp[l][r]%=mod;
	}
	return (dp[l][r]%=mod);
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lli%lli",&n,&k);
	cin>>s;
	for(lli i=1;i<=n;i++){
		ge[i]=gee(i);
	}
	printf("%lli\n",dfs(1,n));
	return 0;
}

