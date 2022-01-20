#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=550,Mod=1000000007;
int N,K;
char S[MX];

inline bool C(int i,char c){return S[i]=='?'||S[i]==c;}
ll U[MX];
ll dp[MX][MX],ep[MX][MX];


int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
//	freopen("bracket2.in","r",stdin);
//	freopen("bracket2.out","w",stdout);
	
	scanf("%d%d%s",&N,&K,S+1);
	
	Fl(l,N,1)Fr(r,l+1,N)
	{
		if(C(l,'(')&&C(r,')'))
		{
			if(r-l-1<=K)
			{
				int b=1;
				Fr(i,l+1,r-1)if(!C(i,'*')){b=0;break;}
				dp[l][r]+=b;
			}
			dp[l][r]+=ep[l+1][r-1];
			int m=min(r-l-2,K);
			Fr(i,1,m)
			{
				if(!C(l+i,'*'))break;
				dp[l][r]+=ep[l+i+1][r-1];
			}
			Fr(i,1,m)
			{
				if(!C(r-i,'*'))break;
				dp[l][r]+=ep[l+1][r-i-1];
			}
		}
		
		ep[l][r]=dp[l][r];
		
		U[l-1]=0;
		Fr(i,l,r-1)U[i]=(U[i-1]+ep[l][i])%Mod;
		int p=l;
		Fr(q,l,r-1)
		{
			if(!C(q,'*'))p=q;
			p=max(p,q-K);
			ep[l][r]+=(U[q]-U[p-1]+Mod)*dp[q+1][r]%Mod;
		}
		
		dp[l][r]%=Mod;
		ep[l][r]%=Mod;
		
//		printf("[%d,%d]: %lld %lld\n",l,r,dp[l][r],ep[l][r]);
	}
	printf("%lld\n",ep[1][N]);
	return 0;
}
