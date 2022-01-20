#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
#define For(Ti,Ta,Tb) for(int Ti=(Ta);Ti<=(Tb);++Ti)
#define Dec(Ti,Ta,Tb) for(int Ti=(Ta);Ti>=(Tb);--Ti)
typedef long long ll;
const int N=505,Mod=1e9+7;
int n,k;
char s[N];
bool Is(int p,char c){
	return s[p]=='?'||s[p]==c;
}
bool AllIs(int l,int r,char c){
	For(i,l,r){
		if(!Is(i,c)) return 0;
	}
	return 1;
}
ll f[N][N],g[N][N],sum[N][N];
int lf[N];
ll Sum(int i,int l,int r){
//	ll res=0;
//	For(j,l,r) res=(res+g[i][j])%Mod;
//	return res;
	return (sum[i][r]-sum[i][l-1]+Mod)%Mod;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	For(i,1,n) lf[i]=Is(i,'*')?lf[i-1]:i;
	for(int i=1,j=2;j<=n;++i,++j){
		if(Is(i,'(')&&Is(j,')')) sum[i][j]=g[i][j]=f[i][j]=1;
	}
	For(len,3,n){
		for(int i=1,j=i+len-1;j<=n;++i,++j){
			if(!Is(i,'(')||!Is(j,')')){
				sum[i][j]=sum[i][j-1];continue;
			}
			if(j-i-1<=k&&AllIs(i+1,j-1,'*')){
				g[i][j]=1;
			}
			g[i][j]=(g[i][j]+f[i+1][j-1])%Mod;
			for(int p=i+1;p<j-1&&p-i<=k;++p){
				if(!Is(p,'*')) break;
				g[i][j]=(g[i][j]+f[p+1][j-1])%Mod;
			}
			for(int p=j-1;p>i+1&&j-p<=k;--p){
				if(!Is(p,'*')) break;
				g[i][j]=(g[i][j]+f[i+1][p-1])%Mod;
			}
			f[i][j]=g[i][j];
			sum[i][j]=(sum[i][j-1]+g[i][j])%Mod;
			For(p,i,j){
				f[i][j]=(f[i][j]+g[i][p]*f[p+1][j])%Mod;
				int l=max({i,p-k+1,lf[p]+1});
				if(l-1>p-1) continue;
				f[i][j]=(f[i][j]+(Sum(i,l-1,p-1)+Mod)*f[p+1][j]%Mod)%Mod;
			}
//			printf("%d %d: %lld %lld\n",i,j,g[i][j],f[i][j]);
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}
