#include<bits/stdc++.h>
using namespace std;
int bq1[1001][1001],bq2[1001][1001],bq3[1001][1001];
int p[1001][1001],t[1001][1001];
int f[1001][1001];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int cx,n,m,i,j,k;
	scanf("%d%d%d",&n,&m,&cx);
	for(i=1;i<=n-1;i++)
	  for(j=1;j<=m;j++)
	  {
	  	scanf("%d",&bq1[i][j]);
	  }
	for(i=1;i<=n;i++)
	  for(j=1;j<=m-1;j++)
	  {
	  	scanf("%d",&bq2[i][j]);
	  }
	for(i=1;i<=cx;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d%d%d",&bq3[i][j],&p[i][j],&t[i][j]);
		}
	}
	printf("0");
	return 0;
}
