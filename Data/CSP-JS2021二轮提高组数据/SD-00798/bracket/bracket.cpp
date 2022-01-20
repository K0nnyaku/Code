#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=600;
const long long mod=1e9+7;
char s[maxn];
int n,k;
long long f[maxn][maxn][maxn]={0}; 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s+1;
	if(s[1]==')'||s[1]=='*')
	{
		printf(0);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	f[1][1][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int q=0;q<=k;q++)
			{
				if(s[i]=='(')
				{
					if(q==0&&j>0)
					{
						for(int qq=0;qq<=k;qq++)
						{
							f[i][j][0]+=f[i-1][j-1][qq];
							f[i][j][0]%=mod;
						} 
					}
				}
				else if(s[i]==')')
				{
					if(q==0)
					{
						for(int qq=0;qq<=k;qq++)
						{
							f[i][j][0]+=f[i-1][j+1][qq];
							f[i][j][0]%=mod;
						} 
					}
				}
				else if(s[i]=='*')
				{
					if(q>0)
					{
						f[i][j][q]+=f[i-1][j][q-1];
						f[i][j][q]%=mod;
					}
				}
				else
				{
					if(q==0&&j>0)
					{
						for(int qq=0;qq<=k;qq++)
						{
							f[i][j][0]+=f[i-1][j-1][qq];
							f[i][j][0]%=mod;
						} 
					}
					if(q==0)
					{
						for(int qq=0;qq<=k;qq++)
						{
							f[i][j][0]+=f[i-1][j+1][qq];
							f[i][j][0]%=mod;
						} 
					}
					if(q>0)
					{
						f[i][j][q]+=f[i-1][j][q-1];
						f[i][j][q]%=mod;
					}
				}
			}
		}
	}
	printf("%lld",f[n][0][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
