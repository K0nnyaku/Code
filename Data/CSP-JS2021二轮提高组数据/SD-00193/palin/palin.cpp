#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int T,n,a[10010],b[10010],c[10010],ans[101][101];
bool judge()
{
	for(int i=1;i<=n;i++) if(b[i]!=b[2*n+1-i]) return false;
	return true; 
}
void comp()
{
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]<c[i])
		{
			for(int j=1;j<=2*n;j++)
			{
				c[i]=ans[i];
			}
			return;
		} 
	}
}
void dfs(int head,int tail,int tmp)
{
	if(head==tail||tmp==2*n)
	{
		b[tmp]=a[head];
		ans[tmp]=0;
		if(judge())
		{
			comp();
		}
		return;
	} 
	for(int i=1;i<=2;i++)
	{
		if(i==1)
		{
			b[tmp]=a[head];
			ans[tmp]=0;
			dfs(head+1,tail,tmp+1);
		}
		if(i==2)
		{
			b[tmp]=a[tail];
			ans[tmp]=1;
			dfs(head,tail-1,tmp+1);
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			c[i]=9;
			scanf("%d",&a[i]);
		}
		dfs(1,2*n,1);
		int flag=0;
		for(int i=1;i<=n*2;i++)
		{
			if(c[i]==9)
			{
				ans
				flag=1;
				break;
			} 
		}
		if(flag=1) continue;
		for(int i=1;i<=n*2;i++)
		{
			if(c[i]==0) cout<<'L';
			else cout<<'r';
		}
	}
	for(int i=1;)
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
2 5
4 1 2 4 5 3 1 2 3 5
4 3
3 2 1 2 1 3
*/
