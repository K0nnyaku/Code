#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n,m,t,w,cnt,h[10000010];
ll a[1010][1010];
struct Node{
	ll to,next;
	ll w;
}e[1000010];
void add(ll x,ll y,ll xx,ll yy,ll w){
	e[++cnt].to=a[xx][yy];
	e[cnt].w=w;
	e[cnt].next=h[a[x][y]];
	h[a[x][y]]=cnt;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
/*	for(ll i=1;i<n;i++){
		for(ll j=1;j<=m;j++){
			scanf("%lld%lld",&w);
			add(i,j,i+1,j,w);
		}
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<m;j++){
			scanf("%lld%lld",&w);
			add(i,j,i,j+1,w);
		}
	}*/
	for(ll i=1;i<=t;i++){
		//for(ll j=1;j<=k;j++){
		//	
		//}
		cnt=rand();
		printf("%lld\n",cnt);
	}
	return 0;
}
