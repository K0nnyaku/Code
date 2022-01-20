#include<iostream>
#include<cstdio>
#include<cstdlib>

#define abs(a) ((a)<0?(-(a)):(a))

const int N=505;
const long long mod=1e9+7;

int n,m;

bool d=0;

long long f[2][N][N];

char s[N];

using namespace std;

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);//
	bool has=0;
	switch(s[1])
	{
		case '(':f[0][1][0]=1;
		break;
		case '?':f[0][1][0]=1;
		break;
	}
	for(int i=2;i<=n;++i)
	{
		d^=1;
		if(s[i]=='(')
		{
			for(int j=0;j<=n;++j)
			{
				f[d][j][0]=0;
				if(j>0)
				{
					for(int k=0;k<=m;++k)
						f[d][j][0]+=f[d^1][j-1][k];
					f[d][j][0]%=mod;
				}
				for(int k=1;k<=m;++k)
						f[d][j][k]=f[d^1][j][k-1];
			}
		}
		else if(s[i]==')')
		{
			for(int j=0;j<=n;++j)
			{
				f[d][j][0]=0;
				if(j<i)
				{
					for(int k=0;k<=m;++k)
						f[d][j][0]+=f[d^1][j+1][k];
					f[d][j][0]%=mod;
				}
				for(int k=1;k<=m;++k)
						f[d][j][k]=f[d^1][j][k-1];
			}
		}
		else if(s[i]=='*')
		{
			for(int j=0;j<=n;++j)
				for(int k=m;k>=0;--k)
				{
					if(k>0)
						f[d][j][k]=f[d^1][j][k-1];
					else
						f[d][j][k]=0;
				}
		}
		else if(s[i]=='?')
		{
			has=1;
			for(int j=0;j<=n;++j)
			{
				f[d][j][0]=0;
				if(j>0)
				{
					for(int k=0;k<=m;++k)
						f[d][j][0]+=f[d^1][j-1][k];
				}
				if(j<i)
				{
					for(int k=0;k<=m;++k)
						f[d][j][0]+=f[d^1][j+1][k];
				}
				f[d][j][0]%=mod;
				for(int k=1;k<=m;++k)
				{
					f[d][j][k]=0;
					if(k>0)
						f[d][j][k]+=f[d^1][j][k-1];
					f[d][j][k]%=mod;
				}
			}
		}
	}
	if(!has || n>100)
		cout<<0;
	else
	{
		cout<<f[d][0][0];
	}
	return 0;
}
