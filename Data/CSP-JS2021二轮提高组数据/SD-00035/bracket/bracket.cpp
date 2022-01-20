#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll n,mod=1e9+7,lprs[501][501][501],ka,ans;
string s;
inline ll qpow(ll n1,ll n2){
	ll prs=n1,now=1;
	while(n2){
		if(n2&1){now*=prs;now%=mod;}
		n2>>=1;prs*=prs;prs%=mod;
	}
	return now;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld%s",&n,&ka,s.c_str());
	lprs[0][1][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i]=='('){
				lprs[i][j][0]+=lprs[i-1][j+1][0];
			}
			if(s[i]==')'){
				if(j>0)lprs[i][j][0]+=lprs[i-1][j-1][0];
			}
			if(s[i]=='*'){
				for(int k=1;k<=ka;k++)lprs[i][j][k]+=lprs[i-1][j][k-1];
			}
			for(int k=0;k<=ka;k++){
				if(s[i]=='?'){
					if(k>0)lprs[i][j][k]+=lprs[i-1][j][k-1];
					if(k=0){
						if(i>0){
							for(int k2=0;k2<=ka;k2++){
								if(j>0)lprs[i][j][k]+=lprs[i-1][j-1][k];
								lprs[i][j][k]+=lprs[i-1][j+1][k];
							}
						}
					}
				}	
			}
		}
	}
	for(int j=0;j<n;j++)for(int k=0;k<=ka;k++)ans+=lprs[n-2][j][k];
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

