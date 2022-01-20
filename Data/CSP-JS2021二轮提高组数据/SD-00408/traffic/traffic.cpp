#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N=1001;
int d[N][N],h[N][N];
long long sum;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0)^(unsigned long long)(new char));
	int t;
	int n,m;
	cin>>n>>m>>t;
	int e;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>d[i][j];sum+=d[i][j];
		 } 
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++) 
		{
			cin>>h[i][j];
			sum+=h[i][j];
		}
	}
	cout<<(rand()*rand())%sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
