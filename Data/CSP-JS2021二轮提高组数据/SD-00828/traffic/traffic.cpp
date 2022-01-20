#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
const int N=1e5+5;
int p[10000005];
int n,m,t,x,y,k;
void file(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}
int main(){
	file();
	cin>>n>>m>>t;
	int tot=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			p[++tot]=x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++) {
			cin>>x;
			p[++tot]=x;
		}
	}
	sort(p+1,p+tot+1);
	int ans=p[1]+p[2]+p[3];
	int z[5],a[5];
	while(t--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>y>>z[i];
		}
		if(z[1]==z[2]){
			cout<<0<<endl;
		}
		else{
			cout<<min(ans,min(a[1],a[2]));
		}
	}
	return 0;
} 
