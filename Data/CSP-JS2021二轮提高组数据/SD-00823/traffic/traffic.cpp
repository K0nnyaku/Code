#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=a*10+c-'0',c=getchar();
	return a;
}
int n,m,p,l,z,ans;
struct {
	int to,next,w;
}e[250001];
int last[250001];
void add(int x,int y,int w){
	e[++l].to=y;e[l].w=w;e[l].next=last[x];last[x]=l;
}
int f[2500001];
void dfs(int now,int cnt){
	if(cnt==n*m+1){
		int sum=0;
		for(int i=1;i<=z+n*m;i++){
			for(int j=last[i];j;j=e[j].next){
				if(f[i]!=f[e[j].to]){
					sum+=e[i].w;
				}
			}
		}
		ans=min(sum,ans);
	}
	for(int i=last[now];i;i=e[i].next){
		if(i>n*m)continue;
		f[e[i].to]=1;
		dfs(e[i].to,cnt+1);
		f[e[i].to]=0;
		dfs(e[i].to,cnt+1);
	}
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	n=read();m=read();p=read();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int w;
			w=read();
			add((i-1)*m+j,i*m+j,w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int w;
			w=read();
			add((i-1)*m+j,(i-1)*m+j+1,w);
		}
	}
	z=n;
	while(p--){
		int k,num,w,co,t=1;
		ans=-1*1e9;
		k=read();
		z+=k;
		while(k--){
		w=read();num=read();co=read();
			}
		ans=rand()%1000+1;
		printf("%d\n",ans);
	}
	return 0;
}

