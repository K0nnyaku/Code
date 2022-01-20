#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 500050
int a[N],b[N];
int T,n;
int s[N],vis[N],book;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+ch-48;ch=getchar(); }
	return x*f; 
}
void check()
{
	int ok=1;
	for(int i=1;i<=2*n;i++)
		if(b[i]!=b[2*n-i+1]) { ok=0;break; }
	for(int i=1;i<=n;i++) 
		if(vis[i]!=2) { ok=0;break; }
	if(ok)
	{
		for(int i=1;i<=2*n;i++)
		{
			if(s[i]==1) putchar('L');
			else if(s[i]==-1) putchar('R');
		}
		puts("");
		book=1;
	}
	return ;
}
void dfs(int pos,int x,int y)
{
	if(book==1) return ;
	if(pos==2*n+1) { check();return ; }
	if(vis[a[x]]<2)
	{
		s[pos]=1;
		b[pos]=a[x];
		vis[a[x]]++;
		dfs(pos+1,x+1,y);
		s[pos]=0;
		b[pos]=0;
		vis[a[x]]--;
	}
	if(vis[a[y]]<2)
	{
		s[pos]=-1;
		b[pos]=a[y];
		vis[a[y]]++;
		dfs(pos+1,x,y-1);
		s[pos]=0;
		b[pos]=0;
		vis[a[y]]--;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		book=0;
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		n=read();
		for(int i=1;i<=2*n;i++) a[i]=read();
		dfs(1,1,2*n);
		if(book==0) puts("-1");
	}
	return 0;
}
