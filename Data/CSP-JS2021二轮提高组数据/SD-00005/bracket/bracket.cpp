#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rop(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define por(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long ll;
namespace AnShu{

inline ll read(){
	ll W=0,F=1;
	char C=getchar();
	while((C<'0'||C>'9')&&C!='-') C=getchar();
	if(C=='-') F=-1,C=getchar();
	while(C>='0'&&C<='9') W=W*10+C-'0',C=getchar();
	return W*F;
}

const ll mod=1e9+7;
ll n,k,ans;
char s[502];
ll dfss(ll l,ll r);
ll dfsa(ll l,ll r);
ll dfs1(ll l,ll r);

ll dfss(ll l,ll r){
	if(r-l+1>k) return 0;
	rep(i,l,r) if(s[i]=='('||s[i]==')') return 0;
	return 1;
}

ll dfsa(ll l,ll r){
	if(r-l<1) return 0;
	if(r-l==1){
		if(!(s[l]==')'||s[l]=='*'||s[r]=='('||s[r]=='*')) return 1;
		return 0;
	}
	ll p=0;
	if(dfss(l,r)) p++,p%=mod;
	if(!(s[l]==')'||s[l]=='*'||s[r]=='('||s[r]=='*')){
		if(dfss(l+1,r-1)) p+=dfss(l+1,r-1),p%=mod;
		if(dfsa(l+1,r-1)) p+=dfsa(l+1,r-1),p%=mod;
		rop(i,l+1,r-1)
			if(dfss(l+1,i)&&dfsa(i+1,r-1)) p+=(dfss(l+1,i)*dfsa(i+1,r-1))%mod,p%=mod;
		rop(i,l+1,r-1)
			if(dfsa(l+1,i)&&dfss(i+1,r-1)) p+=(dfsa(l+1,i)*dfss(i+1,r-1))%mod,p%=mod;
	}
	rop(i,l,r)
		if(dfsa(l,i)&&dfsa(i+1,r)) p+=(dfsa(l,i)*dfsa(i+1,r))%mod,p%=mod;
	rop(i,l,r-1)
		rop(j,i+1,r)
			if(dfsa(l,i)&&dfss(i+1,j)&&dfsa(j+1,r)) p+=(((dfsa(l,i)*dfss(i+1,j))%mod)*dfsa(j+1,r))%mod,p%=mod;
	return p%mod;
}

void Main(){
	n=read(),k=read();
	scanf("%s",s+1);
	printf("%lld",dfsa(1ll,n)%mod);
}

}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	AnShu::Main();
	return 0;
}

