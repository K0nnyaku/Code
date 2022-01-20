#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>" ">>m1>>" ">>m2>>endl;
	int a1,b1;
	int a2,b2;
	cin>>a1>>" ">>b1>>endl;
	cin>>a2>>" ">>b2>>endl;
	int i1,i2;
	i1=++i1,i1<=m1;
	i2=++i2,i2<=m2,i2>i1;
	int d;
	d=1;
	if(a1>=b1 )
	{
		d=d+1;
	}
	else;
	{
		d=d;
	}
	int c;
	c=1;
	if(a2>=b2)
	{
		c=c+1;
	}
	else
	{
		c=c;
	}
	int t;
	t=d+c;
	cout<<t<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
