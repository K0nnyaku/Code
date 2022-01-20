#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500050
using namespace std;
int t,n,a[N],cnt,cun[N],dan[N],f,mid,zhong[N],vis[N],ji;
inline void dfs(int l,int r){
	if(l>2*n||r<1) return;
	if(vis[l]&&vis[r]){
		for(int i=1;i<=n;i++){
			if(dan[i]!=dan[2*n+1-i]) return;
		}
		for(int i=1;i<=2*n;i++){
			if(cun[i]<zhong[i]){
				f=1;
				for(int j=1;j<=2*n;j++) zhong[j]=cun[j];
				return;
			}
			if(cun[i]>zhong[i]) return;
		}
		return;
	}
	if(!vis[l]){
		vis[l]=1;
		cun[++cnt]=1;
		dan[cnt]=a[l];
		dfs(l+1,r);
		vis[l]=0;
		cnt--;
	}
	if(!vis[r]){
		vis[r]=1;
		cun[++cnt]=2;
		dan[cnt]=a[r];
		dfs(l,r-1);
		cnt--;
		vis[r]=0;
	}
	
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ji++;
		scanf("%d",&n);
		memset(zhong,0x3f,sizeof(zhong));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		if(n<=100){
			cnt=0;
			f=0;
			dfs(1,n*2);
			if(!f){
				printf("-1\n");
				continue;
			}
			for(int i=1;i<=n*2;i++){
				if(zhong[i]==1) printf("L");
				else printf("R");
			}
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
