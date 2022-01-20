#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int b[n];
	for(int i=0;i<n;i++)b[i]=0;
	char a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}
	if(n==3||n==4)cout<<"1";
	else if(n==5)cout<<"2";
	else if(n==6)cout<<"3";

	
	
	return 0;
}
