#include<cstdio>
#include<iostream>
#define N 517
#define mod 1000000007
using namespace std;

int n,K,F[N][N],G[N][N];char s[N];

void upd(int &a,int b) {
	a += b;a %= mod;
}

bool k_check(int l,int r) {
	for(int i = l;i <= r;i += 1)
		if(s[i] == '(' || s[i] == ')')return 0;
	return 1;
}

bool p_check(int x,int y) {
	if(x == y)return 0;
	if(s[x] != '(' && s[x] != '?')return 0;
	if(s[y] != ')' && s[y] != '?')return 0;
	return 1;
}

int main()
{
	freopen("bracket.in","r",stdin);freopen("bracket.out","w",stdout); 
	scanf("%d%d",&n,&K);scanf("%s",s+1);
	for(int len = 1,l,r;len <= n;len += 1){
		for(l = 1;l <= n-len+1;l += 1){
			r = l + len - 1;
			if(k_check(l+1,r-1) && p_check(l,r) && len-2 <= K && len >= 2){
				upd(G[l][r],1);upd(F[l][r],1);
			}
			for(int k = l;k < r;k += 1)//2 AB
				upd(F[l][r],1ll*F[l][k]*F[k+1][r]%mod);
			for(int k = l;k < r;k += 1)
				upd(G[l][r],1ll*G[l][k]*G[k+1][r]%mod);
			if(p_check(l,r) && len > 2){//3
				upd(F[l][r],F[l+1][r-1]%mod);upd(G[l][r],F[l+1][r-1]%mod);
				for(int k = 1;k <= K && l+k+1 <= r-1;k += 1){
					if(!k_check(l+1,l+k))break;
					upd(F[l][r],F[l+k+1][r-1]);
				}
				for(int k = 1;k <= K && l+1 <= r-k-1;k += 1){
					if(!k_check(r-k,r-1))break;
					upd(F[l][r],F[l+1][r-k-1]);
				}
			}
			for(int i = l+1;i <= r-1;i += 1){//2 ASB
				for(int j = i;j <= r-1;j += 1){
					if(j-i+1 > K)break;
					if(k_check(i,j)){
						upd(F[l][r],1ll*G[l][i-1]*G[j+1][r]%mod);
					}
				}
			}
		}
	}
	printf("%d\n",F[1][n]);
	return 0;
}

