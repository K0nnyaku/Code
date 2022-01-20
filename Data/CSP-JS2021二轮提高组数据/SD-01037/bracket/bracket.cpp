#include<cstdio>
#define ll long long
ll f[505][505];
const ll P=1e9+7;
ll F(int n,int k){
	if(n==0) return 1;
	else if(n==1) return 0;
	else if(n==2) return 1;
	else if(n==3) return k>=1;
	else if(f[n][k]) return f[n][k];
//	printf("%d %d\n",n,k);
	ll rtn=0;
	int i,j;
	rtn+=F(n-2,k);
	rtn%=P;
	if(n-2<=k) ++rtn;
	for(i=1;i<=k&&n-i-2>0;++i){
		rtn+=F(n-i-2,k)*2;
		rtn%=P;
	}
	for(i=1;i<=n;++i){
		for(j=0;j<=k&&j+i<n;++j){
			rtn+=F(i,k)*F(n-i-j,k);
			rtn%=P;
			rtn%=P;
		}
	}
	rtn%=P;
	return f[n][k]=rtn;
}
int main(){
	int n,k;
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	printf("%lld\n",F(n,k));
	
	return 0;
}
