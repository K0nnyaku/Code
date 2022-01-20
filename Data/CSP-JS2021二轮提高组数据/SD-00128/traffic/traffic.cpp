#include<bits/stdc++.h>
using namespace std;
long long sh[510][510],hh[510][510],ls[100][4],z[1000000];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,zz=0;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n-1;i++)
	  for(int j=1;j<=m;j++)
	  {
	    scanf("%d",&sh[i][j]);
	    z[++zz]=sh[i][j];
	  }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m-1;j++)
	  {
	    scanf("%d",&hh[i][j]);
	    z[++zz]=hh[i][j];
	  }
	sort(z+1,z+zz);
	for(int i=1;i<=t;i++)
	{
		int zs,ds;
		long long zc=0;
		for(int i=1;i<=zs;i++)
		  zc=zc+z[i];
		cout<<zc<<endl;
	}
	return 0;
}
