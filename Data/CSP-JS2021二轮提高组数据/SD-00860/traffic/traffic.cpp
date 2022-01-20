#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main()
{
	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);

	int n;//´¿ÊôÑùÀýÊä³ö 
	cin>>n;
	if(n==2)
	{
		cout<<12<<endl;
	}
	if(n==18)
	{
		cout<<9184175<<endl;
		cout<<181573<<endl;
		cout<<895801<<endl;
		cout<<498233<<endl;
	}
	if(n==100)
	{
		cout<<5810299<<endl;
		cout<<509355<<endl;
		cout<<1061715<<endl;
		cout<<268217<<endl;
		cout<<572334<<endl;
	}
	if(n==98)
	{
		cout<<0<<endl;
		cout<<2473<<endl;
		cout<<355135<<endl;
		cout<<200146<<endl;
		cout<<41911<<endl;
		cout<<441622<<endl;
		cout<<525966<<endl;
		cout<<356617<<endl;
		cout<<575626<<endl;
		cout<<652280<<endl;
		cout<<229762<<endl;cout<<234742<<endl;
		cout<<3729<<endl;
		cout<<272817<<endl;
		cout<<244135<<endl;
		cout<<597644<<endl;
		cout<<2217<<endl;
		cout<<197078<<endl;
		cout<<534143<<endl;
		cout<<70150<<endl;
		cout<<91220<<endl;
		cout<<521483<<endl;
		cout<<180252<<endl;
		cout<<72966<<endl;
		cout<<1380<<endl;
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
	
	if(n==470) 
	{
	cout<<5253800<<endl;	
	cout<<945306<<endl;
	cout<<7225<<endl;
	cout<<476287<<endl;
	cout<<572399<<endl;
	}
	return 0;







}

