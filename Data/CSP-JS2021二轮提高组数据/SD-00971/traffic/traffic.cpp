#include<cstdio>
#include<iostream>
using namespace std;
int f[10005][10005][5],y=0;
int k[10005],x[100005],r[100005],c[100005];
int ans=1e9;
int main()
{
   freopen("traffic.in","r",stdin);
   freopen("traffic.out","w",stdout);
   int n,m,t;
   scanf("%d %d %d",&n,&m,&t);
   for(int i=1;i<n;i++)
      for(int j=1;j<=m;j++)
      {
      	scanf("%d",&f[i][j][2]) ;
		f[i+1][j][4]=f[i][j][2];
	  }
    for(int i=1;i<=n;i++)
      for(int j=1;j<m;j++)
      {
      	scanf("%d",&f[i][j][3]) ;
		f[i][j][1]=f[i][j][3];
	  }
   for(int i=1;i<=t;i++)
   {
   	scanf("%d",&k[i]);
   	for(int j=1;j<=k[i];j++)
   	    scanf("%d",&x[i],&r[i],&c[i]);
   	int x2=max(k[1],k[2]);
	int x1=min(k[1],k[2]);
	int ans=1e9;
	for(int i=x1;i<=x2;i++)
	{
		int y=i-m,z=m-i+m+n,xx=0;
		while(y!=0&&z!=0)
			xx=min(f[y--][z][3],f[y][z++][2]);
		ans=min(ans,xx);	
	}     
   }
   printf("%d",ans);
   fclose(stdin);
   fclose(stdout);
   return 0;
}

