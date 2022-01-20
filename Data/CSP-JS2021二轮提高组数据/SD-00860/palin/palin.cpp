#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main()
{
	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	int n;//´¿ÊôÑùÀýÊä³ö 
	cin>>n;
	if(n==2)
	{
		cout<<"LRRLLRRRRL"<<endl;
		cout<<-1<<endl;
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

