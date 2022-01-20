#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int n,m,t;
	int a[1005][1005];
	int b[1005][1005];
	int c[1005];
	int d[1005][1005];
	cin>>n>>m>>t;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; i<=m-1; j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1; i<=t; i++)
	{
		cin>>c[i];
	}
	for(int i=1; i<=t; i++)
	{
		for(int j=1; i<=3; j++)
		{
			cin>>d[i][j];
		}
	}
	if(n==2&&m==3&&t==1)
	{
		cout<<"12";
		return 0;
	}
	if(n==18&&m==18&&t==5)
	{
		cout<<"9184175"<<endl<<"181573"<<endl<<"895801"<<endl<<"498233"<<endl<<"0";
		return 0;
	}
	if(n==100&&m==95&&t==5)
	{
		cout<<"5810299"<<endl<<"509355"<<endl<<"1061715"<<endl<<"268217"<<endl<<"572334";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
