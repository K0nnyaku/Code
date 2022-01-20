#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define N 100010
using namespace std;
const ll dx[4]={0,0,1,-1};
const ll dy[4]={1,-1,0,0};
ll n,m,t,k,b1[510][510],b2[510][510],x,y,xxx,yyy,ww,www,op1,op2,c1,c2,vis[510][510],a[510][510],ans=0;
void jie(ll xx){
	if(1<=xx&&xx<=m){x=1;y=xx;}
	if(m+1<=xx&&xx<=m+n){x=xx-m;y=m;}
	if(m+n+1<=xx&&xx<=m+m+n){x=n;y=m-(xx-n-m)+1;}
	if(m+m+n+1<=xx&&xx<=(m+n)*2){x=n-(xx-m-m-n)+1;y=1;}
}
void dfs(ll x,ll y){
	for(ll i=0;i<4;i++){
		ll nx=x+dx[i],ny=y+dy[i];
		if(!(nx>=1&&nx<=n&&ny>=1&&ny<=m))continue;
		if(nx==xxx&&ny==yyy)continue;
		if(vis[nx][ny])continue;
		vis[nx][ny]=1;
		ll sum=0;
		if(a[nx-1][ny]!=a[nx][ny])sum+=b1[nx-1][ny];
		if(a[nx+1][ny]!=a[nx][ny])sum+=b1[nx][ny];
		if(a[nx][ny-1]!=a[nx][ny])sum+=b2[nx][ny-1];
		if(a[nx][ny+1]!=a[nx][ny])sum+=b2[nx][ny];
		if(sum>=b1[nx-1][ny]+b1[nx][ny]+b2[nx][ny-1]+b2[nx][ny]-sum){
			a[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
	for(ll i=1;i<n;i++)for(ll j=1;j<=m;j++)scanf("%lld",&b1[i][j]);
	for(ll i=1;i<=n;i++)for(ll j=1;j<m;j++)scanf("%lld",&b2[i][j]);
	while(t--){
		scanf("%lld",&k);
		if(k==1){
			scanf("%lld%lld%lld",&ww,&op1,&c1);
			printf("0\n");
			continue;
		}	
		scanf("%lld%lld%lld",&ww,&op1,&c1);
		scanf("%lld%lld%lld",&www,&op2,&c2);
		if(c1==c2){
			printf("0\n");
			continue;
		}	
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		jie(op2);
		xxx=x;yyy=y;
		jie(op1);
		vis[x][y]=1;
		a[x][y]=1;
		dfs(x,y);
		ans=0;
		for(ll i=1;i<n;i++)for(ll j=1;j<=m;j++)if(a[i][j]!=a[i+1][j])ans+=b1[i][j];
		for(ll i=1;i<=n;i++)for(ll j=1;j<m;j++)if(a[i][j]!=a[i][j+1])ans+=b2[i][j];
		ans=min(ans,min(ww,www));
		cout<<ans<<endl;
	}
	return 0;
}
