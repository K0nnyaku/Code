#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=305;
int N,K,P[MX];
double C[MX][MX];
char B[MX];

double dp[MX];
int Work()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",&P[i]);
	dp[0]=1;
	Fr(i,1,N)if(!B[i])
	{
		int a=0;
		for(int j=i;!B[j];j=P[j])B[j]=1,++a;
		Fl(j,K,0)
		{
			for(int k=min(a,K-j);k>=1;--k)
				dp[j+k]+=dp[j]*C[a][k];
			dp[j]=0;
		}
	}
	printf("%.10f\n",dp[K]/C[N][K]);
	return 0;
}

int main()
{
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
	
	Fr(i,0,300)C[i][0]=1;
	Fr(i,1,300)Fr(j,1,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
	
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		Work();
		memset(dp,0,sizeof(dp));
		memset(B,0,sizeof(B));
		memset(P,0,sizeof(P));
	}
}
