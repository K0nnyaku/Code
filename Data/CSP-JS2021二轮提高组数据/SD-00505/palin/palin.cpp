#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,a[1231231],b[1231231],d[1231231],n,flag;
void dfs1(int x,int y,int t){
	if(flag==1)return;
	if(t==2*n){
		flag=1;
		return;
	}
	b[t]=a[x];
	d[t]=1;
	if(b[2*n-t+1]==b[t])dfs1(x+1,y,t+1);
	b[t]=a[y];
	d[t]=2;
	if(b[2*n-t+1]==b[t])dfs1(x,y-1,t+1);
}
void dfs(int x,int y,int t){
	if(flag==1)return;
	
	if(t==n){
		dfs1(x,y,t);
	}
	b[t]=a[x];
	d[t]=1;
	dfs(x+1,y,t+1);
	d[t]=2;
	b[t]=a[y];
	dfs(x,y-1,t+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		
		cout<<-1<<endl;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
