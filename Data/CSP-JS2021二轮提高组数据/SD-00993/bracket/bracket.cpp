#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
char S[501],s[501];
const int N=40;
int f[N][N][N][N];
const int mod=1e9+7;
int ANS;
int dfs(int len,int lim,int L,int R)//x=1 ( 2) 3*
{
	if(lim>k||len>n||L>n/2||R>n/2)return 0;
	if(len==n&&L==R)return 1;
	cout<<len<<' '<<lim<<' '<<L<<' '<<R<<'\n';
	int ans=0;
	if(f[len][lim][L][R]!=-1)return f[len][lim][L][R];
	if(s[len+1]!='?')
	{
		if(s[len+1]=='(')ANS=(ANS+dfs(len+1,0,L+1,R))%mod;
		if(s[len+1]==')')ANS=(ANS+dfs(len+1,0,L,R+1))%mod;
		else ANS=(ANS+dfs(len+1,lim+1,L,R));
	}
	else for(int i=1;i<=3;i++)ANS=(ANS+dfs(len+1,(i==3)?lim:0,L+(i==1),R+(i==2)))%mod;
	if(lim<=k)f[len][lim][L][R]=ans;
	cout<<ans<<'\n';
	return ans;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==1)
	{
		puts("0");
		return 0;
	}
	memset(f,-1,sizeof f);
	scanf("%s",S);
	int len=strlen(S);
	for(int i=1;i<=len;i++)s[i]=S[i-1];
	dfs(1,0,1,0);
	cout<<ANS;
	return 0;
}
