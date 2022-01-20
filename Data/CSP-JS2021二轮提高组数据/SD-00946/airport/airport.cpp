#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
int d[100000];
int x,y;
int f1=0,f2=0;
int k,e,r;
int s[100000];
int p[100000];
int maxn;
int g[100000];
int h[100000];

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i]>>b[i];		
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>c[i]>>d[i];
		if(i==m2) break;
	}
	x=0;
	y=n-x;
	for(int v=0;v<=n+1;v++)
	{   if(y>=0&&x>=0)
		{
	
		f1=1;
		e=1;
		for(int i=1;i<=m1;i++)
		{    if(x!=0)
			{   
			   
				int j=i+1;
				  
				 if(b[i]<a[j])
				      {
					    f1++;
					    g[i]=1;
				      }
				      else
					  {
						  if(e<x)
						    {
							f1++;e++;}
						  else for(int l=i;l>0;l--)
						  {
						  	if(b[l]<a[j]&&g[l]==0)
						  	{
							  f1++;g[i]=1;break;}
							  else continue;
						  }
					  }
			    
	        }else f1=0;
	   }	
		
		k=0;
		s[v]=f1;
		 
		f2=1;
		r=1;
		for(int i=1;i<=m2;i++)
		{    if(y!=0)
			{ 
			    
			    int j=i+1;
	
				      if(d[i]<a[j])
				      {
					    f2++;
						h[i]=1;
				      }
				      else
					  {
					    if(r<y)
					     {
						 f2++;r++;}
						 else for(int l=i;l>0;l--)
						  {
						  	if(d[l]<c[j]&&h[l]==0)
						  	{
							  f2++;h[i]=1;break;}
							  else continue;
						  }
					   
					  }
				  
				  
			}
			else f2=0; 
		}
		p[v]=f2;
		
		x++;
		y--;
		e=0;
		r=0;
		k=0;
		f1=0;
		f2=0;	}
		else break;
	}
	s[1]-=1;
	
	for(int i=0;i<=n+1;i++)
	{
		int u=s[i]+p[i];
		if(u>maxn) maxn=u;
	}
	cout<<maxn;	
	return 0;
	 
}
