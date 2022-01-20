#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
	char ch=' ';
	int v=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){v=(v<<1)+(v<<3)+(ch^48);ch=getchar();}
	return v*x;
}
const int N=510,mod=1e9+7;
char s[N];
int n,k,a[N],b[N],dp[N][N]; 
bool ispair(int l,int r){
	if(s[l]=='('&&s[r]==')') return true;
	if(s[l]=='('&&s[r]=='?') return true;
	if(s[l]=='?'&&s[r]==')') return true;
	if(s[l]=='?'&&s[r]=='?') return true;
	return false;
}
bool isstar(int l,int r){
	if(r-l+1>k) return false;
	if(a[r]-a[l-1]+b[r]-b[l-1]!=r-l+1) return false;
	return true;
}
int add(int l,int r,int y){
	dp[l][r]+=y;
	if(dp[l][r]>=mod) dp[l][r]-=mod;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i]=='?');
		b[i]=b[i-1]+(s[i]=='*');
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(len==2){//()?*
				if(ispair(l,r)) dp[l][r]=1;
			}//mod
			else{
				if(ispair(l,r)){
					add(l,r,dp[l+1][r-1]);
					if(isstar(l+1,r-1)) add(l,r,1);
					for(int i=l+1;i<r-1;i++){
						if(isstar(l+1,i)) add(l,r,dp[i+1][r-1]);
						if(isstar(i+1,r-1)) add(l,r,dp[l+1][i]);
					}
				}
				for(int i=l;i<r;i++){
					add(l,r,1ll*dp[l][i]*dp[i+1][r]%mod);
					//if(l==1&&r==n&&dp[l][i]&&dp[i+1][r]) printf("(%d %d %d %d)\n",i,i+1,dp[l][i],dp[i+1][r]);
				}
				for(int i=l;i<r-1;i++)
					for(int j=i+1;j<r;j++)
						if(isstar(i+1,j)){
							add(l,r,1ll*dp[l][i]*dp[j+1][r]%mod);
							//if(l==1&&r==n&&dp[l][i]&&dp[j+1][r]) printf("[%d %d %d %d]\n",i,j+1,dp[l][i],dp[j+1][r]);
						}
			}
		}
	printf("%d",dp[1][n]);
	//for(int i=1;i<=n;i++)
	//	for(int j=i;j<=n;j++)
	//		printf("%d %d %d\n",i,j,dp[i][j]);
	return 0;
}


