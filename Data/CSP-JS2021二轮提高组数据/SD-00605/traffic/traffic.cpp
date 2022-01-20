//T4 ???2^n???
#include<iostream>
#include<cstdio>
const int N=20,M=20;
using namespace std;
int read(){
 	int x=0,f=1;char ch=getchar();
 	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,T,cnt=0;
int col[N][M],vis[N][M],a[N][M][N][M];
long long ans=0x7ffffff,tot;
void dfs(int x,int y){
    for (int k=0;k<=1;k++){
	  cnt++;
      col[x][y]=k;
      vis[x][y]=1;
	  if (cnt==n*m){
	  	tot=0;
	  	for (int i=0;i<=n;i++)
	  	  for (int j=0;j<=m;j++){
	  	    if (col[i][j]!=col[i+1][j]){
	  	      tot+=a[i][j][i+1][j];
	  	    } 
	  	    if (col[i][j]!=col[i][j+1]){
	  	      tot+=a[i][j][i][j+1];
	  	    }
	  	  }
		  ans=min(ans,tot);
	  	  return;
      }
      for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
          if (!vis[i][j]) dfs(i,j);
      col[x][y]=0;
      vis[x][y]=0;
      cnt--;
    }
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	if (n>=100||m>=100){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<n;i++){
	  for (int j=1;j<=m;j++){
		int w=read();
		a[i][j][i+1][j]=w;
	  }
    }
	for (int i=1;i<=n;i++){
		for (int j=1;j<m;j++){
			int w=read();
			a[i][j][i][j+1]=w;
		}
	}
    while (T--){
    	int k=read();
    	for (int i=1;i<=k;i++){
    		int dis=read(),xy=read(),col1=read();
    		int x=0,y=0,x1=0,y1=0;
    		if (xy<=m)
    		  x=0,y=xy,x1=1,y1=xy;
    		if (xy>m&&xy<=m+n)
    		  x=xy-m,y=m+1,x1=xy-m,y=m;
    		if (xy>m+n&&xy<=2*m+n)
    		  x=n+1,y=m-(xy-m-n)+1,x1=n,y1=m-(xy-m-n)+1;
    		if (xy>2*m+n)
    		  x=n-(xy-2*m-n)+1,y=0,x1=n-(xy-2*m-n)+1,y1=1;
    		a[x][y][x1][y1]=dis;
    		a[x1][y1][x][y]=dis;
    		col[x][y]=col1;
    	}
		dfs(1,1);
		cout<<ans<<endl;
    }
    return 0;
}

