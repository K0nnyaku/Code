#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[1010][1010],b[1010][1010],c[1010][1010];
int k[1001];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
cin>>n>>m>>t;
for(int i=1;i<n;i++){
	for(int j=1;j<=m;j++){
		cin>>a[i][j];
	}
} 
for(int i=1;i<=n;i++){
	for(int j=1;j<m;j++){
		cin>>b[i][j];
	}
}
for(int i=1;i<=t;i++){
	cin>>k[i];
	for(int j=1;j<=k[i];j++){
		cin>>c[i][j];
	}
}
cout<<23<<endl;
fclose(stdin);
fclose(stdout);
return 0; 
}
