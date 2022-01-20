#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1000010
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
//-------------------------------------
int T,n,en,a[N],ans[N],nw[N];
bool flag=0;
bool check()
{
	int fr=1,ls=en;
	for(int i=1;i<=en;++i)
	{
		if(ans[i]==1)
		{
			nw[i]=a[fr];
			fr++;
		}else{
			nw[i]=a[ls];
			ls--;
		}
	}
	for(int i=1;i<=n;++i)
		if(nw[i]!=nw[2*n+1-i])
			return false;
	return true;
}
void dfs(int k)
{
	if(flag) return ;
	if(k==en+1)
	{
		if(check())
		{
			for(int i=1;i<=en;++i)
			{
				if(ans[i]==1)
					printf("L");
				else
					printf("R");
			}
			putchar('\n');
			flag=1;
		}
		return ;
	}
	ans[k]=1;
	dfs(k+1);
	ans[k]=2;
	dfs(k+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		flag=0;
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		n=read();
		en=2*n;
		for(int i=1;i<=en;++i)
			a[i]=read();
		dfs(1);
		if(!flag)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

