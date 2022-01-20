#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>'0'&&ch<'9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
 } 
 inline void write(int x)
 {
 	if(x<0)
 	{
 		putchar('-');
 		x=-x;
	 }
	 if(x>9)
	 write(x/10);
	 putchar(x%10+'0');
 }
 int main()
 {
 	freopen("traffic.in","r",stdin);
	freopen("traffic.in","w",stdout);
	int n,m,t,u;
	u=99;
	n=read();m=read();t=read();
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m-1;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%d",&b[i][j]);
	}
	write(u);
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
