#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
ll n,m,T;
ll hang[505][505],lie[505][505];
ll X[60],Y[60];
ll K,x[60],p[60],t[60];
ll vis[505][505];
ll ans;
void dfs(ll ,ll );
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&T);
	for(ll i=1;i<n;i++){
		for(ll j=1;j<=m;j++){
			scanf("%lld",&hang[i][j]);
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<m;j++){
			scanf("%lld",&lie[i][j]);
		}
	}
	while(T--){
		scanf("%lld",&K);
		for(ll i=1;i<=K;i++){
			scanf("%lld %lld %lld",&x[i],&p[i],&t[i]);
		}
		ans=1145141919810*114514;
		dfs(1,1);
		printf("%lld\n",ans);
	}
	return 0;
}
void dfs(ll R,ll C){
	if(C>m){
		R++;
		C=1;
	}
	if(R==n+1){
		ll cnt=0,cun;
		for(ll i=1;i<n;i++){
			for(ll j=1;j<=m;j++){
				if(vis[i][j]!=vis[i+1][j]){
					cnt+=hang[i][j];
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<m;j++){
				if(vis[i][j]!=vis[i][j+1]){
					cnt+=lie[i][j];
				}
			}
		}
		for(ll i=1;i<=K;i++){
			if(p[i]>2*m+n){
				cun=n-(p[i]-(2*m+n))+1;
				if(vis[cun][1]!=t[i])cnt+=x[i];
			}else if(p[i]>m+n){
				cun=m-(p[i]-(n+m))+1;
				if(vis[n][cun]!=t[i])cnt+=x[i];
			}else if(p[i]>m){
				cun=p[i]-m;
				if(vis[cun][m]!=t[i])cnt+=x[i];
			}else{
				cun=p[i];
				if(vis[1][cun]!=t[i])cnt+=x[i];
			}
		}
		ans=min(cnt,ans);
		return;
	}
	vis[R][C]=0;
	dfs(R,C+1);
	vis[R][C]=1;
	dfs(R,C+1);
	return;
}
