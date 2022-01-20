#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
#define qwq 507
const ll mod=1e9+7;
int n,k;
char s[qwq];
inline void read(){
	n=0;
	char c=getchar();
	for(;c!='('&&c!=')'&&c!='?'&&c!='*';c=getchar());
	for(;c=='('||c==')'||c=='?'||c=='*';c=getchar())s[++n]=c;
	return ;
}
inline bool cbc(int l,char c){
	if(s[l]==c)return true;
	if(s[l]=='?')return true;
	return false;
}
bool lrcbs[qwq][qwq];
ll f[2][qwq][qwq];//1:有*断点 0:无*断点 
ll h[qwq][qwq];
ll g[qwq][qwq];
void initcbs(){
	for(int l=1;l<=n;++l){
		lrcbs[l][l]=cbc(l,'*');
		for(int r=l+1;r<=n;++r){
			if(r-l+1>k)break;
			if(!lrcbs[l][r-1]){
				break;
			}
			lrcbs[l][r]=cbc(r,'*');
		}
	}
//	for(int l=1;l<=n;++l){
//		for(int r=l;r<=n;++r){
//			printf("[%d,%d]:%d\n",l,r,lrcbs[l][r]);
//		}
//	}
	return ;
}
inline bool cbs(int l,int r){
	return lrcbs[l][r];
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	read();
//	for(int i=1;i<=n;++i)putchar(s[i]);
	initcbs();
	for(int len=2;len<=n;++len){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			if(cbc(l,'(')&&cbc(r,')')){
				if(len==2){
					f[0][l][r]+=1;
				}
				else {
					f[0][l][r]+=f[0][l+1][r-1]+f[1][l+1][r-1]+h[l+1][r-1];f[0][l][r]%=mod;
					if(cbs(l+1,r-1))f[0][l][r]+=1,f[0][l][r]%=mod;
					for(int mid=l+1;mid+1<=r-1;++mid){
						h[l][r]+=((f[1][l][mid]+f[0][l][mid])%mod)*((h[mid+1][r]+f[0][mid+1][r]+f[1][mid+1][r])%mod)%mod;
						h[l][r]%=mod;
					}
					for(int x=l+3;x<=r-1;++x){
						f[1][l][r]+=((f[0][x][r]+f[1][x][r])%mod)*g[x][l]%mod;
						f[1][l][r]%=mod;
					}
					for(int mid=l+1;mid<=r-3;++mid){
						if(cbs(l+1,mid))f[0][l][r]+=f[0][mid+1][r-1]+f[1][mid+1][r-1]+h[mid+1][r-1],f[0][l][r]%=mod;
					}
					for(int mid=l+3;mid<=r-1;++mid){
						if(cbs(mid,r-1))f[0][l][r]+=f[0][l+1][mid-1]+f[1][l+1][mid-1]+h[l+1][mid-1],f[0][l][r]%=mod;
					}
				}
				for(int x=r+2;x<=n;++x){
					if(cbs(r+1,x-1)){
						g[x][l]+=f[0][l][r],g[x][l]%=mod;
					}
				} 
			}
		}
	}
//	for(int l=1;l<=n;++l){
//		for(int r=l;r<=n;++r){
//			printf("f[%d,%d]:%lld %lld\n",l,r,f[0][l][r],h[l][r]);
//		}
//	}
	printf("%lld\n",(f[0][1][n]+f[1][1][n]+h[1][n])%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
