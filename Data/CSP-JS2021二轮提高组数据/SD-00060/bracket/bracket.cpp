#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define mkp make_pair
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define pq priority_queue
#define space putchar(' ')
#define enter putchar('\n')
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ms(x,y) memset(x,y,sizeof(x))
#define debug(x) cerr<<#x<<"= "<<(x)<<endl
template<class T> inline T read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*=f;
}
template<class T> inline void print(T x){
	char buf[20];int cnt=0;
	if(x<0) putchar('-'),x=-x;
	if(!x) putchar('0');
	while(x) buf[++cnt]=x%10^48,x/=10;
	while(cnt) putchar(buf[cnt--]);
}
#define mod 1000000007
#define inf 1000000001
#define fpi freopen("bracket.in","r",stdin)
#define fpo freopen("bracket.out","w",stdout)
char s[505];
ll dp[505][505][5];
inline ll qmod(ll x){
	if(x<0) return x+mod;
	if(x>=mod) return x-mod;
	return x;
}
inline bool check(int x,char ch){
	return s[x]==ch||s[x]=='?';
}
int main(){
	fpi,fpo;
	int n=read(n),k=read(k),i,j,l,r;
	scanf("%s",s+1);
	for(i=1;i<=n;i++){
		dp[i][i-1][0]=1;
		for(j=1;j<=k&&j+i-1<=n;j++){
			if(!check(j+i-1,'*')) break;
			dp[i][j+i-1][3]=1;
		}
	}
	for(l=n-1;l;l--){
		for(r=l+1;r<=n;r++){
			if(check(l,'(')&&check(r,')')){
				dp[l][r][0]=qmod(qmod(qmod(dp[l+1][r-1][0]+dp[l+1][r-1][1])+qmod(dp[l+1][r-1][2]+dp[l+1][r-1][3]))+dp[l+1][r-1][4]);
			}
			ll sum;
			for(i=r+1;i<=n;i++){
				sum=qmod(qmod(dp[l][r][0]+dp[l][r][1])+dp[l][r][2]);
				dp[l][i][2]=qmod(dp[l][i][2]+sum*dp[r+1][i][0]%mod);
			}
			for(i=l;i<r;i++){
				sum=qmod(dp[i+1][r][0]+dp[i+1][r][2]);
				dp[l][r][4]=qmod(dp[l][r][4]+dp[l][i][3]*sum%mod);
			}
			sum=qmod(dp[l][r][0]+dp[l][r][2]);
			for(i=r+1;i<=n&&i<=r+k;i++){
				if(!check(i,'*')) break;
				dp[l][i][1]=qmod(dp[l][i][1]+sum);
			}
		}
	}
	print(qmod(dp[1][n][0]+dp[1][n][2]));
	return 0;
}
