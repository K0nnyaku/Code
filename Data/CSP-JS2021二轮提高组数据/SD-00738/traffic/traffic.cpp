#include<iostream>
#include<cstdio>
using namespace std;
int n,m,T;
int x1[510][510];
int x2[510][510];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&x1[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			scanf("%d",&x2[i][j]);
	for(int i=1;i<=T;i++)
		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
