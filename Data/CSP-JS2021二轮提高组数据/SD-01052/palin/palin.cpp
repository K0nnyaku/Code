#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
int a[2010],b[2010];
int ans[2010],tot;
int read()
{
	int f=1,s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return f*s;
}
bool check()
{
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1]) return false;
	}
	return true;
}
bool solve(int l,int r)
{
	if(l>r)
	{
		if(check()) return true;
		return false;
	}
	b[++tot]=a[l];
	ans[tot]=1;
	if(solve(l+1,r)) return true;
	b[tot]=a[r];
	ans[tot]=2;
	if(solve(l,r-1)) return true;
	tot--;
	return false;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();n*=2;
		for(int i=1;i<=n;i++) a[i]=read();
		if(solve(1,n))
		{
			for(int i=1;i<=n;i++)
			{
				if(ans[i]==1) printf("L");
				else printf("R"); 
			}
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
