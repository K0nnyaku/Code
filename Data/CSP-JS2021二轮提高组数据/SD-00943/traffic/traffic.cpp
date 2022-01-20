#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=501;
#define re register int
#define ll long long
int read(){
	int x=0,mark=1;char c=getchar();
	while(c<'0'||c>'9'){if (c=='-')mark=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*mark;
}
int x1[N][N],x2[N][N],col[N];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n=read(),m=read(),T=read();
	for (re i=1;i<n;i++){//(i,j)->(i+1,j)
		for (re j=1;j<=m;j++) x1[i][j]=read();
	}
	for (re i=1;i<=n;i++){//(i,j)->(i,j+1)
		for (re j=1;j<=m-1;j++) x2[i][j]=read();
	}
	while (T--){
		int ki=read(),maxn=1e9,x;
		bool mark=1;
		int num;
		for (re i=1;i<=ki;i++){
			x=read(),maxn=min(maxn,x);num=read(),col[i]=read();
		}
		if (ki==1||col[1]==col[2])puts("0");
		else printf("%d\n",maxn); 
	}
	fclose(stdin);
	fclose(stdout);
return 0;}


