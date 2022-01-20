//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int T,n,a[maxn],ans[maxn],vis[maxn],to[maxn];
bool dfs(int now,int l,int r,int x,int y){
	if(now>n) return 1;
	if(l<=x){
		if(l<x&&a[x]==a[l]){
			ans[now]=1;ans[2*n-now+1]=1;
			return dfs(now+1,l+1,r,x-1,y);
		}
		if(r>=y&&a[y]==a[l]){
			ans[now]=1;ans[2*n-now+1]=2;
			return dfs(now+1,l+1,r,x,y+1);
		}
	}
	if(r>=y){
		if(l<=x&&a[x]==a[r]){
			ans[now]=2;ans[2*n-now+1]=1;
			return dfs(now+1,l,r-1,x-1,y);
		}
		if(r>y&&a[y]==a[r]){
			ans[now]=2;ans[2*n-now+1]=2;
			return dfs(now+1,l,r-1,x,y+1);
		}
	}
	return 0;
}
void print(){
	for(int i=1;i<=2*n;i++){
		if(ans[i]==1) putchar('L');
		else putchar('R');
	}
	puts("");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) vis[i]=to[i]=0;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(!vis[a[i]]) vis[a[i]]=i;
			else to[i]=vis[a[i]],to[vis[a[i]]]=i;
		}
		ans[1]=1;ans[2*n]=1;
		if(dfs(2,2,2*n,to[1]-1,to[1]+1)){
			print();
		}else{
			ans[1]=2;ans[2*n]=1;
			if(dfs(2,1,2*n-1,to[2*n]-1,to[2*n]+1)){
				print();
			}else{
				puts("-1");
			}
		}
	}
	return 0;
}

