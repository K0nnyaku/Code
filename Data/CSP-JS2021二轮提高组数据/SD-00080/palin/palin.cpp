#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
long long a[10001],b[10001],c[10001]={0};
int main()
{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	long long T,n,cnt1=0,c1=0;
	bool cnt=0;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int j=1;j<=2*n;j++)
		cin>>a[j];
		for(int j=1;j<=2*n;j++)
		{
			if(cnt==0)
			b[j]=a[j];
			if(cnt==1)
			{
				for(int y=1;y<=j-1;y++)
				cnt1=cnt1+c[y];
				b[j]=a[2*n-cnt1];
				c[j]=1;
				cnt=0;
			}
			if(j<=n)
			{
				for(int x=1;x<=j-1;x++)
				  if(b[j]==b[x]) 
				  {
				 	   cnt=1;
					   j=j-1; 
					   break;
				  }
			}
			if(j>n) 
			{
				if(b[j]!=b[2*n-j+1]&&a[2*n-cnt1]!=b[2*n-j+1])
				{
					cnt=1;
					if(c[2*n-j]==1) 
					{
						for(int y=2*n-j-2;y<=2*n;y++)
						c[y]=0;
						j=2*n-j-2;
					}
					else
					{
						for(int y=2*n-j;y<=2*n;y++)
						c[y]=0;
						j=2*n-j;
					}
				}
			}
		}
	}
	cout<<endl;
	for(int i=1;i<=2*n;i++)
	cout<<b[i]<<" ";
	fclose(stdin);fclose(stdout);
	return 0;
} 
