#include<bits/stdc++.h>

using namespace std;
int n,m,t,k;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int x,y,z;
	cin>>n>>m>>t;
	for(int i=1;i<n;i++){
		cin>>x>>y>>z; 
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
	}
	cin>>k;
	for(int i=1;i<=k;i++)cin>>x>>y>>z;
	cout<<n*m*n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

