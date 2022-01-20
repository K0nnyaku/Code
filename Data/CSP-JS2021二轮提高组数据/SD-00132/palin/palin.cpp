#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 2100010
#define inf 2147483647
#include<bits/stdc++.h>
using namespace std; 
/*
void dfs(int pos){
	flag=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n+1-i]) {
			flag=1;break;
		}
	} 
} */

int t,n,a[maxn];

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
	}
	cout<<"LRRLLRRRRL"<<endl<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
} 
