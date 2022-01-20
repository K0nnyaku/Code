#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long int n,q,a[100009],x,v,y=0,z[100009],w[100009],w1,x1=1;
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=q;k++)
	{
		for(int i=1;i<=n;i++)
		{
			z[i]=a[i];
		 } 
		cin>>y;
		if(y==1)
		{
			x1=1;
			cin>>x>>v;
			a[x]=v;
			for(int i=1;i<=n;i++)
		{
			z[i]=a[i];
		 } 
		}
		if(y==2)
		{
			cin>>x;
			if(x1==1)
			{
				for(int i=1;i<=n;i++)
			{
				w[i]=i;
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=i;j>=2;j--)
			{
			if(z[j]<z[j-1])
			{
				int t=z[j-1];
				z[j-1]=z[j];
				z[j]=t;
				w1=w[j];
				w[j]=w[j-1];
				w[j-1]=w1;
			}
			}
		}
			}
			
		for(int i=1;i<=n;i++)
			{
				if(w[i]==x)
				{
					cout<<i<<endl;
					break;
				}
			}
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
