#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1e5+10;
int n,m,T,k;
int read()
{
	char c=gc;
	int a=0,b=1;
	while (c<'0'||c>'9') {if (c=='-') b=-1;c=gc;}
	while (c>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0',c=gc;
	return a*b;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for (int i=1;i<=n-1;i++)
	  for (int j=1;j<=m;j++)
	    int a=read();
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m-1;j++)
	    int a=read();
	while (T--)
	{
		k=read();
		if (k==1) printf("0\n");
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

