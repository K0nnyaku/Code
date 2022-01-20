#include<bits/stdc++.h>
using namespace std;
int n,k;
char a[501];
int f[501];
const int mod=1e9+7;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>a+1;
	f[2]=1;
	for(int i=1;i<=k;i++)
	{
		f[i+2]=1;
		f[i]%=mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int t=0;t<=k;t++)
			{
				f[i]+=f[j-t]+f[i-j];
				f[i]%=mod;
			}
		}
	}
	cout<<f[n];
	return 0;
}


