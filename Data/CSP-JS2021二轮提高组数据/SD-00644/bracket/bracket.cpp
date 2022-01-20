#include<bits/stdc++.h>
using namespace std;
const int maxn=510,mod=1e9+7;
long long f[maxn][maxn][2],dp[maxn][2];
int p[maxn][maxn];
char s[maxn];
int n,k;
inline int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*w;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[j]=='('||s[j]==')'||j-i>=k)break;
			p[i][j]=1;
		}
	}
	for(int i=1;i<n;i++)if((s[i]=='('||s[i]=='?')&&(s[i+1]==')'||s[i+1]=='?'))f[i][i+1][0]++;
	for(int l=3;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if((s[i]!='('&&s[i]!='?')||(s[j]!=')'&&s[j]!='?'))continue;
			if(p[i+1][j-1])f[i][j][0]++;
			f[i][j][0]+=f[i+1][j-1][0]+f[i+1][j-1][1];
			for(int k=i+1;k<j-1;k++)f[i][j][0]=(f[i][j][0]+p[i+1][k]*(f[k+1][j-1][0]+f[k+1][j-1][1]))%mod;
			for(int k=j-1;k>i+1;k--)f[i][j][0]=(f[i][j][0]+p[k][j-1]*(f[i+1][k-1][0]+f[i+1][k-1][1]))%mod;
			memset(dp,0,sizeof(dp));
			dp[i-1][0]=1;
			for(int u=i;u<=j;u++){
				for(int v=i;v<=u;v++){
					if(v==i&&u==j)continue;
					dp[u][0]=(dp[u][0]+f[v][u][0]*(dp[v-1][0]+dp[v-1][1]))%mod;
					if(v!=i&&u!=j&&p[v][u])dp[u][1]=(dp[u][1]+dp[v-1][0])%mod;
				}
			}
			f[i][j][1]=(dp[j][0]+dp[j][1])%mod;
		}
	}
	printf("%lld\n",(f[1][n][0]+f[1][n][1])%mod);
	fclose(stdin);fclose(stdout);
	return 0;
}

