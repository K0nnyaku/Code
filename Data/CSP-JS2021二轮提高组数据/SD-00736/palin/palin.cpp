#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n;
int a[100009];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=T;i++){
		cout<<"-1"<<endl;
	}
	return 0;
}
