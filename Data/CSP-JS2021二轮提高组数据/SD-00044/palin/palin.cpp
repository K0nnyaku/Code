#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma GCC optimize(2)
using namespace std;
const int N=1e6+10;
int T,n,a[N],temp[N];
char cz[N];
bool flag=false;
bool st[N];

bool check()
{
	for(int i=1;i<=n;i++)
	if(temp[i]!=temp[2*n+1-i]) return false;
	return true;
}

void dfs(int u,int l,int r)
{
	if(flag) return ;
	if(u==2*n+1)
	{
		if(check())
		{
			flag=true;
			for(int i=1;i<=2*n;i++) printf("%c",cz[i]);
			printf("\n");
		}
		return ;
	}
	
	if(u<=n)
	{
		if(!st[a[l]])
		{
			temp[u]=a[l];
			st[a[l]]=true;
			cz[u]='L';
			dfs(u+1,l+1,r);
			st[a[l]]=false;
		}
		
		if(!st[a[r]])
		{
			temp[u]=a[r];
			st[a[r]]=true;
			cz[u]='R';
			dfs(u+1,l,r-1);
			st[a[r]]=false;
		}
	}
	else 
	{
		if(a[l]==temp[2*n+1-u])
		{
			temp[u]=a[l];
			st[a[l]]=false;
			cz[u]='L';
			dfs(u+1,l+1,r);
			st[a[l]]=true;
		}
		else if(a[r]==temp[2*n+1-u])
		{
			temp[u]=a[r];
			st[a[r]]=false;
			cz[u]='R';
			dfs(u+1,l,r-1);
			st[a[r]]=true;
		}
		else return ;
	}
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	
	while(T--)
	{
		flag=false;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(1,1,2*n);
		if(flag==false) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
