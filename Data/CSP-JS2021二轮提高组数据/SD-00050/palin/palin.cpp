#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
ll T,n,a[1000010];
ll vis[1000010],xu[1000010],shu[1000010];
ll yes;
void dfs(ll ,ll ,ll );
bool check(ll ,ll );
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(ll i=1;i<=n*2;i++){
			scanf("%lld",&a[i]);
		}
		yes=0;
		memset(vis,0,sizeof(vis));
		dfs(1,n*2,0);
		if(!yes)printf("-1\n");
	}
	return 0;
}
bool check(ll l,ll r){
	for(ll i=1;i<=n;i++){
		if(a[l]==shu[n-i+1]){
			xu[n+i]=-1;
			l++;
		}else if(a[r]==shu[n-i+1]){
			xu[n+i]=1;
			r--;
		}else{
			return false;
		}
	}
	for(ll i=1;i<=n*2;i++){
		if(xu[i]==-1){
			printf("L");
		}else{
			printf("R");
		}
	}
	printf("\n");
	return true;
}
void dfs(ll l,ll r,ll ceng){
	if(yes)return;
	if(ceng==n){
		if(check(l,r)){
			yes=1;
		}
		return;
	}
	if(vis[a[l]]==0){
		vis[a[l]]=1;
		xu[ceng+1]=-1;
		shu[ceng+1]=a[l];
		dfs(l+1,r,ceng+1);
		vis[a[l]]=0;
	}
	if(vis[a[r]]==0){
		vis[a[r]]=1;
		xu[ceng+1]=1;
		shu[ceng+1]=a[r];
		dfs(l,r-1,ceng+1);
		vis[a[r]]=0;
	}
	return;
}
