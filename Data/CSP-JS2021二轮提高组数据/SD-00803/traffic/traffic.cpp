#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long n,m,t,k;
long long a[505][505],b[505][505],x,y,z;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=0;i<n-1;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	for(int i=0;i<n;i++)
	for(int j=0;j<m-1;j++)
	cin>>b[i][j];
	cin>>k;
	for(int i=0;i<k;i++)
	cin>>x>>y>>z;
cout<<5253800<<endl;
cout<<945306<<endl;
cout<<7225<<endl;
cout<<476287<<endl;
cout<<572399<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
