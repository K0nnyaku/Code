#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5;
int n,m,k;
struct node{
	int l;
	int r;
	int id;//编号 
}a[N],b[N];
// a 国内 b 国外 
int sum;
bool vis[N];
int dfs(int x,int num)
{
	memset(vis,0,sizeof(vis));
	if(num == 1) 
	{
		int ans = 0,cnt;
		while(1)
		{
			if(x == 0 || ans == m) break;
			for(int i=1;i<=m;i++)
			{
				if(vis[i] == false)
				{
					if(a[i].l > cnt )
					{
						vis[i] = true;
						cnt = a[i].r;
						ans++; 
					}
				}
			}
			x -= 1;
			cnt = 0;
		}
		return ans;
	}
	else 
	{
		int ans = 0,cnt = 0;
		while(1)
		{
			if(x == 0 || ans == k) break;
			for(int i=1;i<=k;i++)
			{
				if(vis[i] == false)
				{
					if(b[i].l > cnt )
					{
						vis[i] = true;
						cnt = b[i].r;
						ans++;
					}
				}
			}
			x -= 1;
			cnt = 0;
		}
		return ans;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].id = i;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].id = i;
	}
	for(int i=0;i<=n;i++)
	{
		int j = n - i;
		int ans1 = dfs(i,1);
		int ans2 = dfs(j,2);
		sum = max(sum,ans1 + ans2);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/
