#include<cstdio>
#include<cstring>
using namespace std;
int pos1[1000050];
int pos2[1000050];
int a[1000050];
int vis[1000050];
char ans[1000050];
int st[1000050];
int cnt;
int n;
int t;
int dfs(int i,int j){
	if(cnt==n){
		int j=1,k=2*n;
		for(int i=1;i<=n;i++){
			if(ans[i]=='L')st[i]=a[j],j++;
			if(ans[i]=='R')st[i]=a[k],k--;
			printf("%c",ans[i]);
		}
		for(int i=n;i>=1;i--){
			if(a[j]==st[i])printf("%c",'L'),j++;
			else printf("%c",'R'),k--;
		}
		printf("\n");
		return 1;
	}
	if(vis[a[i]]==0){
		ans[++cnt]='L';
		int x=pos2[a[i]];
		vis[a[i]]=1;
		if(x==2*n){
			if((vis[a[x-1]]==1)||cnt==1)if(dfs(i+1,j))return 1;
		}
		else{
			if((vis[a[x-1]]==1)||(vis[a[x+1]]==1)||cnt==1)if(dfs(i+1,j))return 1;
		}
		vis[a[i]]=0;
		cnt--;
	}
	if(vis[a[j]]==0){
		ans[++cnt]='R';
		int x=pos1[a[j]];
		vis[a[j]]=1;
		if(x==0){
			if((vis[a[x+1]]==1)||cnt==1)if(dfs(i,j-1))return 1;
		}
		else{
			if((vis[a[x-1]]==1)||(vis[a[x+1]]==1)||cnt==1)if(dfs(i,j-1))return 1;
		}
		vis[a[j]]=0;
		cnt--;
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(pos1,0,sizeof(pos1));
		memset(pos2,0,sizeof(pos2));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(pos1[a[i]]==0)pos1[a[i]]=i;
			else pos2[a[i]]=i;
		}
		if(dfs(1,2*n)==0)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
