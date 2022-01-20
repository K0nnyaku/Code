#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

const int N=1e5;

using namespace std;

int n,t,a[N],b[N];

bool isl[N];

char bo[2]={'R','L'};

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

inline int check()
{
	int l=1,r=2*n;
	for(int i=1;i<=2*n;++i)
		if(isl[i])
		{
			b[i]=a[l++];
		}
		else
			b[i]=a[r--];
	for(int i=1;i<=n;++i)
		if(b[i]!=b[n*2-i+1])	
			return 0;
	return 1;
} 

int dfs(int step)
{
	isl[step]=1;
	if(step==2*n)
	{
		if(check())
			return 1;
	}
	else
		if(dfs(step+1))	
			return 1;
	isl[step]=0;
	if(step==2*n)
	{
		if(check())
			return 1;
	}
	else
		if(dfs(step+1))	
			return 1;
	return 0;
}

inline void work()
{
	n=read();
	for(int i=1;i<=2*n;++i)
		a[i]=read();
	if(dfs(1))
	{
		for(int i=1;i<=2*n;++i)
			putchar(bo[isl[i]]);
		putchar('\n'); 
	}
	else
	{
		printf("-1\n");
	}
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--) 
		work();
	return 0;
}
