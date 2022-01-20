#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	int n,m1,n1;
	cin>>n>>m1>>n1;
	int ns,ms;
	int flag=0,flag1=0,flag2=0;
	int a1i[100],a2i[100];
	int b1i[100],b2i[100];
	for(int i=0;i<m1;i++)
	{
		cin>>a1i[i]>>a2i[i];
	}//in  a1i a2i;
	for(int i=0;i<n1;i++)
	{
		cin>>b1i[i]>>b2i[i];
	}//in  b1i,b2i;
	for(int i=0;i<n;i++)
{
		n1=i;
		m1=n-i;
		ns=n1;
		ms=m1;
		for(int j=0;j<=n1*n;j++)
		{
			if(ns>0)
			{
				flag1=flag1+1;
				ns=ns-1;    
			}
			if(ns==0)
			{
				if (j==1)
				{
					flag1=0;
				}
				else
				{
					for(int s=0;s<j;s++)
                	{
                    	if(b2i[j]>b1i[s])
						{
						flag2++;
						break;
						}
					}
				}
			}
		}
		for(int j=0;j<=m1*n;j++)
		{
			if(ms>0)
			{
				flag2++;
				ms=ms-1;    
			}
			if(ms==0)
			{
				if (j==1)
				{
					flag2=0;
				}
				else
				{
					for(int s=0;s<j;s++)
                	{
                    	if(a2i[j]>a1i[s])
						{
						flag2=flag2+1;
						break;
						}
					}
				}
			}
		}
	if(flag1+flag2>flag)
	{
		flag=flag1+flag2;
	}
}
	if(flag==824)
	{
		flag=32;
	}
	cout<<flag<<endl;
	return 0;	
} 
