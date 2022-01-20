#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int T;
int n,a[1000005];
int b1[1000005];
int fa[1000005];
int vis[1000005],l,r;
int ansplus;

int read()
{
	int ans=0,res=1;
	char ch=getchar();
	while ((ch>'9'||ch<'0')&&ch!='-')
		ch=getchar();
	if (ch=='-')
	{
		res=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*res;
}

void print()
{
	char F[5000005];
	int cnt=0;
	while (cnt<2*n)
	{
		if (ansplus&1)
			F[cnt++]='R';
		else
			F[cnt++]='L';
		ansplus=ansplus>>1;
	}
	while (cnt)
		putchar(F[--cnt]);
	putchar('\n');
	return;
}

bool dfs(int x)
{
	cout << x << endl;
	if (x>2*n)
		return true;
	if (vis[l]==0)
	{
		vis[l]=x;
		vis[fa[l]]=2*n+1-x;
		l++;
		ansplus=ansplus<<1; 
		if (dfs(x+1))
			return true;
		ansplus=ansplus>>1;
		l--;
		vis[l]=0;
		vis[fa[l]]=0;
	}
	if (vis[r]==0)
	{
		vis[r]=x;
		vis[fa[r]]=2*n+1-x;
		r--;
		ansplus=ansplus<<1;
		ansplus++; 
		if (dfs(x+1))
			return true;
		ansplus=ansplus>>1;
		r++;
		vis[r]=0;
		vis[fa[r]]=0;
	}
	if (vis[r]==x)
	{
		r--;
		ansplus=ansplus<<1;
		ansplus++; 
		if (dfs(x+1))
			return true;
		ansplus=ansplus>>1;
		r++;
	}
	if (vis[l]==x)
	{
		l++;
		ansplus=ansplus<<1; 
		if (dfs(x+1))
			return true;
		ansplus=ansplus>>1;
		l--;
	}
	return false;
}

inline void init()
{
	T=read();
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		memset(fa,0,sizeof(fa));
		n=read();
		for (int i=1;i<=2*n;i++)
		{
			a[i]=read();
			if (b1[a[i]]!=0)
			{
				fa[b1[a[i]]]=i;
				fa[i]=b1[a[i]];
			}
			else
				b1[a[i]]=i;
		}
 		l=1;
		r=2*n;
		if (dfs(1))
			print();
		else
			printf("-1\n");
	}
	return;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	init();
	//fclose(stdin);
	//fclose(stdout);
	return 0; 
}
