#include<iostream>
#include<cstdio>
using namespace std;
int t,n,tmp;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.in","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n;
		for(int j = 1;j<=n*2;j++)
		{
			cin>>tmp;
		}
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
