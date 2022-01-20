#include<cstdio>
#include<iostream>
inline int read()
{
	register char c(getchar());
	register int x(0);
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
inline void write(int x)
{
	register int s[11],t(0),y;
	while(x)
	{
		y=x/10;
		s[++t]=x-(y<<1)-(y<<3);
		x=y;
	}
	if(!t)s[++t]=0;
	while(t)putchar(s[t--]^48);
}
char c[501];
int b,d,k,n,a[501],s[501];
inline int aa()
{
	register int a(0),b,i(0),j;
	while(++i<=n&&a>=0)
		if(c[i]=='(')
			++a,b=i;
		else if(c[i]==')')
   		{
			--a;
			if(a<0)
				return 0;
			if(i<n&&b>1&&c[b-1]=='*'&&c[i+1]=='*')
				return 0;
  		}
	if(c[1]=='*'||c[n]=='*')
		return 0;
 	return !a&&i>n;
}
inline void dfs(int u)
{
	if(a[0]>u)
	{
		++u;
		c[a[u]]='(';
		dfs(u);
		c[a[u]]=')';
		dfs(u);
		if(b<k)
		{
			c[a[u]]='*';
			++b;
			dfs(u);
			--b;
		}
	}
	else if(aa())
		++d;
}
int main()
{
	register int i(0);
	freopen("bracket.in","r",stdin);
	n=read();
	k=read();
	while(++i<=n)
	{
		c[i]=getchar();
		while(c[i]^'*'&&c[i]^'('&&c[i]^')'&&c[i]^'?')
			c[i]=getchar();
		if(c[i]=='*')
			++b;
		else if(c[i]=='?')
			a[++a[0]]=i;
	}
	fclose(stdin);
	dfs(0);
	freopen("bracket.out","w",stdout);
	write(d);
	fclose(stdout);
	return 0;
}
