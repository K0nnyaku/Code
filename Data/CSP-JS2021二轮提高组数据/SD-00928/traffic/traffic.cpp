#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,p,t;
}p[55];
int n,m,k;
int a[15][15][15][15];
int minn=0x7fffffff;
int findx(int x){
	if(x<=m)
		return 1;
	else if(x>m&&x<=m+n)
		return x-m;
	else if(x>m+n&&x<=2*m+n)
		return n;
	else
		return 2*m+2*n+1-x;
}
int findy(int x){
	if(x<=m)
		return x;
	else if(x>m&&x<=m+n)
		return m;
	else if(x>m+n&&x<=2*m+n)
		return 2*m+n+1-x;
	else
		return 1;
} 
int work(int c[]){
	int ans=0;
	for(int i=1;i<=k;i++){
		if(p[i].t!=c[findx(p[i].p)*10+findy(p[i].p)])
			ans+=p[i].x;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			ans+=(c[i*10+j]!=c[(i+1)*10+j])*a[i][j][i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			ans+=(c[i*10+j]!=c[i*10+j+1])*a[i][j][i][j+1];
		}
	}
	return ans;
}
void dfs(int x,int y,int c[]){
	if(x==n+1){
		minn=min(minn,work(c));
		return;
	}
	int nxtx,nxty;
	if(y==m)
		nxtx=x+1,nxty=1;
	else
		nxtx=x,nxty=y+1;
	c[x*10+y]=0;
	dfs(nxtx,nxty,c);
	c[x*10+y]=1;
	dfs(nxtx,nxty,c);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int q,x,line,t;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j][i+1][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%d",&a[i][j][i][j+1]); 
		}
	}
	while(q--){
		minn=0x7fffffff;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&x,&line,&t);
			p[i]={x,line,t};
		}
		int c[105];
		dfs(1,1,c);
		printf("%d\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
