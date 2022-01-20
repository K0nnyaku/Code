#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,na,nb,am,bm,atb[10001],btb[10001],atl[10001],btl[10001],x[50000][10000],maax,zhi,zhia,zhib,flag,re,mark[10001];
int jsa(int e,int d)
{
	flag=re=0;
	for(int i=0;i<e;i++)
	    for(int z=0;z<d;z++)
	        if(x[z][atb[i]]==0)
	          {
	          	mark[i]=z;
				re++;
		        for(int j=atb[i];j<=atl[i];j++)
		            x[z][j]=1;
		        break;
			  }
	if(re!=0)
	{
		for(int i=0;i<e;i++)
		    for(int j=atb[i];j<=atl[i];j++)
		        x[mark[i]][j]=0;
	} 
    return re;
}
int jsb(int e,int d)
{
	flag=re=0;
	for(int i=0;i<e;i++)
	    for(int z=0;z<d;z++)
	        if(x[z][atb[i]]==0)
	          {
	          	mark[i]=z;
				re++;
		        for(int j=btb[i];j<=btl[i];j++)
		            x[z][j]=1;
		        break;
			  }
	if(re!=0)
	{
		for(int i=0;i<e;i++)
		    for(int j=btb[i];j<=btl[i];j++)
		        x[mark[i]][j]=0;
	} 
    return re;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&am,&bm);
	for(int i=0;i<am;i++)
	    scanf("%d%d",&atb[i],&atl[i]);
	for(int i=0;i<bm;i++) 
		scanf("%d%d",&btb[i],&btl[i]);
	na=n;nb=0;maax=-1;
	while(na>0)
	{
		zhia=jsa(am,na);
		zhib=jsb(bm,nb);
		zhi=zhia+zhib;
		if(zhi>maax)
		  maax=zhi;
		na--;nb++; 
	}
	printf("%d",maax);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
