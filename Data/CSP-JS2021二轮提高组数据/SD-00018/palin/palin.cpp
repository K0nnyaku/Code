#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
int a[N],n,b[N];
bool ans1[N],useds[N];
bool dfs(int l,int r,int cnt2){
	if(cnt2==(n<<1)) return 1;
	if(cnt2<n){
		if(!useds[a[l]]){
			useds[a[l]]=1;
			b[cnt2+1]=a[l];
			ans1[cnt2+1]=1;
			if(dfs(l+1,r,cnt2+1)){
				useds[a[l]]=0;
				return 1;
			}
			useds[a[l]]=0;
		}
		if(!useds[a[r]]){
			useds[a[r]]=1;
			b[cnt2+1]=a[r];
			ans1[cnt2+1]=0;
			if(dfs(l,r-1,cnt2+1)){
				useds[a[r]]=0;
				return 1;
			}
			useds[a[r]]=0;
		}
		return 0;
	}
	if(a[l]==b[n*2-cnt2]){
		ans1[cnt2+1]=1;
		if(dfs(l+1,r,cnt2+1)) return 1;
	}
	if(a[r]==b[n*2-cnt2]){
		ans1[cnt2+1]=0;
		if(dfs(l,r-1,cnt2+1)) return 1;
	}
	return 0;
}
bool dfs2(int l,int r,int cnt2){
	if(cnt2==n) return 1;
	if(!useds[a[l]]){
		useds[a[l]]=1;
		b[cnt2+1]=a[l];
		ans1[cnt2+1]=1;
		if(dfs2(l+1,r,cnt2+1)){
			useds[a[l]]=0;
			return 1;
		}
		useds[a[l]]=0;
	}
	if(!useds[a[r]]){
		useds[a[r]]=1;
		b[cnt2+1]=a[r];
		ans1[cnt2+1]=0;
		if(dfs2(l,r-1,cnt2+1)){
			useds[a[r]]=0;
			return 1;
		}
		useds[a[r]]=0;
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	if(t<=10){//part 1
		for(i=0;i<t;i++){
			memset(useds,0,sizeof(useds));
			scanf("%d",&n);
			for(j=0;j<(n<<1);j++) scanf("%d",&a[j]);
			if(!dfs(0,(n<<1)-1,0)) printf("-1\n");
			else{
				for(j=1;j<=(n<<1);j++){
					if(ans1[j]) printf("L");
					else printf("R");
				}
				printf("\n");
			}
		}
	}
	else{//part 6
		for(i=0;i<t;i++){
			memset(useds,0,sizeof(useds));
			scanf("%d",&n);
			for(j=0;j<(n<<1);j++) scanf("%d",&a[j]);
			if(!dfs2(0,(n<<1)-1,0)) printf("-1\n");
			else{
				for(j=1;j<=n;j++){
					if(ans1[j]) printf("L");
					else printf("R");
				}
				for(j=n;j;j--){
					if(ans1[j]) printf("L");
					else printf("R");
				}
				printf("\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
