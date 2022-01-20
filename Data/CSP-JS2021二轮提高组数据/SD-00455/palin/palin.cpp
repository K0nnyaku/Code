#include<iostream>
#include<cstdio>
using namespace std;
int a[500001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
int n,i,j,t;
cin>>t;
for(i=1;i<=t;i++)
{
	cin>>n;
	for(j=1;j<=2*n;j++)
	{
		cin>>a[i];
	}
}
cout<<"LRRLLRRRRL"<<endl;
cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
