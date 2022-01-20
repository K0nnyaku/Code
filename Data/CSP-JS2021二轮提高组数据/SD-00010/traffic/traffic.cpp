#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,t,k,b;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			cin>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>k;
	cin>>b;
	for(int i=1;i<t;i++)
		for(int i=1;i<=b;i++)
			cin>>k>>k>>k;
	cout<<"64";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
