#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#define ri register int
#define int long long

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

int write(int x){
	if(x>9)write(x/10);
	putchar(x%10^48);
}

const int N=505,inf=1e9+7;
int dp[N][N],C[N][N],a[N][N],mi[N],n,m;
char ch[N];

int check(int l,int r){
	for(ri i=l;i<=r;i++){
		if(ch[i]=='('||ch[i]==')')return 0;
	}
	return 1;
}

signed main(void){
	freopen("brakcet.in","r",stdin);
	freopen("brakcet.out","w",stdout);
	n=read(),m=read(),mi[0]=1,C[0][0]=1;
	scanf("%s",ch+1);
	for(ri i=1;i<=n;i++){
		C[i][0]=1;
		for(ri j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j],C[i][j]%=inf;
	}
	for(ri i=1;i<=n;i++)mi[i]=mi[i-1]*2%inf;
	for(ri len=2;len<=n;len++){
		for(ri l=1,r=len;r<=n;l++,r++){
			if(check(l,r)&&r-l+1<=m)a[l][r]=1;
		}
	}
	for(ri len=2;len<=n;len++){
		for(ri l=1,r=len;r<=n;l++,r++){
			for(ri k=l;k<r;k++)dp[l][r]+=dp[l][k]*dp[k+1][r]%inf,dp[l][r]%=inf;//AB 
			for(ri k1=l+1;k1<r;k1++){
				for(ri k2=k1;k2<r;k2++){//ASB
					dp[l][r]+=dp[l][k1-1]*a[k1][k2]%inf*dp[k2+1][r]%inf,dp[l][r]%=inf;
				}
			}
			if((ch[l]=='('||ch[l]=='?')&&(ch[r]=='?'||ch[r]==')')){
				if(len==2)dp[l][r]+=1;
				dp[l][r]+=dp[l+1][r-1],dp[l][r]+=a[l+1][r-1],dp[l][r]%=inf;//(A)(S)()
				for(ri k=l+1;k<r;k++)dp[l][r]+=a[l+1][k]*dp[k+1][r-1]%inf,dp[l][r]%=inf;//(SA)
				for(ri k=l+1;k<r;k++)dp[l][r]+=dp[l+1][k]*a[k+1][r-1]%inf,dp[l][r]%=inf;//(AS)
			}
//			printf("%lld %lld %lld\n",l,r,dp[l][r]);
		}
	}
	printf("%lld\n",dp[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



