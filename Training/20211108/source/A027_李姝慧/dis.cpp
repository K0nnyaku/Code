#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,kx,ans,dep[55],f[55];
bool bt[505][505],vis[55][55];
char ch;
void yu(int x,int fa){
	if(x>n) return;
	dep[x]=dep[fa]+1;
	f[x]=fa;
	yu(x*2,x);yu(x*2+1,x);
}
bool lca(int a,int b){
	int s=0;
	if(dep[a]<dep[b]) swap(a,b);
	while(dep[a]>dep[b]&&!bt[a][f[a]]) s++,a=f[a];
	while(a!=b&&!bt[a][f[a]]&&!bt[b][f[b]]) a=f[a],b=f[b],s+=2;
	if(a==b&&s<=kx) return 1;
	return 0; 
}
int main(){
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%d%d",&n,&m);
		yu(1,0);
		for(int i=1;i<=m;i++){
			cin>>ch;
			scanf("%d",&kx);
			if(ch=='?'){
				ans=0;
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						ans+=lca(i,j);
					}
				}
				printf("%d\n",ans);
			}
			else bt[kx][kx/2]=bt[kx/2][kx]=1;
		}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 





