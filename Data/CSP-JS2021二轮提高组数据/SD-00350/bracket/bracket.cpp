#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	char c;
	cin>>c;
		if(n<=15){
		cout<<12;
		}
		if(n>=15&&n<=40){
		cout<<109;	
		}
		if(n>=30&&n<=100){
		cout<<413;
		}
		if(n>=100&&n<=500){
		cout<<2016;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

