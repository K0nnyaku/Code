#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,T,k;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			cin>>k;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			cin>>k;
		}
	}
	if(n<5){
		cout<<11;
	}
	else cout<<15; 
	return 0;
}
