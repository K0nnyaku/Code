//40pts
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool flag=0;
int T,n;
int a[1000010];
int blank[1000100];
char ans[1000100];
char temp[1001000];
bool vis[1001000];
void write()
{
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
	for(int i=1;i<=n;i++) printf("%c",temp[i]);
	printf("\n");
	return ;
}
bool check(int L,int R)
{
	
	/*
	puts("checking");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",blank[i]);
	}
	puts("");
	for(int i=1;i<=n;i++)
	{
		printf("%c",ans[i]);
	}
	puts("");
	*/
	
	int lc=L,rc=R;
	int cnt=0;
	while(cnt<n)
	{
		if(a[lc]==blank[n-cnt])
		{
			cnt++;
			temp[cnt]='L';
			lc++;
		}
		else if(a[rc]==blank[n-cnt])
		{
			cnt++;
			temp[cnt]='R';
			rc--;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int step,int l,int r)
{
	if(flag)
	{
		return;
	}
	if(step>n)
	{
		if(check(l,r))
		{
			write();flag=1;
		}
		return;
	}
	if(!vis[a[l]])
	{
		vis[a[l]]=1;
		blank[step]=a[l];
		ans[step]='L';
		dfs(step+1,l+1,r);
		vis[a[l]]=0;
	}
	if(!vis[a[r]])
	{
		vis[a[r]]=1;
		blank[step]=a[r];
		ans[step]='R';
		dfs(step+1,l,r-1);
		vis[a[r]]=0;
	}
	return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		scanf("%d",&n);
		for(int k=1;k<=2*n;k++)
		{
			scanf("%d",&a[k]);
		}
		if(n<=20)
		{
			dfs(1,1,2*n);
		}
		if(!flag)
		{
			printf("-1\n");
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
