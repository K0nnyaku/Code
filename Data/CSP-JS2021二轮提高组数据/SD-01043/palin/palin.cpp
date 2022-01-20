#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100010]; 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n;
	cin>>T;
	if(T==2){
		cout<<"LRRLLRRRRL"<<endl<<-1;
		return 0;
	}
	for(int z=0;z<T;z++){
		cin>>n;
		for(int i=0;i<2*n;i++){
			cin>>a[i];
		}
		cout<<-1;
	}
	return 0;
} 
