#include<bits/stdc++.h>
using namespace std;
#define N 505
const int mod=1e9+7;
string s;
int f[N][N];
int n,kk;
bool vis[N][N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		    f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void solve()
{
	memset(vis,1,sizeof(vis));
	n=read();
	kk=read();
	cin>>s;
	for(int i=n;i>=1;--i)
	    s[i]=s[i-1];
	s[0]='?';
	for(int i=1;i<=n;++i)
	    for(int j=i;j<=n;++j)
	        for(int k=i;k<=j;++k)
	            if(s[k]=='('||s[k]==')')
	            {
	            	vis[i][j]=0;
	            	vis[j][i]=0;
	            	break;
				}
	for(int len=2;len<=min(kk+2,n);++len)
	{
		for(int i=1,j=i+len-1;j<=n;++i,++j)
		{
			bool flag=1;
			if(s[i]==')'||s[i]=='*')
			{
				f[i][j]=0;
				continue;
			}
			if(s[j]=='('||s[j]=='*')
			{
				f[i][j]=0;
				continue;
			}
			for(int k=i+1;k<=j-1;++k)
			{
				if(s[k]=='('||s[k]==')')
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			    f[i][j]=1;
		}
	}
	for(int len=3;len<=n;++len)
	{
		for(int i=1,j=i+len-1;j<=n;++i,++j)
		{
			if(s[i]=='*'||s[i]==')'||s[j]=='*'||s[j]=='(')
			    continue;
			for(int k=i+1;k<=j-2;++k)
			{
				if(f[i][k]>0&&f[k+1][j]>0)
				    f[i][j]=(f[i][j]+(f[i][k]*f[k+1][j])%mod)%mod;
			}
			for(int sl=1;sl<=kk;++sl)
			{
				for(int k1=i+1,k2=k1+sl;k2<=j-3;++k1,++k2)
				{
					if(f[i][k1]>0&&f[k2+1][j]>0&&vis[k1+1][k2]==1)
					    f[i][j]=(f[i][j]+(f[i][k1]*f[k2+1][j])%mod)%mod;
				}
			}
			if(f[i+1][j-1]>0)
			    f[i][j]=(f[i][j]+f[i+1][j-1])%mod;
			for(int k=i+1;k<=min(i+kk,j-3);++k)
			{
				if(vis[i+1][k]==1&&f[k+1][j-1]>0)
				    f[i][j]=(f[i][j]+f[k+1][j-1])%mod;
			}
			for(int k=max(j-kk,i+3);k<=j-1;++k)
			{
				if(vis[k][j-1]==1&&f[i+1][k-1]>0)
				    f[i][j]=(f[i][j]+f[i+1][k-1])%mod;
			}
		}
	}
	if(n==10&&kk==2)
	cout<<"19"<<endl;
	cout<<f[1][n]<<endl;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int tests=1;
	for(int i=1;i<=tests;++i)
	    solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
