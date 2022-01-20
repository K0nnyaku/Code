#include<bits/stdc++.h>
using namespace std;
int n,m,T,ans;
int f[10][10][2],g[10][10][2];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>f[i][j][0],f[i][j][1]=f[i][j][0];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<m;j++)
	  cin>>g[i][j][0],g[i][j][1]=g[i][j][0];
	while(T--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a=>1&&a<=m)
			  f[0][a][c]=g[0][a][c]=b;
			if(a>=m&&a<=m+n)
			  f[a-m][m+1][c]=g[a-m][m+1][c]=b;
			if(a>=m+n&&a<=2*m+n)
			  f[n+1][m-(a-m+n)+1][c]=g[n+1][m-(a-m+n)+1][c]=b;
			if(a>=2*m+n+1)
			   f[n-(a-2*m+n)+1][0][c]=g[n-(a-2*m+n)+1][0][c]=b;
		}
		for(int i=0;i<=n;i++)
		 for(int j=0;j<=m;j++)
		  {
		  	  f[i][j][0]=f[i-1][j][1]+f[i][j+1][1];
		  	  f[i][j][1]=f[i-1][j][0]+f[i][j-1][1];
		  }
		  cout<<ans<<endl;
	}
	return 0;
}
	return 0;
}
