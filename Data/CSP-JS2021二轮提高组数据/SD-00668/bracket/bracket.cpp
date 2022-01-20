#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
ll read(){
   ll x=0,f=1;char c=getchar();
   while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
   while(isdigit(c))x=x*10+c-'0',c=getchar();
   return x*f;
}
const int N=1000,MOD=1e9+7;
ll f[N][N];
ll g[N][N],gl[N][N],gr[N][N],b[N][N],bl[N][N];
char s[N];
int n,m;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int len=0;len<n;len++){
		for(int l=1;l<=n-len;l++){
			int r=l+len;
			if(r-l+1<=m){
				int delta=1;
				for(int k=l;k<=r;k++)
					if(s[k]!='?'&&s[k]!='*')
						delta=0;
				g[l][r]=delta;
			}
			if(l==r)continue;
			for(int k=l;k<r;k++)
				(gl[l][r]+=g[l][k]*((f[k+1][r]+b[k+1][r])%MOD)%MOD)%=MOD;
			for(int k=l;k<r;k++)
				(bl[l][r]+=g[l][k]*b[k+1][r]%MOD)%=MOD;
			for(int k=r;k>l;k--)
				(gr[l][r]+=g[k][r]*((f[l][k-1]+b[l][k-1])%MOD)%MOD)%=MOD;
			if((s[l]=='?'||s[l]=='(')&&(s[r]=='?'||s[r]==')')){
				b[l][r]=(f[l+1][r-1]+g[l+1][r-1]+gl[l+1][r-1]+gr[l+1][r-1]+b[l+1][r-1])%MOD;
				if(l+1==r)
					b[l][r]=(b[l][r]+1)%MOD;
			}
			for(int k=l;k<r;k++)
				(f[l][r]+=(f[l][k]+b[l][k])%MOD*b[k+1][r]%MOD)%=MOD;
			for(int k=l;k<r;k++)
				(f[l][r]+=(f[l][k]+b[l][k])%MOD*bl[k+1][r]%MOD)%=MOD;
		}
	}
	cout<<(f[1][n]+b[1][n])%MOD<<endl;
	return 0;
}

/*
7 3
(*??*??

10 2
???(*??(?)

100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????

(()(*)) (*)
()((*)) (*)
()*(**) (*)
(*)(**) (*)
(**(*)) (*)

(*)(*) *(*)
()*(*) *(*)

(*)(*) (())
()*(*) (())

() *(*()())

(*) (*()())

() ((*)*())
() ((**)())

(()(*)*())
(()(**)())
((*(*))())
(*((*))())
(**(*)*())
(**(**)())

500 57
????*???***??*?????(????????*?**??????(??????????*??**??*?????????????????????*??????????*?????**????*?????????????????????*?????????????????????????????????*)*?????*????*??*???????????*????????????????*?????*?????*?*???)?????????*????*???*??????????????*???????????????????????*?????*?????*????????????????**??*?????????*?????????????????*??**?????????????*????**?*??*??*??????????*???*??**?(?*???????????????????????????**???????????***??????????*???????*)*???*?????????????????????*????????*????*?

*/










