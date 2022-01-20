#include<bits/stdc++.h>
using namespace std;
const int N=43;
int T,n,a[N],b[N],c[N],ans;
void dfs(int x,int y,int le){
	if(le==2*n+1){
		ans=1;
		return ;
	}
	if(le>n){
		if(a[x]==b[2*n+1-le]){
			c[le]=1;
			dfs(x+1,y,le+1);
			if(ans)return ;
		}
		else if(a[y]==b[2*n+1-le]){
			c[le]=2;
			dfs(x,y-1,le+1);
			if(ans)return ;
		}
		else return ;
	}
	else{
		c[le]=1;
		b[le]=a[x];
		dfs(x+1,y,le+1);
			if(ans)return ;
		c[le]=2;
		b[le]=a[y];
		dfs(x,y-1,le+1);
			if(ans)return ;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		dfs(1,2*n,1);
		if(ans){
			for(int i=1;i<=2*n;i++){
				if(c[i]==1)printf("L");
				if(c[i]==2)printf("R");
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}
/*
4 1 2 4 5 3 1 2 3 5 4 1 2 4 5 3 1 2 3 5
*/
