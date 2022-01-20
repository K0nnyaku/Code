#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define EN putchar('\n')
#define INT_INF (int)(0x3f3f3f3f)
#define LL_INF (long long)(0x3f3f3f3f3f3f3f3f)
inline int read(){
	register int x=0;register int y=1;
	register int c=getchar();
	while(c<'0'||c>'9') y&=(c!='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
	return y?x:-x;
}
#define mod 1000000007
inline void add(int &a,int b){a=(a+b>=mod)?(a+b-mod):(a+b);}
#define N 506
int n,k;
int f[N][N],h[N][N];
char s[N];
int main(){
		freopen("bracket.in","r",stdin);
		freopen("bracket.out","w",stdout);
	n=read();k=read();
	scanf("%s",s+1);
	if(n==1) return puts("0"),0;
	for(int i=1;i<n;i++)if((s[i]=='('||s[i]=='?')&&(s[i+1]==')'||s[i+1]=='?')) f[i][i+1]=h[i][i+1]=1;
	for(int len=3;len<=n;len++){
		for(int i=1,j=len;j<=n;i++,j++){
			if(s[i]=='*'||s[j]=='*'||s[i]==')'||s[j]=='('){
				f[i][j]=h[i][j]=0;continue;
			}
			if((s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?')){
				add(f[i][j],f[i+1][j-1]);
				for(int p=i+1;p<j;p++){//S= [i+1,p]
					if((s[p]=='*'||s[p]=='?')&&p-i<=k) add(f[i][j],f[p+1][j-1]);
					else break;
				}
				for(int p=j-1;p>i;p--){//S= [p,j-1]
					if((s[p]=='*'||s[p]=='?')&&j-p<=k) add(f[i][j],f[i+1][p-1]);
					else break;
				}
				int ff=1;
				for(int p=i+1;p<j;p++)if(s[p]!='*'&&s[p]!='?'){ff=0;break;}
				if(ff&&j-i-1<=k) add(f[i][j],1);
			}
			h[i][j]=f[i][j];
			int l=j+1,r=j,now=0;
			for(int p=j-2;p>=i;p--){
				if(r>p+k+1) add(now,(mod-h[r--][j])%mod);
				if(l>p+2) add(now,h[--l][j]);
				if(s[p+1]!='*'&&s[p+1]!='?') l=p+1,r=p+1,now=h[p+1][j];
				if(s[p+1]=='*'||s[p+1]=='?') add(f[i][j],(long long)now*f[i][p]%mod);
			}
			for(int p=i;p<j;p++) add(f[i][j],(long long)f[i][p]*h[p+1][j]%mod);
//				printf("[%d %2d]: f= %d  g= %d  h= %d\n",i,j,f[i][j],g[i][j],h[i][j]);
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
/*
10 2
???(*??(?)
*/
