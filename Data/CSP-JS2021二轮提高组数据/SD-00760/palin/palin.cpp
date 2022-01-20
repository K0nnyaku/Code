#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000050],bj,ans[1000050],b[1000050];
void dfs(int l,int r,int tot) {
	if(tot==n*2&&!bj) {
		for(int i=1;i<=n;i++) {
			if(b[2*n-i+1]!=b[i]) return ;
		}
		for(int i=1;i<=2*n;i++) {
			if(ans[i]==1) cout<<"L";
			else cout<<"R";
		}cout<<endl;
		bj=1;
		return ;
	}
	if(bj)return ;
	ans[++tot]=1;b[tot]=a[l];
	dfs(l+1,r,tot);
	tot--; 
	ans[++tot]=2;b[tot]=a[r];
	dfs(l,r-1,tot);
	tot--;
	return ;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;bj=0;
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		dfs(1,n*2,0);
		if(!bj)cout<<"-1"<<endl;
	}
	return 0;
}

