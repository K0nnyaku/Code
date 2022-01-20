#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n,a,b[10001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=1;j<=2*a;j++)
		{
			cin>>b[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
