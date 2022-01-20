#include <cstdio>
#include <algorithm>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=1e3+7,INF=1e9+7,Mod=998244353;
int T,n,m,a[N][N],b[N][N],ex[N][N][2],exw[N][N][2],exc[N][N][2],z,f[1000000][2];

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	n=read(),m=read(),T=read(),z=(1<<m);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++)b[i][j]=read();
	}
	for(int i=1;i<=n;i++)ex[i][1][0]=ex[i][m][0]=ex[i][1][1]=ex[i][m][1]=0;
	for(int i=1;i<=m;i++)ex[1][i][0]=ex[n][i][0]=ex[1][i][1]=ex[n][i][1]=0;
	
	while(T--){
		int k=read(),ans=INF;
		for(int i=1,w,p,cl;i<=k;i++){
			w=read(),p=read(),cl=read();
			int x,y,ty;
			if(p<=m)x=1,y=p,ty=0;
			else if(p<=n+m)x=p-m,y=m,ty=1;
			else if(p<=2*m+n)x=n,y=m-(p-n-m)+1,ty=0;
			else x=n-(p-2*m-n)+1,y=1,ty=1;
			//printf("(%d %d)",x,y);
			ex[x][y][ty]=1,exw[x][y][ty]=w,exc[x][y][ty]=cl;
			//printf("exc[%d][%d]=%d\n",x,y,cl);
		}
	
	
	int t=0;
	for(int p=0;p<z;p++){
		int sum=0;
		for(int i=0;i<m;i++){
			int c=(p&(1<<i))?1:0;//printf("!exc[%d][%d]=%d",1,i+1,exc[1][i+1]);
			if(ex[1][i+1][0]&&c!=exc[1][i+1][0])sum+=exw[1][i+1][0];
			
			if(i==0&&ex[1][1][1]&&c!=exc[1][1][1])sum+=exw[1][1][1];
			if(i==m-1&&ex[1][m][1]&&c!=exc[1][m][1])sum+=exw[1][m][1];
			
			if(i==m-1)break;
			int c1=(p&(1<<i))?1:0,c2=(p&(1<<(i+1)))?1:0;
			if(c1!=c2)sum+=b[1][i+2];
		}
		f[p][t]=sum;
	}
	for(int i=2;i<n;i++){
		t^=1;
		for(int p=0;p<z;p++){
			f[p][t]=INF;
			for(int p2=0;p2<z;p2++){
				int sum=f[p2][t^1];
				for(int j=0;j<m;j++){
					int c1=(p&(1<<j))?1:0,c2=(p2&(1<<j))?1:0;
					if(c1!=c2)sum+=a[i][j+1];
					if(j==0&&ex[i][1][1]&&c1!=exc[i][1][1])sum+=exw[i][1][1];
					if(j==m-1&&ex[i][m][1]&&c1!=exc[i][m][1])sum+=exw[i][m][1];
					c1=(p&(1<<j))?1:0,c2=(p&(1<<(j+1)))?1:0;
					if(j==m-1)break;
					if(c1!=c2)sum+=b[i][j+2];
				}
				f[p][t]=min(f[p][t],sum);
			}
		}
	}
	t^=1;
	for(int p=0;p<z;p++){
		f[p][t]=INF;
		for(int p2=0;p2<z;p2++){
			int sum=f[p2][t^1];
			for(int j=0;j<m;j++){
				int c1=(p&(1<<j))?1:0,c2=(p2&(1<<j))?1:0;
				if(c1!=c2)sum+=a[n][j+1];
				if(ex[n][j+1][0]&&exc[n][j+1][0]!=c1)sum+=exw[n][j+1][0];
				if(j==0&&ex[n][1][1]&&c1!=exc[n][1][1])sum+=exw[n][1][1];
				if(j==m-1&&ex[n][m][1]&&c1!=exc[n][m][1])sum+=exw[n][m][1];
				if(j==m-1)break;
				c1=(p&(1<<j))?1:0,c2=(p&(1<<(j+1)))?1:0;
				if(c1!=c2)sum+=b[n][j+2];
			}
			f[p][t]=min(f[p][t],sum);
		}
		//printf("%d %d %d\n",p,f[p][t],f[p][t^1]);
		ans=min(ans,f[p][t]);
	}
	printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
