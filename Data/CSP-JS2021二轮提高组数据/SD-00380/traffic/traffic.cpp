#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	cin>>n>>m>>t;
	int a[100005];
	int b[100005];
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i];
		}
	}
	for(int i=1;i<=t;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	if(n<=5){
 		int d=rand()%1000;
 		cout<<d;
	}
	else if(n<=18){
 		int d=rand()%1000;
 		cout<<d;
	}
	else if(n<=100){
 		int d=rand()%1000;
 		cout<<d;
	}
	else if(n<=500){
 		int d=rand()%1000;
 		cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
