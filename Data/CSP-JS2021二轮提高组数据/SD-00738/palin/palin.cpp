#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[1000010];
int ans[1000010];
int t[1000010];
bool vis[500010];
bool flag;
bool check()
{
	int head=1,tail=2*n;
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]==1)
		{
			t[i]=a[head];
			head++;
		}
		else
		{
			t[i]=a[tail];
			tail--;
		}
	}
	for(int i=1;i<=n;i++)
		if(t[i]!=t[2*n-i+1])
			return 0;
	return 1;
}
void dfs(int x)
{
	if(x==2*n+1)
	{
		if(check())
			flag=1;
		return;
	}
	if(flag)
		return;
	ans[x]=1;
	dfs(x+1);
	if(flag)
		return;
	ans[x]=2;
	dfs(x+1);
}
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	flag=0;
	if(n<=10)
	{
		dfs(1);
		if(!flag)
			printf("-1");
		else
		{
			for(int i=1;i<=2*n;i++)
				if(ans[i]==1)
					printf("L");
				else
					printf("R");
		}
		printf("\n");
		return;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		{
			printf("-1\n");
			return;
		}
		vis[a[i]]=1;
	}
	for(int i=1;i<=2*n;i++)
		printf("L");
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
		work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
