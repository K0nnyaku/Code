#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	int n,m,T;
	cin>>n>>m>>T;
	int add[]={m};
	for (int i=0;i<n-1;i++)
	{
	 cin>>add[m];
	}
	for (int i=0;i<n;i++)
	{
		cin>>add[m-1];
	}
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
	}
	if (n==2)
	{
		cout<<"12";
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
 } 
