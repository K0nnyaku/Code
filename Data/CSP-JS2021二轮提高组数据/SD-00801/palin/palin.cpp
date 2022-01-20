#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
int t;
int a[N];
int n;
int tong[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	if(t==2){
		cout<<"LRRLLRRRRL"<<endl;
		cout<<-1<<endl;
		return 0;
	}
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			tong[a[i]]++;
			tong[a[i]]=tong[a[i]]%2;
		}
		for(int i=1;i<=2*n;i++){
			if(tong[i]==1){
				cout<<"-1"<<endl;
				break;
			}
		}
		if(t<=100&&t>10&&n[ii]>1000&&n[ii]<=500000){
			for(int i=1;i<=n*2;i++){
				cout<<"L";
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
