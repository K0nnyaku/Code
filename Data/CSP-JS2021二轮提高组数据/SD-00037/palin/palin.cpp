#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int sz[10000],n,b[1000],ans[1000];
bool check(int n,int a[]){
	for(int i=1;i<=n;i++){
		if(a[n-i+1]!=a[i])return 0;
	}
	return 1;
}
bool dfs(int l,int r,int top){
	if(top==n+1){
		if(check(n,b)){
			for(int i=1;i<=n;i++){
				if(ans[i]==1)cout<<"L";
				else cout<<"R";
			}
			cout<<endl;
			return 1;
		}
		return 0;
	}
	ans[top]=1;
	b[top]=sz[l];
	if(dfs(l+1,r,top+1))return 1;
	ans[top]=0;
	b[top]=sz[r];
	if(dfs(l,r-1,top+1))return 1;
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++){
			cin>>sz[i];
		}
		if(!dfs(1,n,1))cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
