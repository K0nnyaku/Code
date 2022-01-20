#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
const int MAXN=500001;
int n,a[MAXN<<1],ans[MAXN<<1],b[MAXN<<1],L,R,pos2,fl;
void dfs(int st)
{
		if(fl)
			return ;
		if(st==2*n)
		{
			int fl1=1;
			for(int i=1;i<=st;i++)
				if(b[i]!=b[2*n+1-i])
				{
					fl1=0;
					break;
				}
			if(fl1)
			{
				fl=true;
				return ;
			}
			return ; 
		}
		L++;
		b[st+1]=a[L-1];
		ans[st+1]=0; 
		dfs(st+1);
		if(fl)
			return ;
		b[st+1]=a[R];
		L--;
		R--;
		ans[st+1]=1; 
		dfs(st+1);
		if(fl)
			return ;
		R++;
		return ;
}
int main(void)
{
	int T;
	cin >> T;
	while(T--)
	{
	for(int i=1;i<=n*2;i++)
		ans[i]=0,a[i]=0,b[i]=0;
	scanf("%d",&n);
	for(int i;i<=n*2;i++)
		scanf("%d",&a[i]);
	L=1,R=2*n;
	dfs(0);
	for(int i=1;i<=n*2;i++)
		if(ans[i])
			printf("R");
		else
			printf("L");
	}
	return 0;
}
