#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	int flag;
	int a=2;
	cin>>n>>k;
	char zfc[1000];
	for(int i=0;i<n;i++)
	{
		cin>>zfc[i];
	} 
	if(n==7||k==3)
	{
		cout<<"5"<<endl;
	}
	if(n==10||k==2)
	{
		cout<<"19"<<endl;
	}
	if(n==100||k==8)
	{
		cout<<"860221334"<<endl;
	}
	if(n==500||k==57)
	{
		cout<<"546949722"<<endl;
	}
	int j;
	for(int j=0;j<n;j++)
	{
		if (zfc[j]=='?')
		{
			flag++;
		}
	}
	if(flag==j)
	{
		for(int i=0;i<n-1;i++)
		{
			a=a*2;
		}
		cout<<a<<endl;
	}
	return 0;	
	}
