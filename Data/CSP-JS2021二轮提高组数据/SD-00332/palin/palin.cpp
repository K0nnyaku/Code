#include<bits/stdc++.h>
using namespace std;
int t,n,a[21],b[21],c[21],flag,d[21],m,l,r;
void dfs(int x){
	if(x==n+1){
		flag=1;
		for(int i=1;i<=n;i++)c[i]=b[i];
		return;
	}
	d[x]=a[l++];if(x<=n/2||d[x]==d[n-x+1]){
		dfs(x+1);l--;if(flag)return;
	}else l--;
	d[x]=a[r--];if(x<=n/2||d[x]==d[n-x+1]){
		b[x]=1;dfs(x+1);r++;b[x]=0;if(flag)return;
	}else r++;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);flag=0;n*=2;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=1;
		l=1;r=n;dfs(1);
		if(!flag)puts("-1");
		else{
			for(int i=1;i<=n;i++){
				if(c[i]==0)printf("L");
				else printf("R");
			}
		}
		puts("");
	}
	return 0;
}
