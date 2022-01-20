#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
typedef long long ll;
const int N = 510;
int n,m,T,a[N*N],b[N*N],k;
int x3,p,t;
int vv_sz[N*N],vv_sp[N*N];
ll ans=100000000000000000;
int v[N*N],val_sz[N*N],val_sp[N*N];
void dfs(int dep,ll now){
	if(now>=ans) return; 
	if(dep==n*m){
		ans=min(ans,now);
		return;
	}
	for(int i=0;i<=1;i++){
		v[dep+1]=i;
		ll pan=0;
		if((dep+1)%m!=1&&v[dep+1]!=v[dep]) pan+=a[dep];
		if(dep+1>m&&v[dep+1-m]!=v[dep+1]) pan+=b[dep+1-m];
		if(vv_sz[dep+1]&&vv_sz[dep+1]-1!=v[dep+1]) pan+=val_sz[dep+1];
		if(vv_sp[dep+1]&&vv_sp[dep+1]-1!=v[dep+1]) pan+=val_sp[dep+1];
		dfs(dep+1,now+pan);
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&b[(i-1)*m+j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%d",&a[(i-1)*m+j]);
		}
	}
	while(T--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&x3,&p,&t);
			if(p<=m){
				vv_sz[p]=t+1;
				val_sz[p]=x3;
			}
			else if(p>m&&p<=m+n){
				vv_sp[(p-m)*m]=t+1;
				val_sp[(p-m)*m]=x3;
			}
			else if(p>m+n&&p<=2*m+n){
				int poi=p-(m+n);
				vv_sz[(n-1)*m+(m-poi+1)]=t+1;
				val_sz[(n-1)*m+(m-poi+1)]=x3;
			}
			else{
				int poi=p-(2*m+n);
				vv_sp[(n-poi)*m+1]=t+1;
				val_sp[(n-poi)*m+1]=x3;
			}
		}
		ans=100000000000000000;
		dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0

*/
