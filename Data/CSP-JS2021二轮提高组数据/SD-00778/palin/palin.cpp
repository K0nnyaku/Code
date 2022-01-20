#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int vis[1000100],a[1000100],n;
char ans[1000100];
inline int read()
{
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		r=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();
	}
	return w*r;
}
int dfs(int head,int tail,int k)
{
	if(k==2*n)
	{
		ans[k]='L';
		return 1;
	}
	if(vis[a[head]]==0)
	{
		vis[a[head]]=k;
		if(dfs(head+1,tail,k+1)==1)
		{
			ans[k]='L';
			return 1;
		}
		vis[a[head]]=0;
	}
	if(vis[a[head]]!=0&&k==2*n-vis[a[head]]+1)
	{
		if(dfs(head+1,tail,k+1)==1)
		{
			ans[k]='L';
			return 1;
		}
	}
	if(vis[a[tail]]==0)
	{
		vis[a[tail]]=k;
		if(dfs(head,tail-1,k+1)==1)
		{
			ans[k]='R';
			return 1;
		}
		vis[a[tail]]=0;
	}
	if(vis[a[tail]]!=0&&k==2*n-vis[a[tail]]+1)
	{
		if(dfs(head,tail-1,k+1)==1)
		{
			ans[k]='R';
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=2*n;j++)
		{
			scanf("%d",&a[j]);
		}
		if(dfs(1,2*n,1)==0)
		printf("-1\n");
		else
		{
			for(int j=1;j<=2*n;j++)
			{
				printf("%c",ans[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
