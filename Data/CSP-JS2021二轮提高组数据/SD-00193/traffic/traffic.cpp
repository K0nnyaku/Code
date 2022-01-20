#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int n,m,T,p;
int e1[1001][1001],e2[1001][1001],f1[1001][1001];
int a,b,c,d,e,f,g,ans=999999999;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int k=1;k<=T;k++)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int x;
				scanf("%d",&x);
				e1[i][j]=x;
			}
		}
		for(int i=1;i<=m-1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x;
				scanf("%d",&x);
				e2[i][j]=x;
			}
		}
		scanf("%d",&p);
		cin>>a>>b>>c;
		cin>>e>>f>>g;
		if((b==m&&f==m+1)||(b==m+n&&f==m+n+1)||(b==2*m+n&&f==2*m+n+1)||(b==2*m+2*n&&f==1)) ans=0;
		swap(b,f);
		if((b==m&&f==m+1)||(b==m+n&&f==m+n+1)||(b==2*m+n&&f==2*m+n+1)||(b==2*m+2*n&&f==1)) ans=0;
		swap(b,f);
		ans=a+e;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f1[i][j]=min(f1[i-1][j]+e1[i-1][j],f1[i][j-1]+e2[i][j-1]);
			}
		}
		ans=min(f1[n][m],ans);
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
