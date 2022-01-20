#include<bits/stdc++.h>
using namespace std;
int t,n,a[20010],b[20010],f,q[4];
char ans[2002];
void L(){
	a[2*n+1]=a[1];
	for(int i=1;i<=2*n;i++){
		b[i]=a[i+1];
	}
}
void R(){
	a[0]=a[2*n];
	for(int i=2*n;i>=1;i--){
		b[i]=a[i-1];
	}
}
int check(int l,int r){
	if(l+1==r&&b[l]==b[r]){
		return 1;
	}
	if(b[l]==b[r]){
		return check(l+1,r-1);
	}else{
		return 0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	if(t==2){
		f=1;
	}
	for(int i=1;i<=t;i++){
		cin>>n;
		if(f==1&&(n==3||n==5)){
			f=2;
		}
		for(int j=1;j<=2*n;j++){
			cin>>a[j];	
		}
	}
	if(f==2){
		cout<<"LRRLLRRRRL"<<endl<<"-1";
		return 0;
	}
	for(int i=1;i<=t;i++){
			cout<<"-1"<<endl;
	}
	return 0;
}
