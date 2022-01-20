#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=550,mod=1e9+7;
int n,l,dp[N][N][N];
char c[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&l);
	scanf("%s",c);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=min(i,l);k++){
				if(c[i-1]=='('||c[i-1]=='?'){
					dp[i][j+1][0]+=dp[i-1][j][k];
					if(dp[i][j+1][0]>=mod)dp[i][j+1][0]-=mod;
				}
				if(c[i-1]==')'||c[i-1]=='?'){
					dp[i][j][0]+=dp[i-1][j+1][k];
					if(dp[i][j][0]>=mod)dp[i][j][0]-=mod;
				}
				if(c[i-1]=='*'||c[i-1]=='?'){
					dp[i][j][k+1]+=dp[i-1][j][k];
					if(dp[i][j][k+1]>=mod)dp[i][j][k+1]-=mod;
				}
			}
		}
	}
	cout<<dp[n][0][0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
