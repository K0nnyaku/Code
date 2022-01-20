#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,T,ans=0,x3,p,t,k;
int x1[1000][1000],x2[1000][1000],dis[1000],cr[1000],cr1[1000][1000];
void dfs(int x,int y,int sum){
	if(y==m+1){
		x++;
		y=1;
	}
	if(x==n+1){
		printf("%d\n",sum);
		ans=min(ans,sum);
		return;
	}
	int tmp=0;
	cr1[x][y]=0;
	if(x==1&&y==1){
		if(cr[1]==1&&cr[2*n+2*m]==1)tmp+=dis[1]+dis[2*n+2*m];
		else if(cr[1]==1)tmp+=dis[1];
		else if(cr[2*m+2*n]==1)tmp+=dis[2*m+2*n];
	}
	else if(x==1&&y==m){
		if(cr[m]==1&&cr[m+1]==1)tmp+=dis[m]+dis[m+1];
		else if(cr[m]==1)tmp+=dis[m];
		else if(cr[m+1]==1)tmp+=dis[m+1];
	}
	else if(x==n&&y==1){
		if(cr[2*m+n]==1&&cr[2*m+n+1]==1)tmp+=dis[2*m+n]+dis[2*m+n+1];
		else if(cr[2*m+n]==1)tmp+=dis[2*m+n];
		else if(cr[2*m+n+1]==1)tmp+=dis[2*m+n+1];
	}
	else if(x==n&&y==m){
		if(cr[m+n]==1&&cr[m+n+1]==1)tmp+=dis[m+n]+dis[m+n+1];
		else if(cr[m+n]==1)tmp+=dis[m+n];
		else if(cr[m+n+1]==1)tmp+=dis[m+n+1];
	}
	else if(x==1)
		if(cr[y]==1)tmp+=dis[y];
	else if(y==1)
		if(cr[2*m+2*n+1-x]==1)tmp+=dis[2*m+2*n+1-x];
	else if(x==n)
		if(cr[2*m+n+1-y]==1)tmp+=dis[2*m+n+1-y];
	else if(y==m)
		if(cr[m+x]==1)tmp+=dis[m+x];
	if(x-1>=1&&cr1[x-1][y]==1)tmp+=x1[x-1][y];
	if(y-1>=1&&cr1[x][y-1]==1)tmp+=x2[x][y-1];
	printf("%d\n",tmp);
	dfs(x,y+1,sum+tmp);
	cr1[x][y]=1;
	tmp=0;
	if(x==1&&y==1){
		if(cr[1]==0&&cr[2*n+2*m]==0)tmp+=dis[1]+dis[2*n+2*m];
		else if(cr[1]==0)tmp+=dis[1];
		else if(cr[2*m+2*n]==0)tmp+=dis[2*m+2*n];
	}
	else if(x==1&&y==m){
		if(cr[m]==0&&cr[m+1]==0)tmp+=dis[m]+dis[m+1];
		else if(cr[m]==0)tmp+=dis[m];
		else if(cr[m+1]==0)tmp+=dis[m+1];
	}
	else if(x==n&&y==1){
		if(cr[2*m+n]==0&&cr[2*m+n+1]==0)tmp+=dis[2*m+n]+dis[2*m+n+1];
		else if(cr[2*m+n]==0)tmp+=dis[2*m+n];
		else if(cr[2*m+n+1]==0)tmp+=dis[2*m+n+1];
	}
	else if(x==n&&y==m){
		if(cr[m+n]==0&&cr[m+n+1]==0)tmp+=dis[m+n]+dis[m+n+1];
		else if(cr[m+n]==0)tmp+=dis[m+n];
		else if(cr[m+n+1]==0)tmp+=dis[m+n+1];
	}
	else if(x==1)
		if(cr[y]==0)tmp+=dis[y];
	else if(y==1)
		if(cr[2*m+2*n+1-x]==0)tmp+=dis[2*m+2*n+1-x];
	else if(x==n)
		if(cr[2*m+n+1-y]==0)tmp+=dis[2*m+n+1-y];
	else if(y==m)
		if(cr[m+x]==0)tmp+=dis[m+x];
	if(x-1>=1&&cr1[x-1][y]==0)tmp+=x1[x-1][y];
	if(y-1>=1&&cr1[x][y-1]==0)tmp+=x2[x][y-1];
	dfs(x,y+1,sum+tmp);
	return;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&x1[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)scanf("%d",&x2[i][j]);
	for(int i=1;i<=T;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d%d",&x3,&p,&t);
			dis[p]=x3;
			cr[p]=t;
		}
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
