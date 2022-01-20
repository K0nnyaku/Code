#include<iostream>
#include<cstdio>
using namespace std;
int n,m,T,ans; 
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<n;i++) {
		for(int j=1;j<=m;j++) {
			int x;
			cin>>x;
			ans+=x;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<m;j++) {
			int x;
			cin>>x;
			ans+=x;
		}
	}
	while(T--) {
		int k;
		cin>>k;
		while(k--) {
			int a,b,c;
			cin>>a>>b>>c;
		} 
		cout<<ans<<endl;
	}
	return 0;
}

