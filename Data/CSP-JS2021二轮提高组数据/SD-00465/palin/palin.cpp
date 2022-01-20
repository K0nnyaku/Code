#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,a;
	cin>>t;
	if(t==0){
		cout<<-1;return 0;
	}
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<2*n;i++){
			cin>>a;
			cout<<"L";
		}
		cout<<endl;
	}
	return 0;
}
