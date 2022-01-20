#include <cstdio>
#include <cstring>
using namespace std;
const int mod=1000000007;
int n,k;
char ch[502];
int dp[502][502][5];
bool canbe(int x,char c){
	return ch[x]=='?'||ch[x]==c;
}
int go(int i,int j,int d){
	if(dp[i][j][d]!=-1)return dp[i][j][d];
	if(i>j)return dp[i][j][d]=0;
	if(d==0){
		if(j-i+1>k)return dp[i][j][d]=0;
		for(int l=i;l<=j;++l){
			if(!canbe(l,'*')){
				return dp[i][j][d]=0;
			}
		}
		return dp[i][j][d]=1;
	}
	if(i==j){
		return dp[i][j][d]=0;
	}
	int res=0;
	if(canbe(i,'(')&&canbe(j,')')){
		if(j-i+1==2)res+=1;
		res=(res+go(i+1,j-1,0));
		res=(res+go(i+1,j-1,3));
	}
	for(int l=i+1;l<j-1;++l){
		if(d==4||d==2)res=(res+go(i+1,l,0)*go(l+1,j-1,2))%mod;
		else res=(res+go(i+1,l,0)*go(l+1,j-1,1))%mod;
		if(d==1||d==2)res=(res+go(i+1,l,2)*go(l+1,j-1,0))%mod;
		else res=(res+go(i+1,l,4)*go(l+1,j-1,0))%mod;
	}
	for(int l=i;l<j;++l){
		if(d==2)res=(int)(res+1ll*(go(i,l,1)*go(l+1,j,2))%mod)%mod;
		else if(d==1)res=(int)(res+1ll*(go(i,l,1)*go(l+1,j,1))%mod)%mod;
		else if(d==4)res=(int)(res+1ll*(go(i,l,3)*go(l+1,j,2))%mod)%mod;
		else res=(int)(res+1ll*(go(i,l,3)*go(l+1,j,1))%mod)%mod;
	}
	return dp[i][j][d]=res;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,ch+1);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(1,n,2));
	/*
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int *s=dp[i][j];
			printf("%d %d:%d %d %d %d %d\n",i,j,s[0],s[1],s[2],s[3],s[4]);
		}
	}
	//*/
	return 0;
}

