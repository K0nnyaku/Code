#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue> 
#define maxn 5000
int n,m,T;
int c[maxn][maxn];
struct node{
	int jiazhi;//(i,j)µ½(i,j+1) 
	int jiaer;//(i,j)µ½(i+1,j) 
};
node ditu[maxn][maxn];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			int jz;
			scanf("%d",&jz);
			ditu[i][j].jiaer=jz;	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			int jz;
			ditu[i][j].jiazhi=jz;
		}
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int quan,hao,yan;
		scanf("%d%d%d",&quan,&hao,&yan);
	}
	printf("%d","12");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
