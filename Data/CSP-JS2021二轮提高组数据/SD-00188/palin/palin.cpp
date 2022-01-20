#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
//CSP 2021 RP++!
void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
int t,n,a[N];
int c[N],flag;
int b[N];
int check(){
	int l=1,r=2*n;
	for(int i=1;i<=2*n;i++){
		if(!c[i]){
			b[i]=a[r--];
		}
		else b[i]=a[l++];
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=b[n*2-i+1]){
			return 0;
		}
	}
	//for(int i=1;i<=n*2;i++) cout<<b[i];
	return 1;
}
void dfs(int dep){
	if(flag) return;
	if(dep==n*2+1){
		if(check()){
			for(int i=1;i<=n*2;i++){
				cout<<(c[i]?'L':'R');
			}
			cout<<endl;
			flag=1;
		}
		return;
	}
	c[dep]=1;
	dfs(dep+1);
	c[dep]=0;
	dfs(dep+1);
}
int main(){
	file();
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
		}
		flag=0;
		dfs(1);
		if(!flag){
			cout<<"-1"<<endl;
			continue;
		}
	}
	return 0;
}
/*
*/
