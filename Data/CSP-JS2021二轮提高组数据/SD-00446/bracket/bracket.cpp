#include<cstdio>
const int mod=1000000007;
int n,k,f[510][510][510][2][2],ans;
char s[510];
inline int read(){
	register char ch=getchar();int f=1,x=0;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline int add(int x,int y){return (1ll*x+y>=mod)?(1ll*x+y-mod):(x+y);}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	//freopen("data.in","r",stdin);
	n=read();k=read();
	scanf("%s",s+1);
	f[0][0][0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			if((s[i]=='('||s[i]=='?')&&j>=1){
				for(int p=0;p<=min(max(i-2,0),k);++p){
					f[i][j][0][0][0]=add(f[i][j][0][0][0],f[i-1][j-1][p][0][0]);
					f[i][j][0][0][0]=add(f[i][j][0][0][0],f[i-1][j-1][p][1][0]);
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j-1][p][0][1]);
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j-1][p][1][1]);
				}
			}
			if(s[i]==')'||s[i]=='?'){
				for(int p=0;p<=min(max(i-2,0),k);++p){
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j+1][p][0][1]);
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j+1][p][0][0]);
					f[i][j][0][0][0]=add(f[i][j][0][0][0],f[i-1][j+1][p][1][0]);
					f[i][j][0][0][0]=add(f[i][j][0][0][0],f[i-1][j+1][p][1][1]);
				}
			}
			if(s[i]=='*'||(s[i]=='?'&&i!=1)){
				for(int p=1;p<=min(max(i-2,0),k-1);++p){
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j+1][p][0][1]);
					f[i][j][0][0][1]=add(f[i][j][0][0][1],f[i-1][j+1][p][0][0]);
				}
			}
		}
	}
	ans=add(ans,f[n][0][0][1][1]);
	ans=add(ans,f[n][0][0][1][0]);
	ans=add(ans,f[n][0][0][0][1]);
	ans=add(ans,f[n][0][0][0][0]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
