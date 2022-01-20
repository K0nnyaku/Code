#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int n;
int c[1000005];
int o[1000005];
bool w[1000005];
bool pan(){
	bool f=1;
	for(int i=0;i<n*2;i++){
		if(b[i]!=b[2*n-i-1]){
			f=0;
		}
	}
	return f;
}
bool dfs(int x,int y,int z){
	if(x==y){
	if(pan()){
	return 1;	
	}
	return 0;
	}
	b[z]=a[x];
	if(dfs(x+1,y,z+1)){
		c[z]=1;
	};
	if(dfs(y-1,x,z+1)){
		c[z]=2;
	};
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	int x;
	cout<<"-1"<<endl;
	return 0;
	cin>>x;
	for(int i=0;i<n*2;i++){
		b[i]=0;
	}
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	if(dfs(0,2*n,0));
	for(int o=0;o<n*2;o++){
		cout<<c[o];
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
