#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){                                
    int n;
    int m1;
    int m2;
    int c;
    int sum=0;
	cin>>n;
	cout<<endl;
	cin>>m1;
	for(int i=1;i<=m1;i++){
		if(m1>n){
			cout<<n;
		}
		if(m1<n){
			cout<<m1;
		}
	}cout<<endl;
	cin>>m2;
	for(int i=1;i<=m2;i++){
		if(m2>n){
			cout<<n;	
		}
		if(m2<n){
			cout<<m2;
		}
	}cout<<endl;
	cin>>sum;
	for(int i=1;i<=sum;i++){
		if(m1+m2>=n){
		n=sum;}
		if(m1+m2<=n){
			c=sum;
		}
	}cout<<endl;
	cout<<sum;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
