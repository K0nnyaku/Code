#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k,a[1005],vis[1005];
long double mul[1005][1005],p[1005],f[1005];
int main()
{
	freopen("unlock.in","r",stdin); 
	freopen("unlock.out","w",stdout); 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n+1;i++)
			f[i]=0;
		for(int i=0;i<n;i++)
			p[i]=1.0*(n-k-i)/(n-i);
		for(int i=0;i<=n;i++)
		{
			mul[i][i]=1;
			for(int j=i+1;j<=n;j++)
			{
				mul[i][j]=mul[i][j-1]*p[j-1];
			}
		}
		f[0]=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				int u=i,ct=0;
				while(!vis[u])
				{
					vis[u]=1;
					ct++;
					u=a[u];
				}
				for(int j=n;j>=ct;j--)
				{
					f[j]-=f[j-ct]*mul[j-ct][j];
				}
			}
		long double ans=0;
		for(int i=0;i<=n;i++)
		{
		//	printf("%f ",f[i]);
			ans+=f[i];
		}
	//	printf("\n");
		printf("%.10f\n",(double)ans); 
	}
	return 0; 
}
