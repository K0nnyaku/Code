#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=1e9+7;
int n,kkk;
char ch[N];
bool xing[N][N];
int yan[N],sum[N][N],f[N][N];
bool panduan(int x,int y)
{
	if(ch[x]!='('&&ch[x]!='?') return 0;
	if(ch[y]!=')'&&ch[y]!='?') return 0;
	return 1;
}
signed main()
{
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	cin>>n>>kkk;scanf("%s",ch+1);
	for(int i=1;i<=n;i++)
	{
		if(ch[i]!='*'&&ch[i]!='?') continue;
		for(int j=i;j<=i+kkk-1;j++)
		{
			if(ch[j]!='*'&&ch[j]!='?') {yan[i]=j-1;break;}
			if(j==i+kkk-1) yan[i]=j;
			xing[i][j]=1;
		}
	}
	for(int i=1;i<n;i++)
		if(panduan(i,i+1)) f[i][i+1]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
		{
			if(j-1-i>kkk) break;
			if(panduan(i,j)&&xing[i+1][j-1]) f[i][j]+=1;
		}
			
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l<=n;l++)
		{
			int r=l+len-1;
			if(r>n) break;
			if(panduan(l,r))
			{
				f[l][r]+=f[l+1][r-1];f[l][r]%=mod;
				for(int k=l+1;k<r-1;k++)
				{
					if(k-l>kkk) break;
					if(xing[l+1][k]) f[l][r]=(f[l][r]+f[k+1][r-1])%mod;
				}
				for(int k=r-1;k>l+1;k--)
				{
					if(r-k>kkk) break;
					if(xing[k][r-1]) f[l][r]=(f[l][r]+f[l+1][k-1])%mod;
				}
			}
			for(int k=l+1;k<r-1;k++)
			{
				f[l][r]+=f[l][k]%mod;
				f[l][r]%=mod;
			}
			for(int k=l;k<r-1;k++)
			{
				if(!yan[k+1]) continue;
				f[l][r]+=f[l][k]*sum[k+2][r]%mod;f[l][r]%=mod; 
				if(yan[k+1]+2<=r) f[l][r]-=f[l][k]*sum[yan[k+1]+2][r]%mod;f[l][r]+=mod;
				f[l][r]%=mod;
			}
			sum[l][r]=(sum[l+1][r]+f[l][r])%mod;
		}
	}
	cout<<f[1][n];
} 
