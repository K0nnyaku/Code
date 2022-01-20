#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
	char ch=' ';
	int v=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){v=(v<<1)+(v<<3)+(ch^48);ch=getchar();}
	return v*x;
}
const int N=1010;
int n,m,k,t,cnt,ans,head[N],v[N],w[N],nxt[N],col[N]; 
void add(int x,int y,int z){
	v[++cnt]=y,w[cnt]=z,nxt[cnt]=head[x],head[x]=cnt;
}
void dfs(int x){
	if(x==n*m+1){
		int res=0;
		for(int i=1;i<=n*m+k;i++)
			for(int j=head[i];j;j=nxt[j])
				if(col[i]!=col[v[j]]) res+=w[j];
		ans=min(ans,res);
		return;
	}
	col[x]=0;
	dfs(x+1);
	col[x]=1;
	dfs(x+1);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			add((i-1)*m+j,i*m+j,read());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			add((i-1)*m+j,(i-1)*m+j+1,read());
	while(t--){
		k=read();
		ans=1e9;
		memset(col,0,sizeof(col));
		for(int i=1;i<=k;i++){
			int s=read(),x=read(),c=read();
			if(x<=m) add(n*m+i,x,s);
			if(x>m&&x<=n+m) add(n*m+i,n*(m-1)+x-m,s);
			if(x>n+m&&x<=n+m*2) add(n*m+i,n*m-x+n+m+1,s);
			if(x>n*m+2) add(n*m+i,m*(n-x+n+m*2)+1,s);
			col[n*m+i]=c;
		}
		dfs(1);
		for(int i=n*m+1;i<=n*m+k;i++)
			head[i]=0;
		printf("%d ",ans);
	}
	return 0;
}


