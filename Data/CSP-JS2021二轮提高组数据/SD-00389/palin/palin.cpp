//LFCode AK IOI
//qwaszx AK IOI
#include<bits/stdc++.h>//40pts±©Á¦ 
using namespace std;
int n;
int a[1000010];
int b[1000010];
bool opt[1000010];
int flag;
void dfs(int x,int l,int r){
	if(flag)
		return;
	if(x==2*n+1){
		flag=1;
		for(int i=1;i<=2*n;i++){
			if(opt[i]==0)
				printf("L");
			else
				printf("R");
		}
		puts("");
		return;
	}
	if(x<=n){
		b[x]=a[l];
		opt[x]=0;
		dfs(x+1,l+1,r);
		b[x]=a[r];
		opt[x]=1;
		dfs(x+1,l,r-1);
	}
	else{
		int y=2*n+1-x;
		if(a[l]!=b[y]&&a[r]!=b[y])
			return;
		if(a[l]==b[y]){
			opt[x]=0;
			dfs(x+1,l+1,r);
		}
		else{
			opt[x]=1;
			dfs(x+1,l,r-1);
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		flag=0;
		dfs(1,1,2*n);
		if(!flag){
			puts("-1");
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}






















