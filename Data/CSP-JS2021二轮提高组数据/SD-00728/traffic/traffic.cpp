#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	int x,y,z,ans1=INT_MAX,ans2=INT_MAX;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		ans1=min(ans1,y);
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y; 
		ans2=min(ans2,y);
	}
	for(int i=1;i<=t;i++){
		cout<<ans1+ans2;
	}
	return 0;
}


