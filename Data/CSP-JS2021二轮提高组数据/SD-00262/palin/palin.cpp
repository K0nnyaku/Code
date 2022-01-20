#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[500005]={},flag=0,k=1;
int f[500005][2]={};
char ans[500005];
void dfs(int len,int l,int r){
	if(flag)return;
	if(len-1==n*2){
		flag = 1;printf("%s",ans);cout << endl;
		return;
	}
	if(f[a[l]][0]==0||(2*n-f[a[l]][0])==len-1){
		ans[len-1] = 'L';
		if(f[a[l]][0]==0)f[a[l]][0]=len;
		else f[a[l]][1] = len;
		dfs(len+1,l+1,r);
		if(f[a[l]][1]==0)f[a[l]][0]=0;
	}
	if(f[a[r]][0]==0||(2*n-f[a[r]][0])==len-1){
		ans[len-1] = 'R';
		if(f[a[r]][0]==0)f[a[r]][0]=len;
		else f[a[r]][1] = len;
		dfs(len+1,l,r-1);
		if(f[a[r]][1]==0)f[a[r]][0]=0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1;i<=t;i++){
		scanf("%d",&n);
		flag=0;
		for(int j = 1;j<=2*n;j++){
			scanf("%d",&a[j]);
		}
		dfs(1,1,2*n);
		if(!flag){
			cout << -1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
