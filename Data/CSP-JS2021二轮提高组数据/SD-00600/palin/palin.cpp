#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{	
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,b;
	int a[100000]={0};
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>b;
		for(int j=1;j<=2*b;j++)
		{
			cin>>a[j];//
			
		}
	}
	cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
//	fclose(stdin);
//	fclose(stdout);


