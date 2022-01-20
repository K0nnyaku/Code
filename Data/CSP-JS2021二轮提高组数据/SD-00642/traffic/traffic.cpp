#include<cstdio>
using namespace std;
const int MAXN=505;
inline int minn(int a,int b){
	return a<b?a:b;
}
int uedge[MAXN][MAXN];//从x,y向上的边的边权 
int ledge[MAXN][MAXN];//从x,y向左的边的边权 
char flag[MAXN][MAXN];//x,y的颜色 
int EXedge[MAXN<<2];//扩展边的颜色 
char EXvis[MAXN];//扩展点是否存在 
char EXflag[MAXN<<2];//扩展点的颜色 
int n,m;
inline long long getcost(int x,int y){
	long long res=0;
	if(x==1){
		if(EXvis[y]&&EXflag[y]!=flag[x][y])
			res+=EXedge[y]; 
	}else if(flag[x][y]!=flag[x-1][y])
		res+=uedge[x][y];
	if(x==n&&EXvis[m+n+m-y+1]&&EXflag[m+n+m-y+1]!=flag[x][y])
		res+=EXedge[m+n+m-y+1];
	if(y==1){
		if(EXvis[2*(n+m)-x+1]&&EXflag[2*(n+m)-x+1]!=flag[x][y])
			res+=EXedge[2*(n+m)-x+1];
	}else if(flag[x][y-1]!=flag[x][y])
		res+=ledge[x][y];
	if(y==m&&EXvis[m+x]&&EXflag[m+x]!=flag[x][y])
		res+=EXedge[m+x];
	return res;
}
long long solve(int x,int y,long long now){
	if(y>m)y=1,x++;
	if(x==n+1)return now;
	long long res=0x7f7f7f7f7f7f7f7f;
	flag[x][y]=0;
	res=minn(res,solve(x,y+1,now+getcost(x,y)));
	flag[x][y]=1;
	res=minn(res,solve(x,y+1,now+getcost(x,y)));
	return res;
}
int T,k,x,p,c;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			uedge[i][j]=x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			scanf("%d",&x);
			ledge[i][j]=x;
		}
	}
	while(T--){
		scanf("%d",&k);
		for(int i=1;i<=2*(n+m);i++)EXvis[i]=0;
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&x,&p,&c);
			EXedge[p]=x;
			EXflag[p]=c;
			EXvis[p]=1;
		}
		printf("%lld",solve(1,1,0ll));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

