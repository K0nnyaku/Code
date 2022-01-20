#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
const int N=510;
int n,m,t,k;
unsigned int lenth[N][N],height[N][N];
unsigned int curl[N][N],curh[N][N];
ull ans;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(register int i=1;i<n;i++)
		for(register int j=1;j<=m;j++)
			scanf("%u",&height[i][j]);
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<m;j++)
			scanf("%u",&lenth[i][j]);
	while(t--){
		ans=0ull;
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=m;j++){
				curl[i][j]=lenth[i][j];
				curh[i][j]=height[i][j];
			}
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x,p,color;
			scanf("%d%d%d",&x,&p,&color);
			if(p<=m){
				unsigned int maxn=0;
				int pointer;
				for(int j=1;j<=n;j++){
					if(curh[j][p]>maxn){
						maxn=curh[j][p];
						pointer=j;
					}
				}
				curh[pointer][p]=x;
			}else if(p>(m+n)&&p<=(2*m+n)){
				unsigned int maxn=0;
				int pointer;
				for(int j=1;j<=n;j++){
					if(curh[j][(2*m+n+1-p)]>maxn){
						maxn=curh[j][(2*m+n+1-p)];
						pointer=j;
					}
				}
				curh[pointer][(2*m+n+1-p)]=x;
			}else if(p>m&&p<=(m+n)){
				unsigned int maxn=0;
				int pointer;
				for(int j=1;j<=m;j++){
					if(curl[p-m][j]>maxn){
						maxn=curl[p-m][j];
						pointer=j;
					}
				}
				curl[p-m][pointer]=x;
			}else{
				unsigned int maxn=0;
				int pointer;
				for(int j=1;j<=m;j++){
					if(curl[(2*m+2*n+1-p)][j]>maxn){
						maxn=curl[(2*m+2*n+1-p)][j];
						pointer=j;
					}
				}
				curl[(2*m+2*n+1-p)][pointer]=x;
			}
		}
		for(register int i=1;i<n;i++)
			for(register int j=1;j<=m;j++)
				ans+=(ull)curh[i][j];
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<m;j++)
				ans+=(ull)curl[i][j];
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
