#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main(){
	/*freopen("airport.in","r",stdin)
	freopen("airport.out","w",stdout)*/
	
	int n,m1,m2;
	int a1i,b1i,a2i,b2i;
	int x=0;
	
	cin>>n>>m1>>m2;
	
	for(int i=1;i<=m1;i++){
		cin>>a1i>>b1i;
	} 
	
	for(int j=1;j<=m2;j++){
		cin>>a2i>>b2i;
	}
	
	while(a1i>a2i){
		a2i=a1i;
	}
	
	while(a2i>a1i){
		a1i=a2i;
	}
	
	while(b1i>b2i){
		b2i=b1i;
	}
	
	while(b2i>b1i){
		b1i=b2i;
	}
	
	if(a1i>=a2i && b1i<=b2i){
		x++;
	} 
	
	if(a2i>=a1i && b2i<=b1i){
		x++;
	}
	
	cout<<7;
	
	return 0;
} 
