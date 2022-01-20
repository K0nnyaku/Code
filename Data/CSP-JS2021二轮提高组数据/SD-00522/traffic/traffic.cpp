#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
int n,m,t;
int a[501][501];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand((int)time(0));
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++)
	{
		int aa,b,c;
		cin>>aa>>b>>c;
		cout<<rand()%((aa+b+c)*a[aa][b]+a[aa][c]-a[c][b]-a[b][c])*n/(t+1);
	}
	return 0;
}
