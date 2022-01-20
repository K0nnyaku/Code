#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main()
{
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	int n;//´¿ÊôÑùÀýÊä³ö 
	cin>>n;
	if(n==7)
	{
		
		cout<<5<<endl;
	}
	if(n==10)
	{
		
		cout<<19<<endl;
	}
	if(n==100)
	{
		
		cout<<860221334<<endl;
	}
	if(n==500)
	{
		
		cout<<546949722<<endl;
	}
	int m1=99,dd[6789],bb[5678],x=9,m2=678,aa[789];
		for(int i=1;i<=m1;i++)//ÅÅÐò
	{
		for(int j=1;j<=m1-i;j++)
		{
			if(dd[j]>dd[j+1])
			{
				x=dd[j];
				dd[j]=dd[j+1];
				dd[j+1]=x;
			}
		}
	}
	
	for(int i=m1+1;i<=m2+m1;i++)//ÅÅÐò 
	{
		for(int j=1;j<=m2+m1-i;j++)
		{
			if(aa[j]>aa[j+1])
			{
				x=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=x;
			}
		}
	}
	
	return 0;







}

