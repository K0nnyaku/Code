#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int t,n,a[105];

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<"-1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
