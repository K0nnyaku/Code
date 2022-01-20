#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
const int N=10000;
int c(){
	
	
	
	
} 
int main(){
	int n;
	int a[N],b[N];
    freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    cin>>n;
	for(int i=1;i<2n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<2n;i++){
	 if(a[i]=a[2n+1-i]){
	 	cout<<"-1"<<endl;
	 }
	 else{
	 	if(a[i]!=a[i+1]){
	 		c="L"+c();
		 }
		 else if(a[i]==a[i+1]&&a[i]!=a[2n+1-i]){
		 	c="R"+c();
		 }
	 }
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
