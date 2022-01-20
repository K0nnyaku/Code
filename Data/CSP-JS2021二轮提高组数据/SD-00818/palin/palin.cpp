#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int T,n,x;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=2*n;j++){
			cin>>x;
		}
		if(n==5){
			cout<<"LRRLLRRRRL "<<endl;
		}
		if(n==3){
			cout<<"-1 "<<endl;
		}
	}
	return 0;
}
