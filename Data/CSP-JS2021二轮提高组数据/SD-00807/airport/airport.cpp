#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,b1max,b2max,szhi=0,shu,shu01,shu02,lqg;
	scanf("%d %d %d",&n,&m1,&m2);
	int m=m1+m2;
	int a1[m1],a11[m1],b1[m1],b11[m1],a2[m],a22[m],b2[m],b22[m];
	for(int z1=1;z1<=m1;z1++)
	{
		scanf("%d %d",&a1[z1],&b1[z1]);
	}
	for(int z2=m1+1;z2<=m;z2++)
	{
		scanf("%d %d",&a2[z2],&b2[z2]);
	}
	b1max=0;
	for(int bijiao1=1;bijiao1<=m1;bijiao1++)
	{
		if(b1[bijiao1]>b1max)
		{
			b1max=b1[bijiao1];
		}
	}
	b2max=0;
	for(int bijiao2=m1+1;bijiao2<=m;bijiao2++)
	{
		if(b2[bijiao2]>b2max)
		{
			b2max=b2[bijiao2];
		}
	}
	for(int lq=0;lq<=n;lq++)
	{
		shu01=0;
		for(int z33=1;z33<=m1;z33++)
	    {
		a11[z33]=a1[z33];
		b11[z33]=b1[z33];
	    }
		for(int time=1;time<=b1max;time++)
		{
			for(int z3=1;z3<=m1;z3++)
			{			
			    if(a11[z3]==time&&lq==0)
			    {
			    	b11[z3]=0;
				}
				if(a11[z3]==time&&lq>0)
			    {
			    	shu01++;
			    	lq=lq-1;
			    }
			    if(b11[z3]==time)
			    {
			    	lq=lq+1;
			    }
		    }
		}
		shu02=0;
		lqg=0;
		lqg=n-lq;
		for(int z44=m1+1;z44<=m;z44++)
	    {
		a22[z44]=a2[z44];
		b22[z44]=b2[z44];
	    }
	    for(int time=1;time<=b2max;time++)
		{
			for(int z4=m1+1;z4<=m;z4++)
			{			
			    if(a22[z4]==time&&lqg==0)
			    {
			    	b22[z4]=0;
				}
				if(a22[z4]==time&&lqg>0)
			    {
			    	shu02++;
			    	lqg=lqg-1;
			    }
			    if(b22[z4]==time)
			    {
			    	lqg=lqg+1;
			    }
		    }
		}
		shu=shu01+shu02;
		if(shu>szhi)
		{
			szhi=shu;
		}
	}
	printf("%d",szhi);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
