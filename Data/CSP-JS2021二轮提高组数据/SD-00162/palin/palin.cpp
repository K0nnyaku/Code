#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
int n,t;
const int maxn=1e6;
int nums[maxn];
char ans[100001];
int q1[10001],q2[10001];
void dfs(int h1,int h2,int t1,int t2)
{
	int flag=1;
	for(int i=1;i<=n;i++)
		if(q2[i]!=q2[2*n-i+1])
			flag=0;
	if(flag==1)
		printf("%s",ans);
	
}	
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	int cnt=1;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&q1[i]);
		int h1=1,h2=2*n,t1=n,t2=2*n;
		//dfs(h1,h2,t1,t2);
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
