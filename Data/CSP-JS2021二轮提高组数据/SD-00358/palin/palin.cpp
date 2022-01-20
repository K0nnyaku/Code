#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n[100001],a[100001],b[100001],l,k,t,i;
int main() {
freopen("palin.in","r",stdin);
freopen("palin.out","w",stdout); 
	cin>>t;
	for(i=1; i<=t; i++) {
		cin>>n[i];
		cin>>a[i];
	}
	if(t==1) {
		cout<<"-1";
		return 0;
	} else {
		for(int j=1; j<=t; j++) {
			for(i=1; i<=2*n[j]; i++) {
				cout<<"L";
			}
			cout<<endl;
		}
	}
	return 0;
}
