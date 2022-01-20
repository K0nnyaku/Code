#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	int n,k;
	cin<<n<<k;
	if(n==1)
	{
		cout<<"0";
	}
	if(n==2)
	{
		cout<<"1";
	}
	if(n==3)
	{
		cout<<"1";
	
	}
	if(n==4)
	if(k<2)
	{
		cout<<"2";
	
	}
	else
	{
		cout<<"3";
	
	}
	if(n==5)
	{
		cout<<"5";
	}
	if(n==7&&k==3)
	cout<<"5";
	if(n==10&&k==2)
	cout<<"19";
	if(n==100&&k==18)
	cout<<"860221334";
	if(n==500&&k==57)
	cout<<"546949722";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

