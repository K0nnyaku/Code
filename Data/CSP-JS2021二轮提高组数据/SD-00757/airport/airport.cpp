#include<cstdio>
#include<iostream>
#include<fstream>
const int N=1e9;
using namespace std;
int main()
{
	int n, m1,m2,a1[10010],a2[10010],b1[10010],b2[10010],c1[10010],c2[10010],d1[10010],d2[10010],a,z,b,sum1=0,sum2=0,ans=0;
	freopen("airport.in","r",stdin);
	cin>>n>>m1>>m2;
	//排序 
	for(int i=0;i<=m1-1;i++)
	{
		cin>>a1[i]>>b1[i];
		c1[i]=a1[i];d1[i]=b1[i];
	}
	for(int i=0;i<=m2-1;i++)	
	{
		cin>>a2[i]>>b2[i];
		c2[i]=a2[i];d2[i]=b2[i];
	}
	for(int i=0;i<=m1-1;i++)
	{
		for(int j=0;j<=m1-2;j++)
		{
			if(a1[j]>a1[j+1])
			{
				z=a1[j];a1[j]=a1[j+1];a1[j+1]=z;
				z=b1[j];b1[j]=b1[j+1];b1[j+1]=z;
			}
		}	
	}
	for(int i=0;i<=m2-1;i++)
	{
		for(int j=0;j<=m2-2;j++)
		{
			if(a2[j]>a2[j+1])
			{
				z=a2[j];a2[j]=a2[j+1];a2[j+1]=z;
				z=b2[j];b2[j]=b2[j+1];b2[j+1]=z;
			}
		}	
	}	
	int x1=m1,x2=m2;
	for(int i=0;i<=n;i)
	{
		a=i;b=n-i;
		if(i==0) sum1=1;
		else if(i==n) sum2=1;
		if(!sum1)//国内 
		{
			
			sum1=1;
			for(int j=1;j<=m1-1;j++)
			{
				//cout<<"j"<<j<<endl;
				for(int k=j-1;k>=0;k--)
				{
					if(a1[j]>=b1[k] && b1[k]!=0) 
					{
						//cout<<"iii";
						b1[k]=0;
						a++;//cout<<"a"<<a<<endl;	
					}
				}
				if(a-1==0)
				{
					for(int k=j;k<=m1-2;k++)
					{
						a1[k]=a1[k+1];
						b1[k]=b1[k+1];
					}
					m1--;j--;//cout<<"m1"<<m1<<endl;cout<<"j"<<j<<endl;
				}
				else
				{
					sum1++;//cout<<"sum1"<<sum1<<endl;
					a--;//cout<<"a"<<a<<endl;
				}
			
			}
		}
		else sum1=0;
		//cout<<"sum1"<<sum1<<endl;
		if(!sum2)//国外 
		{
			
			sum2=1;
			for(int j=1;j<=m2-1;j++)
			{
				for(int k=j-1;k>=0;k--)
				{
					if(a2[j]>=b2[k] && b2[k]!=0) 
					{
						b2[k]=0;
						b++;	
					}
				}
				if(b-1==0)
				{
					for(int k=j;k<=m2-2;k++)
					{
						a2[k]=a2[k+1];
						b2[k]=b2[k+1];
					}
					m2--;j--;
				}
				else
				{
					sum2++;
					b--;
				}
			
			}
		}
		else sum2=0;
		//cout<<x1<<" "<<m1<<" "<<x2<<" "<<m2<<" "<<sum1<<" "<<sum2<<" "<<sum1+sum2<<endl;
		if(ans<sum1+sum2) ans=sum1+sum2;
		//cout<<sum1+sum2;
		sum1=0;sum2=0;i=i+1;//cout<<"i"<<i<<endl;	
		m2=x2;m1=x1;
	for(int s=0;s<=m1-1;s++)
	{
		
		a1[s]=c1[s];b1[s]=d1[s];
	}
	for(int s=0;s<=m2-1;s++)	
	{
		
		a2[s]=c2[s];b2[s]=d2[s];
	}
	}
	freopen("airport.out","w",stdout);
	cout<<ans;
	
		//for(int i=0;i<=m1-1;i++)cout<<a1[i]<<" "<<b1[i]<<endl;
		//cout<<endl;
		//	for(int i=0;i<=m2-1;i++)cout<<a2[i]<<" "<<b2[i]<<endl;
	
	

	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
