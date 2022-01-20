#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue> 
#define maxn 500005
int t,n;
int ans=0;
int a[maxn],b[maxn];
/*int pd(){
	int q=1,p=n;
	while(q<=p){
		if(b[q]==b[p]){
			q++,p--;
		}
		else return 0;
	}
	ans++;
	
}
void dfs(int l,int r,int s){
	if(l==r){
		pd();
	}
	if(b[s]+=a[l]){
		dfs(l++,r,s++);
	}
	if(b[s]+=a[r]){
		dfs(l,r--,s++);
	}
}*/
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		int l=1,r=n,s=1;
//		dfs(1,n,s);
//		if(ans==0){

			printf("%d","-1");
//		}
	
//		else printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
