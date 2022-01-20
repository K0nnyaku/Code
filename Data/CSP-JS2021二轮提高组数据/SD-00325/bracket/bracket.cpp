#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=1e9+7;
int n,k,f[N][N][5],g[N];//A AS SA S AAAAAAA...
int qian[N],hou[N];
char a[N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='*'||a[i]=='?')qian[i]=qian[i-1]+1;
	}
	for(int i=n;i>=1;i--){
		if(a[i]=='*'||a[i]=='?')hou[i]=hou[i+1]+1;
	}
	for(int i=1;i<=n;i++){
		for(int o=1;(o+i-1)<=n;o++){
			int l=o,r=o+i-1;
			if(hou[l]>=i&&i<=k){
				f[l][r][3]+=1;
			}
			if(i==2&&(a[l]=='?'||a[l]=='(')&&(a[r]==')'||a[r]=='?')){
				f[l][r][0]+=1;
			}
			if((a[l]=='?'||a[l]=='(')&&(a[r]==')'||a[r]=='?')){
				f[l][r][0]=(f[l][r][0]+1ll*f[l+1][r-1][1]+f[l+1][r-1][2]+f[l+1][r-1][3]+f[l+1][r-1][4])%mod;
//				for(int v=l+1;v+1<=r-1;v++){
//					f[l][r][0]=(f[l][r][0]+f[l+1][v][4]*f[v+1][r-1][3])%mod;
//					f[l][r][0]=(f[l][r][0]+f[l+1][v][3]*f[v+1][r-1][4])%mod;
//				}
			}
			for(int v=l;v+1<=r;v++){
				f[l][r][0]=(f[l][r][0]+1ll*f[l][v][0]*f[v+1][r][2])%mod;
				f[l][r][1]=(f[l][r][1]+1ll*f[l][v][0]*f[v+1][r][3])%mod;
				f[l][r][2]=(f[l][r][2]+1ll*f[l][v][3]*f[v+1][r][0])%mod;
				f[l][r][4]=(f[l][r][4]+1ll*f[l][v][0]*f[v+1][r][4])%mod;
			}
			f[l][r][4]=(f[l][r][4]+f[l][r][0])%mod;
//			cout<<l<<" "<<r<<" "<<f[l][r][4]<<endl;
		}
	}
	if(a[1]!='('&&a[1]!='?'&&a[n]!=')'&&a[n]!='?'){
		printf("0\n");
		return 0;
	}
	int l=2,r=n-1;
	int ans=0;
	for(int v=2;v+1<=r;v++){
					ans=(ans+f[l][v][4]*f[v+1][r][3])%mod;
					ans=(ans+f[l][v][3]*f[v+1][r][4])%mod;
				}
				for(int i=1;i<=n;i++){
					g[i]=f[1][i][0];
					for(int v=i-1;v>=1;v--){
						g[i]=(g[i]+1ll*g[v]*f[v+1][i][0])%mod;
					}
				}
	printf("%d\n",g[n]%mod);
}
/*
7 3
(*??*??


10 2
???(*??(?)

*/
