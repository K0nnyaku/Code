#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
const int mod=1000000007;
int qmod1(const int &x){return x>=mod?x-mod:x;}
int qmod2(const int &x){return x+(x>>31&mod);}
int n,K;
char st[N];
int f[N][N],g[N][N],L[N],R[N],sg[N][N];
int check(const int &pos,const char &c)
{
	return st[pos]==c||st[pos]=='?';
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("bracket3.in","r",stdin);
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&K);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)
	{
		int j=i;while(j<=n&&check(j,'*'))++j;
		R[i]=j-i;
		j=i;while(j>=1&&check(j,'*'))--j;
		L[i]=i-j;
	}
	for(int i=1;i<n;i++)if(check(i,'(')&&check(i+1,')'))f[i][i+1]=g[i][i+1]=1;
	for(int i=1;i<=n+1;i++)g[i][i-1]=1;
	for(int i=1;i<=n+1;i++)sg[i][i-1]=1;
	for(int i=1;i<=n;i++)sg[i][i]=1;
	for(int i=1;i<n;i++)sg[i][i+1]=sg[i+1][i+1]+g[i][i+1];
	for(int len=2;len<=n-1;len++)
		for(int l=1;l+len<=n;l++)
		{
			int r=l+len;
			if(check(l,'(')&&check(r,')'))
			{
				f[l][r]=g[l+1][r-1];
				for(int k=l+1;k<=l+K&&k<r-1&&check(k,'*');k++)
					f[l][r]=qmod1(f[l][r]+g[k+1][r-1]);
				for(int k=r-1;k>=r-K&&k>l+1&&check(k,'*');k--)
					f[l][r]=qmod1(f[l][r]+g[l+1][k-1]);
				if(R[l+1]>=r-l-1&&r-l-1<=K)f[l][r]=qmod1(f[l][r]+1);
				for(int k=l+1;k<=r;k++)
					if(check(k,')'))
					{
						g[l][r]=(g[l][r]+1ll*f[l][k]*g[k+1][r])%mod;
						if(k!=r)
						{
							int t0=min(k+K,min(r-1,k+R[k+1]));
							g[l][r]=(g[l][r]+1ll*f[l][k]*qmod2(sg[k+2][r]-sg[t0+2][r]))%mod;
//							for(int t=k+1;t<=k+K&&t<r&&check(t,'*');t++)
//							for(int t=k+1;t<=t0;t++)
//								g[l][r]=(g[l][r]+1ll*f[l][k]*g[t+1][r])%mod;
						}
							
					}
			}
			sg[l][r]=qmod1(sg[l+1][r]+g[l][r]);
		}
//	cout<<f[1][4]<<endl;
//	cout<<g[2][3]<<endl;
	printf("%d\n",g[1][n]);
} 
