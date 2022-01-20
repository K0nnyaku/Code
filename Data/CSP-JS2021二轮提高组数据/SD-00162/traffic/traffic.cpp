#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,m,t;//n水平，m竖直 
int q1[1001][1001],q2[1001][1001];//q1为横边权，q2为竖边权 

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int ans;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;i++)
	{
		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&q1[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m-1;j++)
				scanf("%d",&q2[i][j]);
		
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
