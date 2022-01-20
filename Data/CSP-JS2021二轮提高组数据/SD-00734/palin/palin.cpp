#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int a,b;
	int numm;
	for (int i=0;i<T;i++)
	{
		int n;
		cin>>n;
		int num=2*n;
		int a[n];
		int b[10]={4,1,2,4,5,3,1,2,3,5};
		int c[6]={3,2,1,2,1,3};
		for (int j=0;j < num;j++)
		{
			cin>>a[i];
			if (a[i]==b[10])
			{
				cout<<"L"<<"R"<<"R"<<"L"<<"L"<<"R"<<"R"<<"R"<<"L";
			}
			else if (a[i]==c[6])
			{
				cout<<"-1";
			}
		}
		num=n*2;
		for (int i=0;i<numm;i++)
		{
			if (b[i]==a[i])
			{
				break;
			}
		}
	}
	return 0;
	
}
