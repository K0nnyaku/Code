#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int T,ans=0,n,a[2000010];
int b[2000010];
char c[2000010];
int l,r;
int q;
int ll;
bool pd(){
	//for(int i=1;i<=n;i++) cout<<a[i];
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]) return false;
	}
	for(int i=1;i<=n;i++) cout<<c[i];
	cout<<endl;
	return true;
}
void dfs(int x,int y,int de){
	if(q==-1) return;
	if(de==n){
		if(pd()){
			q=-1;
			return;
		}
		return;
	}
	a[de+1]=b[x];
	c[de+1]='L';
	dfs(x+1,y,de+1);
	if(q==-1) return;
	a[de+1]=b[y];
	c[de+1]='R';
	dfs(x,y-1,de+1);
	if(q==-1) return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	ll=T;
	while(T!=0){
		T--;
		cin>>n;
		if(n<=10){
			q=0;
			n=n*2;
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++){
				cin>>b[i];
			}
			a[1]=b[1];
			c[1]='L';
			dfs(2,n,1);
			a[1]=b[n];
			c[1]='R';
			dfs(1,n-1,1);
			if(q!=-1) cout<<"-1"<<endl;
		}
		else if(ll==1){
			for(int i=1;i<=n;i++) cout<<"L";
			cout<<endl;
		}
		else cout<<"-1"<<endl;
	}
	return 0;
}
