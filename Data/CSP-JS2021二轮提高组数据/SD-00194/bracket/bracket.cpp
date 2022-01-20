#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
inline int Add(int x,int y,int M=mod){return (x+y)%M;}
inline int Mul(int x,int y,int M=mod){return 1ll*x*y%M;}
inline int Dec(int x,int y,int M=mod){return (x-y+M)%M;}
inline int Min(int x,int y){return x<y?x:y;}
char buf[1<<21],*p1=buf,*p2=buf;
//char obuf[1<<21],*O=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10-'0'+ch;
		ch=getchar();
	}
	return s*w;
}
//inline void Write(int x){
//	if(x>9)Write(x/10);
//	*O++=(x%10+'0');
//}
inline int qpow(int x,int y,int M=mod){
	int res=1;
	while(y){
		if(y&1)res=Mul(res,x,M);
		x=Mul(x,x,M);
		y>>=1;
	}
	return res;
}
typedef pair<int,int> pr;
#define poly vector<int>
#define fi first
#define se second
#define mk make_pair
#define pb emplace_back
const int N=401;
int n,k;
char s[N];
int f[N][N][N][2];
inline void __FILE(){
	freopen("bracket.in","r",stdin);
	freopen("brackest.out","w",stdout);
}
signed main(){
	__FILE();
	n=read();
	k=read();
	scanf("%s",s+1);
	f[0][0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(s[i]==')'||s[i]=='('){
				int ss=0;
				if(s[i]=='('){
					f[i][j][0][0]=f[i-1][j-1][0][0];
					if(j==1){
						for(int l=1;l<=k;++l)ss=Add(ss,f[i-1][j-1][l][0]);
					}
					f[i][j][0][0]=Add(f[i][j][0][0],ss);
					if(j==1)continue;
					ss=0;
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j-1][l][1]);
					f[i][j][0][1]=Add(f[i][j][0][1],ss);
				}
				else {
					if(j){
						f[i][j][0][0]=f[i-1][j+1][0][0];
					}
					else{
						for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][0]);
						for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][1]);
						f[i][j][0][0]=Add(f[i][j][0][0],ss);
					}
					if(!j)continue;
					ss=0;
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][1]);
					f[i][j][0][1]=Add(f[i][j][0][1],ss);
				}
				continue;
			} 
			if(s[i]=='?'){
				int ss=0;
				f[i][j][0][0]=Add(f[i][j][0][0],f[i-1][j-1][0][0]);
				if(j==1){
					for(int l=1;l<=k;++l)ss=Add(ss,f[i-1][j-1][l][0]);
				}
				f[i][j][0][0]=Add(f[i][j][0][0],ss);
				if(j!=1){
					ss=0;
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j-1][l][1]);
					f[i][j][0][1]=Add(f[i][j][0][1],ss);
				}
				
				if(j!=0){
					f[i][j][0][0]=Add(f[i][j][0][0],f[i-1][j+1][0][0]);
				}
				else{
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][0]);
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][1]);
					f[i][j][0][0]=Add(f[i][j][0][0],ss);
				}
				if(j){
					ss=0;
					for(int l=0;l<=k;++l)ss=Add(ss,f[i-1][j+1][l][1]);
					f[i][j][0][1]=Add(f[i][j][0][1],ss);
				}
				
				for(int m=1;m<=k;++m){
					f[i][j][m][0]=Add(f[i][j][m][0],f[i-1][j][m-1][0]);
					f[i][j][m][1]=Add(f[i][j][m][1],Add(f[i-1][j][m-1][0],f[i-1][j][m-1][1]));
				}
				continue;
			}
			if(s[i]=='*'){
				for(int m=1;m<=k;++m){
					f[i][j][m][0]=Add(f[i][j][m][0],f[i-1][j][m-1][0]);
					f[i][j][m][1]=Add(f[i][j][m][1],Add(f[i-1][j][m-1][0],f[i-1][j][m-1][1]));
				}
			}
		}
	}
//	cout<<f[5][1][1][1]<<endl;;
//	for(int pos=1;pos<=n;++pos){
//		printf("%lld:\n",pos);
//		for(int l=0;l<=1;++l)
//		for(int i=0;i<=n;++i)
//		for(int j=0;j<=n;++j)
//		printf("(%lld %lld %lld):%lld \n",i,j,l,f[pos][i][j][l]);
//		
//		puts("-------------------------------------");
//	}
	
	printf("%lld\n",f[n][0][0][0]);
	return 0;
}

