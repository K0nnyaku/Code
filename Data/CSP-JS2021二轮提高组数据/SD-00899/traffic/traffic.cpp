#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define int ll
#define foredge(i) int i=head[u],v=edges[i].to;i;i=edges[i].nxt,v=edges[i].to

using namespace std;
const ll N=100005,M=400005;
ll read(){
	ll x=0,i=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')i=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return i!=0?x:-x;
}

void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void write(ll x,char c){
	if(x<0)putchar('-'),write(-x);
	else write(x);
	putchar(c);
}
int t,n,m;
int w[1005][1005];
int c[1005],x[1005],val[1005];
int exc[105];
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	F(i,1,n-1){
		F(j,1,m){
			int x=read();
			w[i*m-m+j][i*m+j]=w[i*m+j][i*m-m+j]=x;
		} 
	}
	F(i,1,n){
		F(j,1,m-1){
			int x=read();
			w[i*m-m+j][i*m-m+j+1]=w[i*m-m+j+1][i*m-m+j]=x;
		} 
	}
	F(i,1,t){
		int k=read();
		F(i,1,k){
			val[i]=read(),x[i]=read(),exc[i]=read();
		}
		ll ans=0x3f3f3f3f;
		F(i,1,1<<(n*m)){
			memset(c,0,sizeof(c));
			int k=i,pos=1;
			while (k){
				c[pos]=k&1;
				k>>=1;
			}
			ll res=0;
			F(i,1,n-1){
				F(j,1,m){
					if(c[i*m-m+j]!=c[i*m+j]) res+=w[i*m+j][i*m-m+j];
				}
			}
			F(i,1,n){
				F(j,1,m-1){
					if (c[i*m-m+j]!=c[i*m-m+j+1]) res+=w[i*m-m+j+1][i*m-m+j];
				} 
			}
			F(i,1,k){
				int to;
				if(x[i]<=m){
					to=x[i];
				}
				else if(x[i]>m&&x[i]<=n+m){
					to=(x[i]-m)*m;
				}
				else if(x[i]>n+m&&x[i]<=n+2*m){
					to=n*m-(x[i]-n-m)+1;
				}
				else {
					to=(n-(x[i]-n-m-m))*m;
				}
				if(c[to]!=exc[i]) res+= val[i];
			}
			ans=min(ans,res);
		}
		write(ans,'\n');
	}
	return 0;
}

