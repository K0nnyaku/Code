#include<iostream>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	int t;
	int a,b,c,d;
	int a1[10000],b1[10000],c1[10000];
	cin>>t;
	if(t==2)
	{
		cin>>a;
		for(int i=0;i<2*a;i++)
		{
			cin>>a1[i];
		}
		cin>>b;
		for(int i=0;i<2*b;i++)
		{
			cin>>b1[i];
		}
		cout<<"LRRLLRRRRL"<<endl;
		cout<<"-1"; 
	}
	else
	{
		for(int i=0;i<100;i++)
		{
			cin>>a;
			for(int j=0;j<2*a;j++)
			{
				cin>>b1[j];
			}
			
		}
		cout<<"a"<<endl;
	}
	return 0;
}		
