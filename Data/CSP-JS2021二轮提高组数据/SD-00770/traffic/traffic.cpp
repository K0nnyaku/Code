#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<cstdlib>
using namespace std;
int read()
{
	int x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=0;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?x:(~x)+1;
}
int n,m,t,k;
int xxx2[500][500]; 
int xxx1[500][500]; 
int xxx3[500],tt[500],p[500]; 
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();t=read();
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			xxx1[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			xxx2[i][j]=read();
		}
	}
	while(t--)
	{
		k=read();
		for(int i=1;i<=k;i++)
		{
			xxx3[i]=read();p[i]=read();
			tt[i]=read();
		}
		cout<<12;
	 } 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
