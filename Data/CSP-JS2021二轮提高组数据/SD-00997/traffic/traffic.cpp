#include<bits/stdc++.h>
using namespace std;
const int N=2510;
int t,n,ans;
long long a[N][N],d[N][N];
int traffic()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
	freopen("traffic.in ","r","stdin");
	freopen("traffic.out ","w","stdout");
	scanf("%d%d",&t,&n);
	int i,j;
	for(int i=1;i<=t;i++)
	{
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=2*n;j++)
			{
				scanf("%d",&a[i][j]);
		 		traffic();
			 	ans=d[i][j];
			} 
		printf("%d",&ans);	 	
	}
	return 0;
}
