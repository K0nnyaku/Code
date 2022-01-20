#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#define MAXN 1005
#define MAXM 
#define INF 0x3f3f3f3f
#define BASE 131
#define ll long long
#define ull unsigned long long
using namespace std;
int a[MAXN<<1],b[MAXN<<1],ans[MAXN<<1];
char cz[MAXN<<1],anscz[MAXN<<1],c[MAXN<<1];
int n;
int check()
{
	for(int i=1;i<=n;i++)if(b[i]!=b[2*n-i+1])return 0;
	for(int i=1;i<=2*n;i++)if(b[i]!=ans[i])return b[i]<ans[i];
	return 0;
}
void dfs(int ceng,int h,int t)
{
	//for(int i=1;i<=2*n;i++)printf("%c",cz[i]);
	//printf("\n");
	if(b[ceng-1]>ans[ceng-1])return;
	if(ceng>n+1)if(b[ceng-1]!=b[2*n-(ceng-1)+1])return;
	if(ceng<=n+1&&c[b[ceng-1]]==2)return;
	if(ceng==2*n+1)
	{
		if(check())for(int i=1;i<=2*n;i++)ans[i]=b[i],anscz[i]=cz[i];
		return;
	}
	cz[ceng]='L';
	b[ceng]=a[h];
	c[a[h]]++;
	dfs(ceng+1,h+1,t);
	c[a[h]]--;
	cz[ceng]='R';
	b[ceng]=a[t];
	c[a[t]]++; 
	dfs(ceng+1,h,t-1);
	c[a[t]]--; 
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=0;i<=2*n;i++)ans[i]=9999999;
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		dfs(1,1,2*n);
		if(ans[1]==9999999)printf("-1");
		else for(int i=1;i<=2*n;i++)printf("%c",anscz[i]);
		printf("\n");
	}
	return 0;
}
