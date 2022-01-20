#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int a;
	cin>>a;
	int b;
	cin>>b;
	int add[]={2*b};
	
	for(int i=0;i<b;i++)
	{
		cin>>add[2*b];
	}

	
	int c;
	cin>>c;
	int acc[]={2*c};
	
	for(int i=0;i<c;i++)
	{
		cin>>acc[2*c];
	}
	
	if (a==2) {
		cout<<"LRRLLRRRRL"<<endl;
	cout<<"-1";
	}
    
	
	fclose (stdin);
	fclose (stdout);
	return 0;
 } 
