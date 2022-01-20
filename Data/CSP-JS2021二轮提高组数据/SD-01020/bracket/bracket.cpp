#include <cstdio>
using namespace std;
typedef long long ll;
inline void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
inline int rd(){
	register int x=0;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x; 
}
const ll mod=1000000007;
int n,mlen;
ll dp[510][510][3];
bool ss[510][510];
char s[510];
inline bool chk(const int &p,const char &tp){
	return s[p]==tp || s[p]=='?';
}
int main(){
	file();
	n=rd(),mlen=rd();
	if(n==1)return puts("0"),0;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)ss[i][i]=chk(i,'*');
	for(int len=2;len<=n && len<=mlen;++len)
		for(int i=1,j=len;j<=n;++i,++j)
			ss[i][j]=(ss[i+1][j] && chk(i,'*'));
	for(int i=1;i<n;++i)
		dp[i][i+1][0]=dp[i][i+1][2]=(chk(i,'(') && chk(i+1,')'));
	for(int len=3;len<=n;++len)
		for(int i=1,j=len;j<=n;++i,++j){
			if(chk(i,'(') && chk(j,')')){
				dp[i][j][2]=ss[i+1][j-1]+dp[i+1][j-1][1]+dp[i+1][j-1][0];
				for(int k=i+1;k<j-1;++k)
					dp[i][j][2]=(dp[i][j][2]+ss[i+1][k]*dp[k+1][j-1][0])%mod;
			}
			dp[i][j][0]=dp[i][j][2];
			for(int k=i;k<j;++k)
				dp[i][j][0]=(dp[i][j][0]+(dp[i][k][0]+dp[i][k][1])*dp[k+1][j][2])%mod;
			for(int k=i;k<j;++k)
				dp[i][j][1]=(dp[i][j][1]+dp[i][k][0]*ss[k+1][j])%mod;
		}
	printf("%lld\n",dp[1][n][0]);
	return 0;
}
