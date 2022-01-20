#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int read(){
	char ch=' ';
	int v=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){v=(v<<1)+(v<<3)+(ch^48);ch=getchar();}
	return v*x;
}
const int N=1010;
int t,n,a[N],b[N],ans[N],vis[N]; 
void clear(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(vis,0,sizeof(vis));
	memset(ans,0x3f,sizeof(ans));
}
void dfs(int x){
	if(x==n*2+1){
		int l=1,r=n*2;
		for(int i=1;i<=n*2;i++){
			if(vis[i]==1) b[i]=a[l++];
			else b[i]=a[r--];
		}
		/*for(int i=1;i<=n*2;i++)
			printf("%d ",vis[i]);
		putchar('/');
		for(int i=1;i<=n*2;i++)
			printf("%d ",b[i]);
		putchar('\n');*/
		for(int i=1;i<=n;i++)
			if(b[i]!=b[n*2-i+1]) return;
		for(int i=1;i<=n*2;i++){
			if(vis[i]>ans[i]){
				return;
			}
			if(vis[i]<ans[i]){
				for(int j=1;j<=n*2;j++)
					ans[j]=vis[j];
				return;
			}
		}
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=2;
	dfs(x+1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		clear();
		n=read();
		for(int i=1;i<=n*2;i++)
			a[i]=read();
		dfs(1);
		if(ans[1]>1e9) printf("-1");
		else{
			for(int i=1;i<=n*2;i++){
				if(ans[i]==1) putchar('L');
				else putchar('R');
			}
		}
		putchar('\n');
	} 
	return 0;
}


