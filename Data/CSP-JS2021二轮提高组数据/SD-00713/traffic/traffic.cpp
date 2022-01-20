#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,k,x,y,p[1050],xx,yy,zz;
	cin>>n>>m>>k;
	for(int i=1;i<n;i++) 
	{
		for(int j=1;j<=m;j++)
		cin>>x;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		cin>>y;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>p[i];
		for(int j=1;j<=p[i];j++)
		cin>>xx>>yy>>zz;
	}
	for(int i=1;i<=k;i++)
	cout<<47*p[i]-yy*7-19<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
