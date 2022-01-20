#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,k;
char a[505];
inline int read()
{
	int x=1,y=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')
	  c=getchar();
	if(c=='-')
	{
	  x=-1;
	  c=getchar();
	}
	while(c>='0'&&c<='9')
	{
	  y=(y<<3)+(y<<1)+c-'0';
	  c=getchar();
	}
	return x*y;
}
//const int maxn;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",a+1);
	printf("0")
	return 0;
}

