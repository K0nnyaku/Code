#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N=20;
int n,m,T,a[N][N],b[N][N],val[40000005],power[N*N],col[N*N],k,x[N],id[N],co[N],ans,sum;
long long maxx;
bool query(long long s,int x){
	return s/power[x]%2;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	maxx=pow(2,n*m)-1;
	power[0]=1;
	for(int i=1;i<=n*m;++i)
		power[i]=2*power[i-1];
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)	
			scanf("%d",&b[i][j]);
	for(long long s=0,tmp;s<=maxx;++s){
		tmp=s;
		for(int i=0;i<n*m;++i){
			col[i]=tmp%2;
			tmp/=2;
		}
		for(int i=1;i<n;++i)
			for(int j=1;j<=m;++j)
				if(col[(i-1)*m+j-1]!=col[i*m+j-1])
					val[s]+=a[i][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<m;++j)	
				if(col[(i-1)*m+j-1]!=col[(i-1)*m+j])
					val[s]+=b[i][j];
	}
	while(T--){
		scanf("%d",&k);
		for(int i=1;i<=k;++i)
			scanf("%d%d%d",&x[i],&id[i],&co[N]);
		ans=0;
		for(long long s=0,tmp;s<=maxx;++s){
			sum=val[s];
			for(int i=1;i<=k;++i){
				if(id[i]<=m){
					if(query(s,id[i]-1)!=co[i]) sum+=x[i];
				}
				else if(id[i]>m&&id[i]<=n+m){
					if(query(s,(id[i]-m-1)*m+m-1)!=co[i]) sum+=x[i];
				}
				else if(id[i]>n+m&&id[i]<=n+2*m){
					if(query(s,(n-1)*m+2*m+n-id[i])!=co[i]) sum+=x[i];
				}
				else{
					if(query(s,(2*n+2*m-id[i])*m)!=co[i]) sum+=x[i];
				}
			}
			if(sum>ans) ans=sum;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
