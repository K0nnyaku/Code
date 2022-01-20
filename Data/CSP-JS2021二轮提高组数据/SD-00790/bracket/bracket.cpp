#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b)for(int i=(a),ed##i=(b);i<=ed##i;++i)
#define re(i,a)rep(i,1,a)
#define per(i,a,b)for(int i=(a),ed##i=(b);i>=ed##i;--i)
#define in Read()
#define up(a,b) (((a)<(b))and((a)=(b)))
#define down(a,b) (((a)>(b))and((a)=(b)))
#define dbg(x) (cerr<<#x" = "<<(x)<<'\n')
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define each(x,y) for(auto&&x:(y))

typedef long long ll;
typedef unsigned long long ull;

int Read(){
	int x=0,c=getchar();
	while(not isdigit(c))c=getchar();
	while(isdigit(c))x*=10,x+=c^'0',c=getchar();
	return x;
}

void out(int x){
	printf("%d",x);
}
void out(ll x){
	printf("%lld",x);
}
#define ENDL putchar('\n')

const int N=509;
const int mo=1e9+7;

// f[l][r] [l,r] 合法的方案
int m,n,f[N][N],qzh[N],g[N][N];
char s[N];
inline void Add(int&x,int y){
	x+=y;if(x>=mo)x-=mo;
}

signed main(){
	fio("bracket");
	n=in;m=in;scanf("%s",s+1);
	re(i,n)qzh[i]=qzh[i-1]+(s[i]=='?' or s[i]=='*');
	rep(len,2,n){
		re(l,n){
			int r=l+len-1;
			if(r>n)break;
			if(len>=2 and !(s[l]== ')' or s[l]=='*' or s[r]=='*' or s[r]=='(')){
				// () and (S)
				if(r-1-(l+1)+1<=m){
					Add(f[l][r],(qzh[r-1]-qzh[l])==r-l-1);
					Add(g[l][r],(qzh[r-1]-qzh[l])==r-l-1);
				}
//				if(l==6 and r==10)dbg(f[l][r]);
				// (A)
				Add(f[l][r],f[l+1][r-1]);
				Add(g[l][r],f[l+1][r-1]);
//				if(l==6 and r==10)dbg(f[l][r]);
				// (SA)
				rep(k,l+1,r-2){
					// [l+1,k] S
					// [k+1,r-1] A
					if(k-(l+1)+1>m)break;
					bool b =(qzh[k]-qzh[l])==k-l;
					if(not b)break;
					Add(f[l][r],f[k+1][r-1]);
					Add(g[l][r],f[k+1][r-1]);
				}
//				if(l==6 and r==10)dbg(f[l][r]);
				// (AS)
				per(k,r-2,l+1){
					// [l+1,k] A
					// [k+1,r-1] S
					if(r-1-(k+1)+1>m)break;
					bool b =(qzh[r-1]-qzh[k])==r-k-1;
					if(not b)break;
					Add(f[l][r],f[l+1][k]);
					Add(g[l][r],f[l+1][k]);
				}
			}
//			if(l==6 and r==10)dbg(f[l][r]);
			// AB
			rep(k,l,r-1){
				Add(f[l][r],1ll*f[l][k]*g[k+1][r]%mo);
			}
//			if(l==6 and r==10)dbg(f[l][r]);
			// ASB
			rep(k,l,r-1){
				rep(k2,k+1,r-1){
					// [l,k] A
					// [k+1,k2] S
					// [k2+1,r] B
					if(k2-(k+1)+1>m)break;
					bool b =(qzh[k2]-qzh[k])==k2-k;
					if(not b)break;
					Add(f[l][r],1ll*f[l][k]*g[k2+1][r]%mo);
				}
			}
//			cerr<<l<<' '<<r<<' '<<f[l][r]<<'\n';
		}
	}
	out(f[1][n]),ENDL;
//	dbg(f[1][n]);
	return 0;
}
