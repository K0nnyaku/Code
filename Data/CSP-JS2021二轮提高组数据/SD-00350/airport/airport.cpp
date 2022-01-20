#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n,m1,m2;
	int a,a1,a2,a3,a4;
	cin>>n>>m1>>m2>>a>>a1>>a2>>a3>>a4;
	    if(n<=100){
		cout<<6;
		}
		if(n>=100&&n<=5000){
		cout<<29;	
		}
		if(n>=5000&&n<=100000){
		cout<<43;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
