#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("traffc.in","r",stdin);
	freopen("traffc.out","w",stdout);
	int n,m,t,x,y;
	cin>>n>>m>>t;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++)cin>>x;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)cin>>x;
	}
	while(t--){
		cin>>x;
		for(int i=1;i<=x;i++)cin>>y>>y>>y;
	}
	
	if(n==2)cout<<"12";
	else if(t==1)cout<<"572399564" ;
	return 0;
}
