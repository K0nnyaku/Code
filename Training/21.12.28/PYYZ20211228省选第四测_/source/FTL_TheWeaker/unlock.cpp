#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
#define db double
#define LD long double
using namespace std;
const int N=305;
int read(){
	int ans=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	if(f)ans=-ans;
	return ans;
}
int T,cnt,n,K,u,v,f[N],siz[N],num[N],pre[N];
LD dp[N][N],C[N][N];
void init(){
	cnt=0;
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=K;j++)
			dp[i][j]=0;
	dp[0][0]=1;
}
int gtf(int x){
	if(f[x]==x)return x;
	return f[x]=gtf(f[x]);
}
int main(){
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
	T=read();
	for(int i=0;i<=64;i++)C[i][0]=C[i][i]=1;
	for(int i=1;i<=64;i++)
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	while(T--){
		n=read(),K=read();
		init();
		for(int i=1;i<=n;i++){
			v=read();
			u=gtf(i),v=gtf(v);
			if(u==v)continue;
			if(siz[u]<siz[v])f[u]=v,siz[v]+=siz[u];
			else f[v]=i,siz[u]+=siz[v];			
		}
		for(int i=1;i<=n;i++){
			if(f[i]!=i)continue;
			num[++cnt]=siz[i];
			pre[cnt]=pre[cnt-1]+num[cnt];
		}
		for(int i=1;i<=cnt;i++)
			for(int j=min(K,pre[i-1]);j>=0;j--)
				for(int k=min(K-j,num[i]);k;k--){
					dp[i][j+k]+=dp[i-1][j]*C[num[i]][k]/C[n-pre[i-1]][K-j]*C[n-pre[i]][K-j-k];
				}
		printf("%.6Lf\n",dp[cnt][K]);		
	}
	return 0;
}
/*
4
5 1
2 5 4 3 1
5 2
2 5 4 3 1
5 3
2 5 4 3 1
5 4
2 5 4 3 1


1
5 2
2 5 4 3 1

*/
