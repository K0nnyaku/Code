#include<iostream>
#include<cmath>
#include<cstdio>
#include<string> 
int n,m1,m2;
int cnt=0;
int a1,b1;
int a2,b2;
int t;
int a[105][105],b[105][105];
using namespace std;

int main (){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>m1>>m2;	
			}
		}
	cin>>a1>>b1;
	
	for(int i=1;i<=a1;i++){
		for(int j=i-1;j<=b1;j++){
			cin>>a[a1][b1];
		}
		
	}
	
	cin>>a2>>b2;
	
	for(int i=1;i<=a2;i++){
		for(int j=i-1;j<=b2;j++){
			cin>>b[a2][b2];
		}
		
	}
	if(n!=0){
		for(int i=1;i<=m1;i++)
			if(a1<b1){
				cnt++;
				n=n-1;
			}
	}
	if(n!=0){
		for(int i=1;i<=m2;i++){
			if(a2<b2){
				cnt++;
				n=n-1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
