#include<iostream>
#include<cstdio>
using namespace std;
long long  i,s,a[10001],b[10001],a1[10001],b1[10001],n,m1,m2,j,k;
long long  c[10001],c1[10001],ans1,ans2,ans3,l,d,d1;
int main()
{
 	freopen("airport.in","r",stdin);
 	freopen("airport.out","w",stdout);
    cin>>n>>m1>>m2;
	for(i=0;i<m1;i++)
	{
		cin>>a[i]>>a1[i];
	} 
    for(i=0;i<m2;i++)
    {
    	cin>>b[i]>>b1[i];
	}
	for(i=0;i<=n;i++)
	{
		for(j=n;j>=0;j--)
		{
			if(i+j==n)
			{
				c[k]=i;
				c1[k]=j;
				k++;
			}
		}
	} 
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++) 
		{
			if(c[l]==0) 
			{
				ans1=0;
			}
			 if(a[i]>=a1[j]&&c[l]>0) 
			{
				ans1++;
			}
			else if(a[i]<a1[j]&&c[l]>0)
			{
				
				if(c[l]>0)
				{
					ans1++;
					if(ans1>d)
					{
						d=ans1;
					}
					c[l]--;
				}
			}
		   if(l<n)
		  {
		  	l++;
		  }
		}
	}
    l=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(c1[l]==0) 
			{
					ans2=0;
			}
			if(b[i]>=b1[j]) 
			{
				ans2++;
			}
			else if(b[i]<b1[j]&&c[l]>0) 
			{
				 if(c1[l]>0)
				{
					ans2++;
					if(ans2>d1)
					{
						d1=ans2;
					}
					c1[l]--;
				}
			}
			if(l<n)
		  {
		  	l++;
		  }
	    }
	}
	
   cout<<d+d1;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
} 
