#include<bits/stdc++.h>
using namespace std;
int gnd[10001],gnl[10001];
int gwd[10001],gwl[10001];
int f[1001];
int sy[1001],se[1001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,i,j,k,gn,gw;
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++)
	{
		scanf("%d%d",&gnd[i],&gnl[i]);
	}
	for(i=1;i<=m2;i++)
	{
		scanf("%d%d",&gwd[i],&gwl[i]);
	}
	memset(sy,0,sizeof(sy));
	memset(se,0,sizeof(se));
	gn=0;
	gw=n;
	for(i=0;i<=n;i++)
	{
	    for(j=1;j<=m1;j++)
	    {
	    	if(gn==0) sy[j]+=0;
	  	      else
	  	      {
	  	        sy[j]+=1;
	  	        gn--;
	  	    	if(gnd[j]>min(gnl[j],gnl[j-1])||gn!=0)
	  	    	{
	  	    		gn++;
	  	    		sy[j]+=1;
	  	    		gn--;
				}
			  }
		}
		for(k=1;k<=m2;k++)
		{
			if(gw==0) se[k]+=0;
			  else
			  {
			  	se[k]+=1;
			  	gw--;
			  	if(gwd[k]>min(gwl[k],gwl[k-1])||gw!=0)
			  	{
			  		gw++;
			  		se[k]+=1;
			  		gw--;
				}
			  }
		}
		gn++;
		gw--;
		f[i]=max(sy[j]+se[k],sy[j-1]+se[k-1]);
	}
	printf("%d",f[n]);
	return 0;
}
