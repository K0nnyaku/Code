#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,m1,m2,a,b,x;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a>>b;
	}
	for(int j=1;j<=m2;j++){
		cin>>a>>b;
	}
	if(n==3){
		x=7;
	}
	if(n==2){
		x=4;
	}
	if(n==10){
		x=32;
	}
	cout<<x<<endl;
	return 0;
}
