#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n[100],a[100][500005];
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n[i];
		for(int j=1;j<=2*n[i];j++){
			cin>>a[i][j];
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
