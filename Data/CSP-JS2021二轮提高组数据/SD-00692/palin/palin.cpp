#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
int a[N],b[N],h[N];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return f*x;
}
int n;
bool flag=false;
void dfs(int t,int head,int tail)
{
	if(flag)
	{
		return;
	}
	if(t>n)
	{
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(h[i]==1)
			{
				putchar('L');
			}
			else
			{
				putchar('R');
			}
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=2;i++)
	{
		if(i==1)
		{
			b[t]=a[head];
			if(t>n/2&&b[t]!=b[n-t+1])
			{
				continue;
			}
			h[t]=1;
			dfs(t+1,head+1,tail);
		}
		else
		{
			b[t]=a[tail];
			if(t>n/2&&b[t]!=b[n-t+1])
			{
				continue;
			}
			h[t]=2;
			dfs(t+1,head,tail-1);
		} 
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	T=read();
	if(T<=10)
	{
		while(T--)
		{
			n=read();
			n*=2;
			flag=false;
			for(int i=1;i<=n;i++)
			{
				a[i]=read();
			}
			dfs(1,1,n); 
			if(!flag)
			{
				printf("-1\n");
			}
		}
	}
	else
	{
		while(T--)
		{
			n=read();
			n*=2;
			for(int i=1;i<=n;i++)
			{
				a[i]=read();
			}
			for(int i=1;i<=n;i++)
			{
				putchar('L');
			}
			printf("\n");
		}	
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
