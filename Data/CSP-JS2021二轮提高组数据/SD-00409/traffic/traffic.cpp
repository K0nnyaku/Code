#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

inline int read()
{
	int a,flag;
	a=0;
	flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			flag=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*flag;
}

inline void write(int a)
{
	static int sta[64];
	int tp=0;
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	if(!a)
	{
		putchar('0');
		return;
	}
	while(a)
	{
		sta[tp++]=a%10;
		a/=10;
	}
	while(tp)
	{
		putchar(sta[--tp]+'0');
	}
}

int n,m,T;
int a[600][600];
int b[600][600];
int pos[60];
int val[60];
int col[60];
int coll[600][600];

int gv(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		return b[x1][min(y1,y2)];
	}
	if(y1==y2)
	{
		return a[min(x1,x2)][y1];
	}
	return 0;
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();
	m=read();
	T=read();
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)
		{
			b[i][j]=read();
		}
	}
	
	while(T--)
	{
		int k;
		k=read();
		int flag=1;
		if(k==1)
		{
			write(0);
			putchar('\n');
			continue;
		}
		for(int i=1;i<=k;++i)
		{
			val[i]=read();
			pos[i]=read();
			col[i]=read();
			if(i>=2&&col[i]!=col[i-1])
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			write(0);
			putchar('\n');
			continue;
		}
		if(k>2)
		{
			while(1)
			{
				cout<<"Fuck"<<endl;
			}
			return 0;
		}
		if(pos[2]==2*m+2*n&&pos[1]==1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[1]==2*m+2*n&&pos[2]==1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[1]==m&&pos[2]==m+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[2]==m&&pos[1]==m+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[1]==m+n&&pos[2]==m+n+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[2]==m+n&&pos[1]==m+n+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[1]==2*m+n&&pos[2]==2*m+n+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(pos[2]==2*m+n&&pos[1]==2*m+n+1)
		{
			write(min(val[1],val[2]));
			putchar('\n');
			continue;
		}
		if(col[1]==0)
		{
			swap(col[1],col[2]);
			swap(pos[1],pos[2]);
			swap(val[1],val[2]);
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
