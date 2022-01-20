//什么时候我才能有杜爷一半强啊/kk
#include<cstdio>
const int N=514,MOD=1e9+7;
int n,k,f[N][N],g[N][N],h[N][N];
bool p[N][N];
char ch[N];
int vAdd(int a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int Add(int &a,int b){return(a+=b)>=MOD?a-=MOD:a;}
int vSub(int a,int b){return(a-=b)<0?a+=MOD:a;}
int Sub(int &a,int b){return(a-=b)<0?a+=MOD:a;}
int Mul(int a,int b){return 1ll*a*b%MOD;}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,ch+1);
	for(int i=1;i<=n;i++)p[i][i]=(ch[i]=='*'||ch[i]=='?');
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			p[i][j]=p[i][j-1]&p[j][j];
		}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			//(A)
			if((ch[l]=='('||ch[l]=='?')&&(ch[r]==')'||ch[r]=='?')){
				if(len<=k+2)f[l][r]=p[l+1][r-1];
				if(len==2)f[l][r]=1;
				else Add(f[l][r],f[l+1][r-1]);
				for(int i=l+1;i+1<r&&i<=l+k;i++)//星号在左边
					Add(f[l][r],p[l+1][i]*f[i+1][r-1]);
				for(int i=r-1;i-1>l&&i>=r-k;i--)//星号在右边
					Add(f[l][r],p[i][r-1]*f[l+1][i-1]);
			}
			//ASB
			h[l][r]=f[l][r];
			for(int i=l;i<r;i++)
				Add(f[l][r],Mul(h[l][i],g[i+1][r]));
			g[l][r]=vAdd(g[l+1][r],f[l][r]);
			if(l+k<r&&p[l][l+k])Sub(g[l][r],f[l+k+1][r]);
			if(!(ch[l]=='*'||ch[l]=='?'))g[l][r]=f[l][r];
		}
	}
	printf("%d",f[1][n]);
	fclose(stdin);fclose(stdout);return 0;
}
