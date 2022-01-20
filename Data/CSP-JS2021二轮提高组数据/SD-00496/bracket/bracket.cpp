#include<iostream>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<ctime>
#include<bitset>
#include<complex>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
namespace fastIO{
	inline int read(){
		int x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		return fu?-x:x;
	}
	template<class T>
	inline void read(T &x){
		x=0;
		bool fu=false;
		char ch=0;
		while((ch=getchar())>'9'||ch<'0'){
			if(ch=='-')fu=true;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(fu)x=-x;
	}
	char num_[50];
	int cnt_;
	template<class T>
	inline void write(T x){
		if(x==0){
			putchar('0');
			return;
		}
		if(x<0)putchar('-'),x=-x;
		while(x){
			num_[++cnt_]=x%10+'0';
			x/=10;
		}
		while(cnt_)putchar(num_[cnt_--]);
	}
	template<class T>
	inline void write(T x,char c){
		write(x);
		putchar(c);
	}
}
using namespace fastIO;
#define mod 1000000007
int f[502][502],g[502][502],n,K,preg[502][502];
char s[505];
#define L(i) (s[i]=='('||s[i]=='?')
#define R(i) (s[i]==')'||s[i]=='?')
#define cs(i) (s[i]=='*'||s[i]=='?')
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>K;
	scanf("%s",s+1);
	/*
	F(i,1,n){
		memcpy(lst,dp,sizeof(dp));
		memset(dp,0,sizeof(dp));
		if(s[i]=='('){
			F(j,0,min(i,n-i)-1){
				F(k,0,K){
					dp[j+1][0]=(dp[j+1][0]+lst[j][k])%mod;
				}
			}
		}else if(s[i]==')'){
			F(j,1,min(i-1,n-i+1)){
				F(k,0,K)dp[j-1][0]=(dp[j-1][0]+lst[j][k])%mod;
			}
		}else if(s[i]=='*'){
			if(i!=1)F(j,0,min(i,n-i)){
				F(k,0,K-1)dp[j][k+1]=(dp[j][k+1]+lst[j][k])%mod;
			}
		}else{
			F(j,0,min(i,n-i)-1){
				F(k,0,K){
					dp[j+1][0]=(dp[j+1][0]+lst[j][k])%mod;
				}
			}
			F(j,1,min(i-1,n-i+1)){
				F(k,0,K)dp[j-1][0]=(dp[j-1][0]+lst[j][k])%mod;
			}
			if(i!=1)F(j,0,min(i,n-i)){
				F(k,0,K-1)dp[j][k+1]=(dp[j][k+1]+lst[j][k])%mod;
			}
		}
	}
	*/
	UF(i,n,1){
		if(i<n&&L(i)&&R(i+1))f[i][i+1]=g[i][i+1]=preg[i][i+1]=1;
		bool flag=true;
		F(j,i+2,n){
			flag&=cs(j-1);
			if(j-i-1<=K&&flag&&L(i)&&R(j)){
				f[i][j]=(f[i][j]+1)%mod;
				g[i][j]=(g[i][j]+1)%mod;
			}
			int lst=i;
			F(k,i+1,j-2){
				if(!cs(k))lst=k-1;
				if(lst<k-K-1)lst=k-K-1;//if(i==1&&j==7)cerr<<k<<" "<<lst<<endl;
				f[i][j]=(f[i][j]+1ll*(preg[i][k]-preg[i][lst]+mod)*f[k+1][j])%mod;
			}
			if(L(i)&&R(j)){
				g[i][j]=(g[i][j]+f[i+1][j-1])%mod;
				f[i][j]=(f[i][j]+f[i+1][j-1])%mod;
				F(k,i+1,min(j-2,i+K)){
					if(!cs(k))break;
					g[i][j]=(g[i][j]+f[k+1][j-1])%mod;
					f[i][j]=(f[i][j]+f[k+1][j-1])%mod;
				}
				UF(k,j-1,max(i+2,j-K)){
					if(!cs(k))break;
					g[i][j]=(g[i][j]+f[i+1][k-1])%mod;
					f[i][j]=(f[i][j]+f[i+1][k-1])%mod;
				}
			}
			preg[i][j]=(preg[i][j-1]+g[i][j])%mod;
		}
	}
	write(f[1][n]);
/*	
	F(i,1,n){
		cerr<<endl;
		F(j,i,n)cerr<<f[i][j]<<' ';
	}
*/	
	return 0;
}

