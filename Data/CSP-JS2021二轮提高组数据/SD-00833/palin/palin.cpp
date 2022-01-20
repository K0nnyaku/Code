#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N],num[N],p[N];
int n;
bool flag;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		    f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void input()
{
	n=read();
	for(int i=1;i<=n*2;++i)
	    a[i]=read();
}
void dfs(int x,int lef,int rig)
{
	if(flag==1)
	    return;
	if(x==2*n+1)
	{
		flag=1;
		for(int i=1;i<=2*n;++i)
		{
			if(p[i]==1)
			    printf("L");
			if(p[i]==2)
			    printf("R");
		}
		printf("\n");
	}
	if(x<=n)
	{
		if(num[a[lef]]==0)
		{
			num[a[lef]]=x;
			p[x]=1;
		    dfs(x+1,lef+1,rig);
		    num[a[lef]]=0;
		    p[x]=0;
		}
		if(num[a[rig]]==0)
		{
			num[a[rig]]=x;
			p[x]=2;
		    dfs(x+1,lef,rig-1);
		    num[a[rig]]=0;
		    p[x]=0;
		}
	}
	else
	{
		if(num[a[lef]]+x==2*n+1)
		{
			p[x]=1;
		    dfs(x+1,lef+1,rig);
		    p[x]=0;
		}
		else if(num[a[rig]]+x==2*n+1)
		{
			p[x]=2;
		    dfs(x+1,lef,rig-1);
		    p[x]=0;
		}
		else 
		    return;
	}
}
void solve()
{
	memset(a,0,sizeof(a));
	memset(num,0,sizeof(num));
	memset(p,0,sizeof(p));
	flag=0;
	input();
	dfs(1,1,2*n);
	if(!flag)
	    printf("-1\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int tests=read();
	for(int i=1;i<=tests;++i)
	    solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
