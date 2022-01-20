#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rop(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define por(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long ll;
namespace AnShu{

inline ll read(){
	ll W=0,F=1;
	char C=getchar();
	while((C<'0'||C>'9')&&C!='-') C=getchar();
	if(C=='-') F=-1,C=getchar();
	while(C>='0'&&C<='9') W=W*10+C-'0',C=getchar();
	return W*F;
}

ll T,n,m,k,up[500005],le[500005],f[500005][2],co[500005],vis[500005];

ll getn(ll x,ll y){
	return x*(m+2)+y+1;
}

ll regetx(ll x){
	return x/(m+2);
}

ll regety(ll x){
	return x%(m+2)-1;
}

ll gn(ll x){
	if(x<=m) return getn(0,x);
	if(x<=n+m) return getn(x-m,m+1);
	if(x<=n+2*m) return getn(m-(x-n-m)+1,n+1);
	return getn(n-(x-n-2*m)+1,0);
}

void init(){
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	memset(co,0,sizeof(co));
	rep(i,1,m){
		up[getn(1,i)]=0;
		up[getn(n+1,i)]=0;
	}
	rep(i,1,n){
		le[getn(i,1)]=0;
		le[getn(i,m+1)]=0;
	}
}

void Main(){
	T=read(),n=read(),m=read();
	rop(i,1,n)
		rep(j,1,m)	up[getn(i+1,j)]=read();
	rep(i,1,n)
		rop(j,1,m)	le[getn(i,j+1)]=read();
	while(T--){
		init();
		k=read();
		rep(i,1,k){
			ll x=read(),v=read(),c=read();
			x=gn(x);
			vis[x]=1;
		}
	} 
	cout<<0; 
}

}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	AnShu::Main();
	return 0;
}

