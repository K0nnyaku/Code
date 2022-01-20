#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
long long n,m,T,k,w;
long long tot,ver[10010],nxt[10010],head[10010],ed[10010],x,p,t;
void add(long long x,long long y,long long z){
	tot++;
	ver[tot]=y;
	ed[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
	return;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&T);
	for(long long i=1;i<=n-1;i++){
		for(long long j=1;j<=m;j++){
			scanf("%lld",&w);
			add((i-1)*n+j,i*n+j,w);
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m-1;j++){
			scanf("%lld",&w);
			add((i-1)*n+j,(i-1)*n+j+1,w);
		}
	}
	while(T--){
		scanf("%lld",&k);
		for(long long i=1;i<=n;i++){
			scanf("%lld %lld %lld",&x,&p,&t);
			if(p<m){
				//(0,p)
				//(1,p)
//				add(,(1-1)*n+p);
			}
			if(p==m){
				//(0,m)
				//(1,m)
//				add(,(1-1)*n+m);
			}
			if(p>m&&p<=n+m){
				//(p%m,m+1)
				//(p%m,m)
//				add(,(1-1)*n+m);
			}
			if(p>n+m&&p<=2*m+n){
				//(n+1,2*m+n+1-p)
				//(n,2*m+n+1-p)
//				add(,(n-1)*n+(2*m+n+1-p));
			}
			if(p>2*m+n){
				//(2*m+2*n+1-p,0)
				//(2*m+2*n+1-p,1)
//				add(,(2*m+2*n+1-1-p)*n+1);
			}
//			add();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
