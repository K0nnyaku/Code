#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,f1=0,f2=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		int a1,b1,c1=0,d1=0;
		cin>>a1>>b1>>f1;
		a1=c1;
		b1=d1;
		if(c1>b1)
		{
			f1+=1;
		}
	}
	for(int j=1;j<=m2 - 3;j++)
	{
		int a2,b2,c2=0,d2=0;
		cin>>a2>>b2>>f2;
		a2=c2;
		b2=d2;
		if(c2<b2){
		f2+=1;
		}
	}
	int sum=f1+f2;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
