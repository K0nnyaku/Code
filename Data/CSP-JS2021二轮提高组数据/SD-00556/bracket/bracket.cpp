#include<stdio.h>
#define Mod 1000000007

int dp[510][510];
int s[510];
int avi[510][510];
int n,k;
int fz[510];
int hzh[510][510];
int rgk[510];
int maxx(int x,int y){return x>y?x:y;}
int minn(int x,int y){return x<y?x:y;}
int read(){
	char ch;int res=0,zf=1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')zf=!zf;res=(ch^48);
	while((ch=getchar())>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48);
	return zf?res:(-res);
}
int gc(){
	char ch;
	while((ch=getchar())=='\n'||ch=='\r'||ch==' ')ch=getchar();
	if(ch=='(')return 1;
	if(ch==')')return 2;
	if(ch=='*')return 3;
	return 0;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	n=read();k=read();
	for(int i=1;i<=n;i++)s[i]=gc();
	for(int i=1;i<=n;i++){
		int flag1=1;
		avi[i][i-1]=1;
		for(int j=i;j<=n;j++){
			if(s[j]==1||s[j]==2)flag1=0;
			avi[i][j]=flag1;
		//	printf("avi %d %d %d\n",i,j,avi[i][j]); 
		}
	}
	//printf("%d\n",avi[3][3]);
	for(int i=0;i<=n;i++){
		int flag1=1; 
		for(int j=i+1;j<=n;j++)
			if(s[j]==1||s[j]==2){
				rgk[i]=j;
				flag1=0;
				break;
			}
		if(flag1)rgk[i]=n+1;
	}
	//printf("qaq");
//	for(int i=1;i<=n;i++)printf("%d ",s[i]);puts(""); 
	for(int h=2;h<=n;h++)
		for(int i=1;i+h-1<=n;i++){
			int j=i+h-1;
//title 1	
			if((s[i]==1||s[i]==0)&&(s[j]==2||s[j]==0)){
				int flag1=1;
				for(int p=i+1;p<j;p++)if(s[p]==1||s[p]==2){
					flag1=0;
					break;
				}
				if(flag1&&h<=k+2){
					dp[i][h]=(dp[i][h]+1)%Mod;
				//	printf("p2p%d %d %d\n",i,j,dp[i][h]);
				}
			}
//title 2	
		//	if(k>j-i-3)kk=j-i-3;
		//	else kk=k;
/*
			if(h>2){
				int anss=dp[i+2][j-(i+2)+1];
				fz[i+2]=dp[i+2][j-(i+2)+1
				for(int p=i+2;p<=i+1+kk;p++){
					if(avi[i+2][p]){
						anss=(anss+dp[p+1][j-p])%Mod;
						fz[p+1]=dp[p+1][j-p];
					}
				}
				for(int p=i+2;p<=j-2;p++){
					dp[i][h]=(dp[i][h]+(1ll*dp[i][p-1]*anss%Mod))%Mod;
					anss=((anss-fz[p])%Mod+anss)%Mod;
					if(
*/	
#define qaq
#ifdef qaq		
			hzh[j][j]=0;
			for(int p=j-1;p>=i;p--){
				hzh[p][j]=(dp[p][j-p+1]+hzh[p+1][j])%Mod;
			}//puts("qqq");
			if(h>0){
				for(int p=i+1;p<=j-2;p++){
					int q;
					if(s[p]==0||s[p]==3)dp[i][h]=(dp[i][h]+(q=1ll*
					(((hzh[p+1][j]-hzh[minn(minn(rgk[p],p+k),j-1)+1][j])%Mod+Mod)%Mod)
					*dp[i][p-1-i+1]%Mod))%Mod;
				
				//	if(s[p]==0&&h==7&&i==1)printf("k61k%d %d %d %d \n",i,p,j,q);
				}
				
			}
			
			for(int p=i+1;p<=j-1;p++){
				dp[i][h]=(dp[i][h]+(1ll*dp[i][p-i+1]*dp[p+1][j-(p+1)+1]%Mod))%Mod;
			//	if(h==6&&i==1)printf("k61k%d %d %d %d \n",i,p,j,(1ll*dp[i][p-i+1]*dp[p+1][j-(p+1)+1]%Mod));
			}
#else 
			for(int g1=i+1;g1<=j;g1++)
				for(int g2=g1-1;g2+1<j;g2++)if(g2-g1+1<=k){
					if(g1-1-i+1>0&&j-(g2+1)+1>0)dp[i][h]+=dp[i][g1-1-i+1]*avi[g1][g2]*dp[g2+1][j-(g2+1)+1];
				//	if(h==6&&i==1)printf("k61k%d %d %d  \n",g1,g2,( dp[i][g1-1-i+1]*avi[g1][g2]*dp[g2+1][j-(g2+1)+1]));
				}
		//	printf("ooo"); 
					 
#endif
//title 3


			if((s[i]==1||s[i]==0)&&(s[j]==2||s[j]==0)){
				for(int p=i+1;p<j-1;p++){
					if(j-1-(p+1)+1<=k)dp[i][h]=(dp[i][h]+(dp[i+1][p-(i+1)+1]*avi[p+1][j-1]))%Mod;
					if(p-(i+1)+1<=k)dp[i][h]=(dp[i][h]+(dp[p+1][j-1-(p+1)+1]*avi[i+1][p]))%Mod;
				}
				dp[i][h]=(dp[i][h]+dp[i+1][j-1-(i+1)+1])%Mod;
			}
			

		//	printf("%d %d\n",i,i+h-1);
			
		}
//	printf("p%d\n",dp[2][n-2]);
//	printf("p%d\n",dp[2][4]);
//	printf("a%d\n",dp[1][6]);
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;i+j-1<=n;j++){
//			printf("qqq%d %d %d\n",i,i+j-1,dp[1][j]);
//		}
//	}
	
	printf("%d\n",dp[1][n]);
	return 0;
}
			
			
			
			
			
			
			
			
			
			
			
