#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m,k;
int e1[505][505],e2[505][505];
int color[505][505];

struct points{
	int x,p,t;
} a[505];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	int T;
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&e1[i][j]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			scanf("%d",&e2[i][j]);
	
	while(T--)
	{
		scanf("%d",&k);
		for(int i=1; i<=m; ++i)
			e1[0][i]=e1[n][i]=0;
		for(int i=1; i<=n; ++i)
			e2[i][0]=e2[i][m]=0;
		memset(color,0,sizeof(color));
		
		for(int i=1; i<=k; ++i){
			scanf("%d%d%d",&a[i].x,&a[i].p,&a[i].t);
			int p=a[i].p;
			if(p<=m) e1[0][p]=a[i].x,color[0][p]=a[i].t+1;
			else if(a[i].p<=m+n) e2[p-m][m]=a[i].x,color[p-m][m]=a[i].t+1;
			else if(a[i].p<=2*m+n) e1[n][m+1-(p-m-n)]=a[i].x,color[n][m+1-(p-m-n)]=a[i].t+1;
			else e2[2*m+2*n-p+1][0]=a[i].x,color[2*m+2*n-p+1][0]=a[i].t+1;
		}
		
		int kk=(1<<(n*m)),ans=199999999;
		for(int i=0; i<kk; ++i)
		{
			for(int j=1; j<=n; ++j)
				for(int k=1; k<=m; ++k)
					color[j][k]=((i & (1<<((j-1)*m+k-1)))!=0) + 1;
			int sum=0;
			for(int j=1; j<=n+1; ++j)
			{
				for(int k=1; k<=m+1; ++k)
				{
					if(color[j][k]!=color[j-1][k] && color[j-1][k]!=0) sum+=e1[j-1][k];
					if(color[j][k]!=color[j][k-1] && color[j][k-1]!=0) sum+=e2[j][k-1];
				}
			}
			if(sum<ans) ans=sum;
		}
		
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
