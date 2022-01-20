#include<cstdio>
#include<iostream>
typedef long long ll;
const int N=500+13,mod=1e9+7;
char s[N];
int n,m,f[N][N],g[N][N],pre[N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int l=n-1;l;--l){
		for(int r=l+1;r<=n;++r){
			if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?')){
				if(l+1==r) g[l][r]++,g[l][r]%=mod;//()
				else{
					g[l][r]+=(f[l+1][r-1]+g[l+1][r-1])%mod,g[l][r]%=mod;//(A)
					int p=0;
					while(p<m&&l+1+p<r-1&&(s[l+1+p]=='*'||s[l+1+p]=='?')) g[l][r]+=(f[l+1+p+1][r-1]+g[l+1+p+1][r-1])%mod,g[l][r]%=mod,++p;//(AS)
					p=0;
					while(p<m&&r-1-p>l+1&&(s[r-1-p]=='*'||s[r-1-p]=='?')) g[l][r]+=(f[l+1][r-1-p-1]+g[l+1][r-1-p-1])%mod,g[l][r]%=mod,++p;//(SA)
					if(p<m&&r-1-p==l+1&&(s[l+1]=='*'||s[l+1]=='?')) g[l][r]++,g[l][r]%=mod;//(S)	
				}
			}
			pre[l]=0;
			for(int k=l+1;k<=r;++k) pre[k]=(pre[k-1]+(f[k][r]+g[k][r])%mod)%mod;
			for(int k=l,nw=l;k<r;++k){
				if(nw<k) nw=k;
				while(nw+1<r&&nw+1-k<=m&&(s[nw+1]=='*'||s[nw+1]=='?')) ++nw;
				f[l][r]+=(ll)g[l][k]*(pre[nw+1]-pre[k]+mod)%mod,f[l][r]%=mod;
			}
		}
	}
	printf("%d\n",(f[1][n]+g[1][n])%mod);
	return 0;
}
