#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;
int n;
int k;
int a[105];
int b=n*k;
int main (){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
	}
	
	for(int i=1;i<=n*k;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*k;i++){
		if(a[i]==k){
			cout<<"L"<<" ";
		}
		else if(a[i]==k-1){
			cout<<"L"<<" ";
		}
		else if(a[i]>a[i+1]){
			cout<<"L"<<" ";
		}
		else if(a[i]<a[i+1]){
			cout<<"R"<<" ";
		}
		else{
			cout<<endl;
		
		}
		
	}
	cout<<endl;
	cout<<-1;
		return 0;
}
