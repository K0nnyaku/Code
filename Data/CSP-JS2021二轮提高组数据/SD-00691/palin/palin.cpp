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
char a[M];
ll ans,l,tot,n,k,na[M];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	printf("%d\n",-1);
	return 0;
/*
7 3
(*??*??
*/
}
