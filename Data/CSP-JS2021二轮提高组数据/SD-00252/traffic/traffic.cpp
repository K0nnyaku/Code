#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=505;
int n,m,T,k,dis1[N][N],dis2[N][N],ans;
struct kkk{
	int num,w,col;
}q[N];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			dis1[i][j]=read();
			dis1[j][i]=dis1[i][j];
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<=n;j++){
			dis2[i][j]=read();
			dis2[j][i]=dis2[i][j];
		}
	}
	while(T--){
		k=read();
		for(int i=1;i<=k;i++){
			q[i].num=read(),q[i].w=read(),q[i].col=read();
		}
		bool f=false;
		for(int i=1;i<=k;i++){
			if(q[i].col==q[i-1].col)f=true;
			else {
				f=false;
				break;
			}
			if(k==1||f)printf("0\n");
			else if(k==2){
				ans=0;
				for(int i=1;i<n;i++){
					for(int j=1;j<=m;j++){
						ans+=dis1[i][j];
					}
				}
				for(int i=1;i<m;i++){
					for(int j=1;j<=n;j++){
						ans+=dis2[i][j];
					}
				}
				ans+=q[1].w+q[2].w;
				printf("%d\n",ans);
			}
			else printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
