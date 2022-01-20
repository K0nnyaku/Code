#include<cstdio>
#include<iostream>
using namespace std;
const int N=500005;
int T,n,a[N*2],as[N*2];
bool us[N],asb[N],ckb[N];
inline int read()
{
	int s=0;char c=getchar();
	while(!isdigit(c))  c=getchar();
	while(isdigit(c))  s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
bool dfs(int l,int r)
{
	if(r-l+1==n)
	{
		for(int i=n;i;i--)
		{
			if(a[l]!=as[i]&&a[r]!=as[i])  return 0;
			if(as[i]==a[l])  ckb[i]=0,l++;
			else  r--,ckb[i]=1; 
		}
		for(int i=1;i<=n;i++)  putchar(asb[i]?'R':'L');
		for(int i=n;i;i--)  putchar(ckb[i]?'R':'L');
		puts("");return 1;
	}
	int nw=2*n-r+l;
	if(us[a[l]])
	{
		us[as[nw]=a[r]]=asb[nw]=1;
		if(dfs(l,r-1))  return 1;
		us[a[r]]=0;return 0;
	}
	if(us[a[r]])
	{
		us[as[nw]=a[l]]=1;asb[nw]=0;
		if(dfs(l+1,r))  return 1;
		us[a[l]]=0;return 0;
	}
	if(a[l]<=a[r])
	{
		us[as[nw]=a[l]]=1;asb[nw]=0;
		if(dfs(l+1,r))  return 1;
		us[a[l]]=0;
		us[as[nw]=a[r]]=asb[nw]=1;
		if(dfs(l,r-1))  return 1;
		us[a[r]]=0;
	}
	else
	{
		us[as[nw]=a[r]]=asb[nw]=1;
		if(dfs(l,r-1))  return 1;
		us[a[r]]=0;
		us[as[nw]=a[l]]=1;asb[nw]=0;
		if(dfs(l+1,r))  return 1;
		us[a[l]]=0;
	}return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n*2;i++)  a[i]=read();
		if(!dfs(1,n*2))  puts("-1");
	}return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
