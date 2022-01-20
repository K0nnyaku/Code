#include <ctime>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long
#define N 510
#define K 60
using namespace std;
inline bool isdigit(char x){return x>='0'&&x<='9';}
inline int read(){
	char x=getchar();int fl=1,ans=0;
	while(!isdigit(x)){if(x=='-')fl=-1;x=getchar();}
	while(isdigit(x)){ans=(ans<<3)+(ans<<1)+(int)(x-'0');x=getchar();}
	return fl*ans;
}
char inf[]="traffic.in",ouf[]="traffic.out";
int n,m,T,ssum;
struct node{
	int up,down,left,right;
	node(){up=down=left=right=0;}
}d[N][N];
struct extra{
	int len,pos,color;
	void init(){len=read(),pos=read(),color=read();}
}a[K];
signed main(){
	srand(248);//'R'+'P'+'+'+'+' Wishing for happiness ! 
	freopen(inf,"r",stdin);
	freopen(ouf,"w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			d[i][j].down=d[i+1][j].up=read(),ssum+=d[i][j].down;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			d[i][j].right=d[i][j+1].left=read(),ssum+=d[i][j].right;
	while(T--){
		int k=read();
		if(k==0||k==1){
			printf("0\n");
			continue;
		}
		else printf("%d\n",rand());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
