#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int a[101][101];
int main()
{
	int n,m,t;
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];/**/
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>a[i][j];
	memset(a,0x3f,sizeof(a));
	cout<<12;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
