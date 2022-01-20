#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define N 100010
using namespace std;
const ll mod=1e9+7;
ll n,kk,a[110],ans=0,q[110],h;
char c[110];

void check(){
	
	
	h=0;
	ll sum1=0,sum2=0;
	for(ll i=1;i<=n;i++){if(!a[i])sum1++;if(a[i]==1)sum2++;}
	if(sum1!=sum2)return ;
	if(a[1]!=0||a[n]!=1)return ;
	for(ll i=1;i<=n;i++){
		if(!a[i])q[++h]=i;
		if(a[i]==1){
			if(!h)return ;
			ll flag=0;
			for(ll j=q[h]+1;j<i;j++)if(a[j]==0||a[j]==1){flag=1;break;}
			if(flag==0&&i-q[h]-1>kk)return ;
			if(flag&&a[q[h]+1]==2&&a[i-1]==2)return ;
			h--;
		}
	}
	//for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	ans++;
	return ;
}

void dfs(ll x){
	if(x==n+1){
		check();
		return ;
	}
	if(c[x]=='('){
		a[x]=0;
		dfs(x+1);
	}
	if(c[x]==')'){
		a[x]=1;
		dfs(x+1);
	}
	if(c[x]=='*'){
		a[x]=2;
		dfs(x+1);
	}
	if(c[x]=='?'){
		a[x]=0;
		dfs(x+1);
		a[x]=1;
		dfs(x+1);
		a[x]=2;
		dfs(x+1);
	}
}


int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld%s",&n,&kk,c+1);
	
	dfs(1);
	cout<<ans<<endl;
	
	
	
	
	/*if(c[n]=='('||c[n]=='*'||c[1]==')'||c[1]=='*'){
		cout<<"0"<<endl;
		return 0;
	}
	f[1][1][0][0]=1;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=n;j++){
			//f i,j,0,0 (
			if(c[i]=='('||c[i]=='?'){
				f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][0][0])%mod;//i+1 : (	
				if(j)f[i+1][j-1][0][1]=(f[i+1][j-1][0][1]+f[i][j][0][0])%mod;//i+1 : )	
				f[i+1][j][1][2]=(f[i+1][j][1][2]+f[i][j][0][0])%mod;//i+1 : *
			}
			//f i,j,0,1 )
			if(c[i]==')'||c[i]=='?'){
				f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][0][1])%mod;//i+1 : (	
				if(j)f[i+1][j-1][0][1]=(f[i+1][j-1][0][1]+f[i][j][0][1])%mod;//i+1 : )	
				f[i+1][j][1][2]=(f[i+1][j][1][2]+f[i][j][0][1])%mod;//i+1 : *
			}
			//f i,j,k,2 *
			if(c[i]=='*'||c[i]=='?'){
				for(ll k=1;k<=kk;k++){
					f[i+1][j+1][0][0]=(f[i+1][j+1][0][0]+f[i][j][k][2])%mod;//i+1 : (	
					if(j)f[i+1][j-1][0][1]=(f[i+1][j-1][0][1]+f[i][j][k][2])%mod;//i+1 : )	
					if(k!=kk)f[i+1][j][k+1][2]=(f[i+1][j][k+1][2]+f[i][j][k][2])%mod;//i+1 : *
				}
			}
		}
	}
	//cout<<f[3][2][0][0]<<" "<<f[3][0][0][1]<<" "<<f[3][1][2][2]<<endl;
	//cout<<f[4][0][0][1]<<endl;
	//cout<<f[4][1][0][0]<<endl;
	cout<<f[4][3][0][0]<<" "
		<<f[4][1][0][1]<<" "
		<<f[4][2][1][2]<<" "
		<<f[4][1][0][0]<<" "
		<<f[4][0][1][2]<<" "
		<<f[4][2][0][0]<<" "
		<<f[4][0][0][1]<<" "
		<<f[4][1][3][2]<<" "<<endl;
	
	/*cout<<f[5][3][1][2]<<" "
		<<f[5][1][1][2]<<" "
		<<f[5][2][2][2]<<" "
		<<f[5][1][1][2]<<" "
		<<f[5][0][2][2]<<" "
		<<f[5][2][1][2]<<" "
		<<f[5][0][1][2]<<" "<<endl;
	
	
	
	cout<<f[n][0][0][1]<<endl;*/
	return 0;
}
/*

4 2
(*?)

7 3
(*??*??

(**)*()   f[4][0][0][1]
(**(*))   f[4][2][0][0]
(*(**))   f[4][2][1][2] //
(*)**()   f[4][0][1][2]
(*)(**)   f[4][1][0][0]




*/
