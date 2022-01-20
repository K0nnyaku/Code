#include<bits/stdc++.h>
using namespace std;
const int N=1000011;
int n,ans=-1;
int a[N],b[N],c[N];//1L 2R
void dfs(int i,int y_st,int y_ed){
	if(ans!=-1) return;
	if(i==2*n+1){
		int ccc=0;
		for(int ii=1;ii<=2*n;ii++){
			if(c[ii]!=c[2*n-ii+1]){
				ccc=1;
				break;
			}
		}
		if(ccc==0){
			for(int ii=1;ii<=2*n;ii++){
				if(b[ii]==1) printf("L");
				else printf("R");
			}
			printf("\n");
			ans=0;
		}
		return;
	}
	b[i]=1;
	c[i]=a[y_st];
	dfs(i+1,y_st+1,y_ed);
	if(ans!=-1) return;
	b[i]=2;
	c[i]=a[y_ed];
	dfs(i+1,y_st,y_ed-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		ans=-1;
		dfs(1,1,2*n);
		if(ans==-1){
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
