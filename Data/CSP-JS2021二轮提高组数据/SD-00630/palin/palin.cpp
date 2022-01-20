#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int N=1e6+5;
int t,n,a[N],ne[N],now[N],b[N],A[N];

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n*2;++i)
		{
			a[i]=read();
			if(!now[a[i]])
				now[a[i]]=i;
			else
			{
				ne[i]=now[a[i]];
				ne[now[a[i]]]=i;
				now[a[i]]=0;
			}
		}
		int l=ne[1],r=ne[1],L=2,R=n*2,fl=1;
		b[1]=0;A[1]=a[1];
		for(int i=2;i<=n&&fl;++i)
		{
			if(l-1>=L+1&&l-1<=R&&ne[L]==l-1)
			{
				A[i]=a[L];
				--l,++L;
				b[i]=0;
			}
			else if(r+1>=L+1&&r+1<=R&&ne[L]==r+1)
			{
				A[i]=a[L];
				++r;++L;
				b[i]=0;
			}
			else if(l-1>=L&&l-1<=R-1&&ne[R]==l-1)
			{
				A[i]=a[R];
				--l;--R;
				b[i]=1;
			}
			else if(r+1>=L&&r+1<=R-1&&ne[R]==r+1)
			{
				A[i]=a[R];
				++r;--R;
				b[i]=1;
			}
			else fl=0;
		}
			
		if(!fl)
		{
			l=ne[n<<1];r=ne[n<<1];
			L=1,R=n*2-1,fl=1;
			b[1]=1;
			for(int i=2;i<=n&&fl;++i)
			{
				if(l-1>=L+1&&l-1<=R&&ne[L]==l-1)
				{
					A[i]=a[L];
					--l,++L;
					b[i]=0;
				}
				else if(r+1>=L+1&&r+1<=R&&ne[L]==r+1)
				{
					A[i]=a[L];
					++r;++L;
					b[i]=0;
				}
				else if(l-1>=L&&l-1<=R-1&&ne[R]==l-1)
				{
					A[i]=a[R];
					--l;--R;
					b[i]=1;
				}
				else if(r+1>=L&&r+1<=R-1&&ne[R]==r+1)
				{
					A[i]=a[R];
					++r;--R;
					b[i]=1;
				}
				else fl=0;
			}
				
			if(!fl) puts("-1");
			else
			{
				for(int i=1;i<=n;++i)
					if(a[l]==A[n-i+1])
						b[i+n]=0,++l;
					else if(a[r]==A[n-i+1])
						b[i+n]=1,--r;
				for(int i=1;i<=n*2;++i)
					if(b[i]) putchar('R');
					else putchar('L');
				puts("");
			}
		}
		else
		{
			for(int i=1;i<=n;++i)
				if(a[l]==A[n-i+1])
					b[i+n]=0,++l;
				else if(a[r]==A[n-i+1])
					b[i+n]=1,--r;
			for(int i=1;i<=n*2;++i)
				if(b[i]) putchar('R');
				else putchar('L');
			puts("");
		}
		for(int i=1;i<=n*2;++i)
			ne[i]=0,b[i]=0,a[i]=0,now[i]=0,A[i]=0;
	}
	return 0;
}
