#include<cmath>
#include<cctype>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define I inline
#define fi first
#define se second

using std::pair;
using std::vector;
using std::set;
using std::map;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;

template<class T>I void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); } x*=f;
}

void File() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}

const int N=505;
const int mod=1e9+7;

int n,k;
char s[N];
int f[N][N],g[N][N],h[N][N];

void Calc_h() {
	for(int i=1;i<=n;i++) 
		for(int j=i;j<=n;j++) {
			if(j-i+1>k) continue;
			h[i][j]=1;
			for(int k=i;k<=j;k++) if(s[k]=='('||s[k]==')') {
				h[i][j]=0;
				break;
			}
		}
}

int main() {
	File();
	read(n),read(k);
	scanf("%s",s+1);
	
//	printf("%s\n",s+1);
	
	Calc_h();
	
	for(int len=2;len<=n;len++) {
		for(int l=1;l+len-1<=n;l++) {
			int r=l+len-1;
			
			if(s[l]=='('&&s[r]==')' || s[l]=='?'&&s[r]==')' 
				|| s[l]=='('&&s[r]=='?' || s[l]=='?'&&s[r]=='?') {
				if(l+1==r) f[l][r]=1; 
				else f[l][r]=(h[l+1][r-1]+f[l+1][r-1])%mod;
				for(int i=l+1;i<r-1;i++) {
					f[l][r]=((f[l+1][i]*h[i+1][r-1]+h[l+1][i]*f[i+1][r-1])%mod
									+f[l][r])%mod;
				} 
			}
			for(int i=l;i<r;i++) {
				f[l][r]=(f[l][r]+1ll*f[l][i]*f[i+1][r]%mod)%mod;
				f[l][r]=(f[l][r]+1ll*f[l][i]*g[i+1][r]%mod)%mod;
				
				g[l][r]=(g[l][r]+h[l][i]*f[i+1][r]%mod)%mod;
			}
		}
	}
//	for(int len=1;len<=n;len++)
//		for(int l=1;l+len-1<=n;l++) 
//			printf("%d %d : %d\n",l,l+len-1,f[l][l+len-1]);
//	
	printf("%d\n",f[1][n]);
	return 0;
}

