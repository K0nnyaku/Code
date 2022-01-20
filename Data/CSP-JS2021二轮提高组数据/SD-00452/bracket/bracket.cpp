#include<bits/stdc++.h>
namespace MAIN{

using namespace std;
typedef long long LL;
#define pii pair<int,int>
#define fs first
#define sc second
const int N=1.1e3,mod=1e9+7;
char s[N];
bool g[N][N];
LL f1[N][N],f2[N][N],h1[N][N],h2[N][N];
inline bool can(int i,char c){
	if(s[i]=='?')return 1;
	if(s[i]==c)return 1;
	return 0;
}
int main(){
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)g[i][i]=can(i,'*');
	for(int l=2;l<=n;l++){
		for(int i=1,j;(j=i+l-1)<=n;i++){
			g[i][j]=(((j-i+1)<=m)&&g[i][j-1]&&can(j,'*'));
			if(can(i,'(')&&can(j,')')){
				f1[i][j]=(i+1==j)+g[i+1][j-1]+h1[i+1][j-1]+h2[i+1][j-1]
					+f1[i+1][j-1]+f2[i+1][j-1];
				f1[i][j]%=mod;
			}
			for(int k=i;k<j;k++){
				f2[i][j]+=f1[i][k]*(f1[k+1][j]+f2[k+1][j]+h2[k+1][j])%mod;
				if(f2[i][j]>=mod)f2[i][j]-=mod;
				h1[i][j]+=(f1[i][k]+f2[i][k])*g[k+1][j];
				h2[i][j]+=g[i][k]*(f1[k+1][j]+f2[k+1][j]); 
			}
			h1[i][j]%=mod,h2[i][j]%=mod;
		}
	}
	printf("%lld\n",(LL)f1[1][n]+(LL)f2[1][n]); 
	//cerr<<f[3][6]<<endl;
	/*
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<"["<<i<<","<<j<<"]\n";
			cout<<"f:"<<f1[i][j]<<endl;
			cout<<"g:"<<g[i][j]<<endl;
			cout<<"h1:"<<h1[i][j]<<endl;
			cout<<"h2:"<<h2[i][j]<<endl;
		}
	}
	cerr<<f1[1][n]+f2[1][n]<<endl;*/
	return 0;
}

}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	MAIN::main();
	return 0;
}

