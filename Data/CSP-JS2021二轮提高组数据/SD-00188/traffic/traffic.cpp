#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//CSP 2021 RP++!
void file(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}
int a[505][505],b[505][505],n,m,t,k,ans=0x3f3f3f3f;
int p[505][505],c[505*505],w[505],r[505],x[505];
int check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p[i][j]=c[i*m+j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(p[i][j]!=p[i][j+1]) cnt+=a[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]!=p[i+1][j]) cnt+=b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(r[i]<=m){
			if(p[1][r[i]]!=x[i]) cnt+=w[i];
		}
		else if(r[i]<=n+m){
			if(p[r[i]-n+1][m]!=x[i]) cnt+=w[i];
		}
		else if(r[i]<=m*2+n){
			if(p[n][r[i]]!=x[i]) cnt+=w[i];
		}
		else{
			if(p[r[i]-n+1][r[i]]!=x[i]) cnt+=w[i];
		}
	}
	return cnt;
}
void dfs(int dep){
	if(dep==n*m+1){
		ans=min(ans,check());
		return;
	}
	c[dep]=1;
	dfs(dep+1);
	c[dep]=0;
	dfs(dep+1);
}
int main(){
	file(); 
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
	while(t--){
		cin>>k;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			w[i]=a;
			r[i]=b;
			x[i]=c;
		}
		ans=0x3f3f3f3f;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
