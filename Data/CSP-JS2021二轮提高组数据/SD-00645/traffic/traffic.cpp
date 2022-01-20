#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,T;

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>T;
	int xxx;
	for(int i=1;i<n;i++){
		for(int j=1;i<=m;j++)cin>>xxx;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)cin>>xxx;
	}
	int k;
	while(T--){
		cin>>k;
		int a,b,c,x,p,t;
		for(int i=1;i<=k;i++){
			cin>>a>>b>>c;
			cin>>x>>p>>t;
		}
		cout<<T<<endl;
	}
	
	return 0;
}

