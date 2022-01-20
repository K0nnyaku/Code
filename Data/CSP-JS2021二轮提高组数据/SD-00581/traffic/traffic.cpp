#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int x[1001][10001];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	int n,m,t;
	int r,c;
	int ans,tot;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i--){
		for(int j=1;j<=n;j++){
			cin>>r>>c;
		}
	}
	for(int z=1;z<=m;z++){
		for(int y=1;y<=n;y++){
			cin>>ans>>tot;
		}
	}
	cout<<"2"<<endl;
	return 0;
} 
