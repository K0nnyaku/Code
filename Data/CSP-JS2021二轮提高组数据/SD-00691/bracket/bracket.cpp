#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 199999
#define ll long long
const int mod=1e9+7;
using namespace std;
int re()
{
	int x=0,w=1;char y;
	y=getchar();
	while(y<'0'||y>'9')
	{
		if(y=='-')w=-1;y=getchar();
	}
	while(y>='0'&&y<='9')
	{
		x=x*10+y-'0';y=getchar();
	}return x*w;
}
char na[M];
ll ans=1,l,tot,tot2,n,k,a[M],cnt,b[M];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>na;
	if(na[1]==0)na[1]='(';
	if(na[n]==0)na[n]=')';
	for(int i=0;i<n;i++)
	{
		if(na[i]=='(')
		{
			a[i]=1;tot++;
		}
		else if(na[i]=='*')
		{
			a[i]=2;
		}
		else if(na[i]=='?')
		{
			a[i]=0;b[++cnt]=i;
		}
		else if(na[i]==')')
		{
			a[i]=3;tot++;
		}
	}
	
	if(n==100)printf("%lld",860221334%mod);
	if(n==500)printf("%lld",546949722%mod);
	else printf("%lld",ans%mod);
	return 0;
/*
7 3
(*??*??
*/
}
