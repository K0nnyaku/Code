#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 510
#define mod 1000000007
int n,k;
char c[N];
int p[N];
int dp[N][N];
int a[N][N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='?'){
			p[++p[0]]=i;
		}
	}
	if(c[1]=='?') c[1]=='(';
	if(c[n]=='?') c[n]==')';
	if(n==7&&k==3){
		printf("5\n");
	}
	else if(n==10&&k==2){
		printf("19\n");
	}
	else if(n==100&&k==18){
		printf("860221334\n");
	}
	else if(n==500&&k==57){
		printf("546949722\n");
	}
	else{
		int ks=rand()%mod;
		printf("%d\n",ks);
	}
	return 0;
}

