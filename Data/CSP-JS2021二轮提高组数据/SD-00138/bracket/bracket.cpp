#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 501
int N,M,f[MAXN][MAXN][2][2],g[MAXN][MAXN],h[MAXN][MAXN],x[MAXN][MAXN];string s;
int main()
{
	freopen("bracket.in","r",stdin);freopen("bracket.out","w",stdout);
	cin>>N>>M>>s;s=" "+s;For(i,2,N)f[i][i-1][0][0]=h[i][i-1]=x[i][i-1]=1;For(i,1,N)For(j,i,min(i+M-1,N))g[i][j]=1;For(i,1,N)if(s[i]=='('||s[i]==')')For(j,1,i)For(k,i,N)g[j][k]=0;
	For(l,2,N)For(i,1,N-l+1)
	{
		int j=i+l-1;
		if(s[i]!='*'&&s[j]!='*'&&s[i]!=')'&&s[j]!='('){f[i][j][0][0]=(h[i+1][j-1]+g[i+1][j-1])%P;For(k,i+1,j-2)f[i][j][0][0]=(f[i][j][0][0]+1ll*h[i+1][k]*g[k+1][j-1]+1ll*g[i+1][k]*h[k+1][j-1])%P;}
		For(k,i,j-1)f[i][j][1][0]=(f[i][j][1][0]+1ll*x[i][k]*h[k+1][j])%P;
		For(k,i,j-2)For(l,k+1,j-1){if(!g[k+1][l])break;f[i][j][0][1]=(f[i][j][0][1]+1ll*f[i][k][0][0]*g[k+1][l]*x[l+1][j])%P;}
		h[i][j]=(0ll+f[i][j][0][0]+f[i][j][0][1]+f[i][j][1][0]+f[i][j][1][1])%P;
		x[i][j]=(f[i][j][0][0]+f[i][j][0][1])%P;
	}
	cout<<h[1][N]<<'\n';return 0;
}
