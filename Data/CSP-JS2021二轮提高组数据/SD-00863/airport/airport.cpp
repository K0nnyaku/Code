#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c[100001],d[100001],c1[100001],d1[100001],k1[100001],k2[100001];
//freopen("airport.in",r,stdin);
//freopen("airport.out",w,stdout);
int main()
{
	
	int n,m1,m2,a,b,a1,b1,k=0,kmax;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a,&b);
		c[i]=a;d[i]=b;
	}
		for(int l=0;l<=n;l++)
		{
			
			for(int i=1;i<=m1;i++)
			{
				for (int j=1;j<=l;j++)
				{
					if(i<=l)
					{
						k++;
						break;	
					}
					
					else if((c[i]>=d[j])&&(l!=0))
					{
						c[j]=c[i];d[j]=d[i];
						k++;
						break;
					}
				}
					
			}
			k1[l]=k;
				k=0;	
		}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a1,&b1);
		c1[i]=a1;d1[i]=b1;
	}	
	for(int l=0;l<=n;l++)
		{
			for(int i=1;i<=m2;i++)
			{
				for (int j=1;j<=n-l;j++)
				{
					if(i<=n-l)
					{
						k++;
						break;	
					}
					else if((c1[i]>=d1[j])&&(l!=n))
					{
						c1[j]=c1[i];d1[j]=d1[i];
						k++;
						break;
					}
				}
			}
			k2[l]=k;
			k=0;	
		}
	for(int l=0;l<=n;l++)
	{
		k=k1[l]+k2[l];
		if (k>kmax)
		{
			kmax=k;
		}
	}
	cout<<kmax;
	return 0;
}
