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
char c[1000001];
int e,m,n,a[1000001],b[1000001],f[1000001];
inline int aa()
{
	register int i(0);
	while(++i<n)if(b[i]^b[m-i+1])return 0;
	return 1;
}
inline void dfs(int l,int r)
{
	if(!e&&b[0]<m)
	{
		++b[0];
		register int d(b[m-b[0]+1]);
        if(!f[a[l]]||a[l]==d)
        {
			b[b[0]]=a[l],c[b[0]]='L',++f[a[l]];
			dfs(l+1,r);
			if(e)return;
			--f[a[l]];
		}
		if(!f[a[r]]||a[r]==d)
		{
			b[b[0]]=a[r],c[b[0]]='R',++f[a[r]];
			dfs(l,r-1);
			if(e)return;
			--f[a[r]];
		}
		--b[0];
	}
	else if(aa())e=1;
}
int main()
{
	freopen("palin.in","r",stdin);
	register int i,t(read());
	freopen("palin.out","w",stdout);
	while(t--)
	{
		i=-1;
		while(++i<=m)b[i]=f[i]=0;
		i=e=0;
		n=read();
		m=n<<1;
		while(++i<=m)a[i]=read();
		dfs(1,m);
		if(e)
		{
			i=0;
			while(++i<=m)putchar(c[i]);
		}
		else
			putchar('-'),putchar('1');
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
