//zhn 记住 你就是个大菜鸡 放平心态
//消注释！！！return 0！！！
//打暴力啊啊啊，别乱想正解，你想不出来
//实在不行直接打暴力，打完暴力之后“正解”和暴力分区
//别忘了用快读
//orz zrz qlr qyc zyz ljc zsy wyh wym lyt dln
//rp++
//sdsy nb！！！ 
#include<cstdio>
#include<cstring>
#include<iostream>
#define lc(k) ((k)<<1)
#define rc(k) ((k)<<1|1) 

using std::min;

int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

long long qpow(int x,int y){//可自加膜数 
	long long res=1;
	while(y){
		if(y&1) res=1ll*x*res;
		x=1ll*x*x;
		y>>=1;
	}
	return res;
}

int n,m,t;
int a[10][10][3];
int b[10][10][3];
int color[10][10];
int ans;

int check(){
	int sum=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%d ",color[i][j]);
			if(color[i][j]!=color[i+1][j]) sum+=b[i][j][1];
			if(color[i][j]!=color[i][j+1]) sum+=b[i][j][2];
		}
		printf("\n");
	}
	return sum;
}

void dfs(int x,int y){
	if(x==n+1){
//		printf("fuck!!!\n");
		ans=min(ans,check());
		return;
	}
	if(y==m){
		color[x][y]=0;
		dfs(x+1,1);
		color[x][y]=1;
		dfs(x+1,1);
		color[x][y]=0;
	}
	else{
		color[x][y]=0;
		dfs(x,y+1);
		color[x][y]=1;
		dfs(x,y+1);
		color[x][y]=0;
	}
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=rd();m=rd();t=rd();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++) a[i][j][1]=rd();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++) a[i][j][2]=rd();
	}
	while(t--){
		ans=998244353;
		int k;
		scanf("%d",&k);
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				for(int p=0;p<=2;p++){
					b[i][j][p]=a[i][j][p];
				}
			}
		}
		memset(color,0,sizeof(color));
		for(int i=1;i<=k;i++){
			int x=rd(),y=rd();
			if(y>=1&&y<=m){
				b[0][y][1]=x;
				color[0][y]=rd();
			}
			else if(y>m&&y<=m+n){
				b[y-m][m][2]=x;
				color[y-m][m+1]=rd();
			}
			else if(y>m+n&&y<=2*m+n){
				b[n][m*2+n-y+1][1]=x;
				color[n+1][m*2+n-y+1]=rd();
			}
			else{
				b[2*n-2*m-y+1][0][2]=x;
				color[2*n-2*m-y+1][0]=rd();
			}
		}
		dfs(1,1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
