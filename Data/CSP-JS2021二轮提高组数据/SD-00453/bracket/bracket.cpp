#include <iostream>
#include <cstdio>
#define ll long long
#define q 1000000007
using namespace std;
ll n,k;
string s; 
bool b[510][510][2];
ll mem[510][510][2];
ll dfs(ll l,ll r,bool p){
//	cout<<"###"<<l<<" "<<r<<endl;
	if(l==r)return 0;
	if(b[l][r][p]){
//		cout<<l<<" "<<r<<" "<<mem[l][r][p]<<endl;
		return mem[l][r][p];
	}
	b[l][r][p]=1;
//	if(l==1&&r==5)cout<<s.size()<<endl;
	if(s[l]=='*'||s[l]==')'||s[r]=='*'||s[r]=='('){
//		cout<<l<<" "<<r<<" "<<0<<endl;
		return mem[l][r][p]=0;
	}
	ll ans=0;
	if(r==l+1){
//		cout<<l<<" "<<r<<" "<<1<<endl;
		return mem[l][r][p]=1;
	}
	if(s[r-1]==s[l+1]=='*'){
		if(r-l-1>k){
//			cout<<l<<" "<<r<<" "<<0<<endl;
			return mem[l][r][p]=0;
		}
		if(r-l-1<=k){
			bool st=1;
			for(ll i=l+2;i<=r-2;++i){
				if(s[i]=='('||s[i]==')'){
					st=0;
					break;
				}
			}
//			cout<<l<<" "<<r<<" "<<st<<endl;
			return mem[l][r][p]=st;
		}
	}
	if(r-l-1<=k){
		bool st=1;
		for(ll i=l+1;i<r;++i){
			if(s[i]=='('||s[i]==')'){
				st=0;
				break;
			}
		}
		ans+=st;
	}
	ans=(ans+dfs(l+1,r-1,1))%q;
	if(s[r-1]==')'||s[r-1]=='?'){
		for(ll i=l+1;i<=l+k&&i+1<r;++i){
			if(s[i]=='('||s[i]==')')break;
			ans=(ans+dfs(i+1,r-1,1))%q;
		}
	}
	if(s[l+1]=='('||s[l+1]=='?'){
		for(ll i=r-1;i>=r-k&&i-1>l;--i){
			if(s[i]=='('||s[i]==')')break;
			ans=(ans+dfs(l+1,i-1,1))%q;
		}
	}
	if(p)
	for(ll i=l+1;i<r-1;++i){
		if(s[i]=='*'||s[i]=='(')continue;
		if(s[i+1]=='('||s[i+1]=='?')ans=(ans+dfs(l,i,1)*dfs(i+1,r,0))%q;
		for(ll j=1;j<=k&&i+j+1<=r-1;++j){
			if(s[i+j]=='('||s[i+j]==')')break;
			ans=(ans+dfs(l,i,1)*dfs(i+j+1,r,0))%q;
		}
	}
//	cout<<l<<" "<<r<<" "<<ans<<endl;
	return mem[l][r][p]=ans;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	cout<<dfs(0,n-1,1)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
