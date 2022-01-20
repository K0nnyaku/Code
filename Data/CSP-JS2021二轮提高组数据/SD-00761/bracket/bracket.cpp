#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<cstring>
#include<map>
#include<cmath>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*f;
}
const int N=505,mod=1e9+7;
int n,K;
int f[N][N][N][2];
char s[N];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&K);
	scanf("%s",s+1);
	if(s[1]!='('&&s[1]!='?'){
		printf("0\n");
		return 0;
	}
	s[1]='(';
	if(s[n]!=')'&&s[n]!='?'){
		printf("0\n");
		return 0;
	}
	s[n]=')';
	
//	for(int i=1;i<=n;i++) s[i]=s[i+1];
//	n-=2;
	
//	for(int i=1;i<=n;i++) cout<<s[i];
//	printf("\n");
	
	f[0][0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<=K;k++){
				if(s[i+1]=='('){
					if(k>0) f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][k][1])%mod;
					else f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][0][0])%mod;
				}
				if(s[i+1]==')'&&j>=1){
					if(k>0) f[i+1][j-1][0][0]=(f[i+1][j-1][0][0]+f[i][j][k][1])%mod;
					else f[i+1][j-1][0][0]=(f[i+1][j-1][0][0]+f[i][j][k][0])%mod;
				}	
				if(s[i+1]=='*'&&k<K){
					if(k>0) f[i+1][j][k+1][1]=(f[i+1][j][k+1][1]+f[i][j][k][1])%mod;
					else f[i+1][j][k+1][1]=(f[i+1][j][k+1][1]+f[i][j][k][0])%mod;
				}	
				if(s[i+1]=='?'){
					if(k>0){
						f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][k][1])%mod;
						if(j>=1) f[i+1][j-1][0][0]=(f[i+1][j-1][0][0]+f[i][j][k][1])%mod;
						if(k<K) f[i+1][j][k+1][1]=(f[i+1][j][k+1][1]+f[i][j][k][1])%mod;
					}
					else{
						f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][0][0])%mod;
						if(j>=1) f[i+1][j-1][0][0]=(f[i+1][j-1][0][0]+f[i][j][k][0])%mod;
						if(k<K) f[i+1][j][k+1][1]=(f[i+1][j][k+1][1]+f[i][j][k][0])%mod;
					}
				}
			}
		}
	}
	
	printf("%d\n",f[n][0][0][0]);
	return 0;
}
/*
7 3
(*??*??
*/

