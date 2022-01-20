#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
long int n,m1,m2,t;
long int f[100001];
long int ans;
long int mas;
long int tu=100000001;
long int bian;
long int nova;
void num(long int k,long int j,long int b,long int t);
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	long int d1[m1+1],d2[m2+1];
	long int z1[m1+1],z2[m2+1];
	for(long int i=1;i<=m1;i++)
	   	    {
	   	    	cin>>d1[i]>>z1[i];
			   }
	for(long int i=1;i<=m2;i++)
	   	    {
	   	    	cin>>d2[i]>>z2[i];
	   	    	}
    for(long int i=1;i<=m1;i++)
	   {for(long int j=t+1;j<=m1;j++)
	      {
	      	if(d1[j]<tu)
	      	{tu=min(tu,d1[j]);
		     nova=j;}}
		bian=d1[nova];
		d1[nova]=d1[i];
		d1[i]=bian;
		bian=z1[nova];
		z1[nova]=z1[i];
		z1[i]=bian;
		tu=100000001;}
	for(long int i=1;i<=m2;i++)
	   {for(long int j=t+1;j<=m2;j++)
	      {
	      	if(d2[j]<tu)
	      	{tu=min(tu,d1[j]);
		     nova=j;}
		  }
		bian=d2[nova];
		d2[nova]=d2[i];
		d2[i]=bian;
		bian=z2[nova];
		z2[nova]=z2[i];
		z2[i]=bian;
		tu=100000001;}
	for(t=0;t<=n;t++)
	   {
	   	 
	   	 for(long int i=1;i<=m1;i++)
	   	    {
	   	    	num(d1[i],z1[i],1,t);
			   }
		 for(long int i=1;i<=m2;i++)
	   	    {
	   	    	num(d2[i],z2[i],t+1,n);
			   }
		 mas=max(mas,ans);
		 ans=0;
		 
		 
	   } 
	cout<<mas;
	return 0;
}
void num(long int k,long int j,long int b,long int a)
{
	for(long int i=b;i<=a;i++)
	   {if(k>f[i])
	     {f[i]=j;
		 ans+=1;
		 //break;
		 continue;
		 }
	   else
	     continue;}
		
}
