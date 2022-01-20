#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define N 500010
int T,n,a[2*N],vis[N];
int flag;
struct node{
	int p;
	int x;
}ans[N];
bool cmp(node x,node y){
	return x.p<y.p;
}
void DFS(int x,int l,int r){
	if(flag==1) return ;
	if(x>n){
		for(int i=n;i>0;i--){
			if(vis[a[l]]!=i&&vis[a[r]]!=i)return ;
			if(vis[a[l]]==i) l++;
			else r--;
		}
		flag=1;
		for(int i=1;i<=n;i++)
			ans[i].p=vis[i],ans[i].x=i;
		sort(ans+1,ans+1+n,cmp);
		l=1;r=n;
		for(int i=1;i<=n;i++){
			if(a[l]==ans[i].x){
				printf("L");l++;
			} 
			else {
				printf("R");r--;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[l]==ans[i].x){
				printf("L");l++;
			} 
			else {
				printf("R");r--;
			}
		}
		return ;
	}
	if(!vis[a[l]]){
		vis[a[l]]=x;
		DFS(x+1,l+1,r);
		vis[a[l]]=0;
	}
	if(!vis[a[r]]){
		vis[a[r]]=x;
		DFS(x+1,l,r-1);
		vis[a[r]]=0;
	}
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		flag=0;
		DFS(1,1,2*n);
		if(!flag)printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
