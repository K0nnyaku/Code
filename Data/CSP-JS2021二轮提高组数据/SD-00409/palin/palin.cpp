#include<iostream>
#include<cstdio>
#include<algorithm>

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

int a[1001001];
int l,r;
int b[1001001];
int op[1001001];
int n;
int flag;

void dfs(int nw)
{
	if(flag==1)
	{
		return;
	}
	if(nw>2*n)
	{
		
		for(int i=1; i<=2*n; ++i)
		{
			if(op[i]==1)
			{
				putchar('L');
			}
			else
			{
				putchar('R');
			}
		}
		flag=1;
		putchar('\n');
		return;
	}
	
	b[nw]=a[l++];
//	
//	for(int i=1;i<=nw;++i)
//	{
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
	
	if(nw>n)
	{
		if(b[nw]==b[2*n-nw+1])
		{
			op[nw]=1;
			dfs(nw+1);
		}
	}
	else
	{
		op[nw]=1;
		dfs(nw+1);
	}
	l--;
	
	
	if(flag==1)
	{
		return;
	}
	
	
	b[nw]=a[r--];
	if(nw>n)
	{
		if(b[nw]==b[2*n-nw+1])
		{
			op[nw]=2;
			dfs(nw+1);
		}
	}
	else
	{
		op[nw]=2;
		dfs(nw+1);
	}
	r++;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	int T;
	T=read();
	while(T--)
	{
		l=1;
		flag=0;
		n=read();
		r=2*n;
		for(int i=1; i<=2*n; ++i)
		{
			a[i]=read();
		}
		dfs(1);
		if(flag==0)
		{
			printf("-1\n");
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
