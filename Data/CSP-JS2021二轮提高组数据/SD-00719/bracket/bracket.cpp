#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define mp make_pair
#define pb push_back
#define vi vector<int>
typedef long long ll;
using namespace std;
#define int long long
int read(){
	char c=getchar();int s=0,x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=505;
const int mod=1e9+7;
int n,m,s[N],q[N];
char a[N];
int f[N][N][2],g[N],h[N],ng[N];
int calc(int l,int r){
	return s[r]-s[l-1]+q[r]-q[l-1];
}
int jl(int l,int r){
	if(l>r)return 0;
	return (r-l+1);
}
int add(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}
int dp(int l,int r,int t){
	if(f[l][r][t]!=-1)return f[l][r][t];
	if(l>r){
		f[l][r][0]=f[l][r][1]=0;return 0;
	}
	if(l==r){
		f[l][r][0]=f[l][r][1]=0;return 0;
	}
	if(l+1==r && t==1){
		if(t==1){
			f[l][r][t]=0;
			if((a[l]=='?' || a[l]=='(') && (a[r]=='?' || a[r]==')'))f[l][r][1]=1;
		}
		else f[l][r][t]=0;
		return f[l][r][t];
	}
	f[l][r][t]=0;
	if(t==1){
		bool flag=0;
		if((a[l]=='?' || a[l]=='(') && (a[r]=='?' || a[r]==')'))flag=1;
		if(flag){
			if(calc(l+1,r-1)==jl(l+1,r-1) && jl(l+1,r-1)<=m)f[l][r][1]=1;
			f[l][r][1]=add(f[l][r][1],add(dp(l+1,r-1,0),dp(l+1,r-1,1)));
			int flag=0;
			for(int k=l+1;k<r-1;k++){
				if(calc(l+1,k)==jl(l+1,k) && jl(l+1,k)<=m){
					if(flag){
						new char;
					}
					f[l][r][1]=add(f[l][r][1],add(dp(k+1,r-1,0),dp(k+1,r-1,1)));
				}
				else break;
			}
			for(int k=r-1;k>l-1;k--){
				if(calc(k,r-1)==jl(k,r-1) && jl(k,r-1)<=m){
					f[l][r][1]=add(f[l][r][1],add(dp(l+1,k-1,0),dp(l+1,k-1,1)));
				}
				else break;
			}
		}
		return f[l][r][t];
	}
	for(int k=l;k<=r;k++){
		f[l][r][0]=add(f[l][r][0],1ll*dp(l,k,1)*add(dp(k+1,r,0),dp(k+1,r,1))%mod);
	}
	for(int k=l;k<=r;k++){
		int tmp=dp(k,r,0);
		tmp=dp(k,r,1);
	}
	g[r+1]=0;
	for(int k=r;k>=l;k--){
		g[k]=add(g[k+1],add(dp(k+1,r,0),dp(k+1,r,1)));
	}
	for(int k=l;k<=r;k++){
		if(ng[k]){
			int pos=min(ng[k],r);
			f[l][r][0]=add(f[l][r][0],1ll*dp(l,k-1,1)*(g[k]-g[pos+1]+mod)%mod);
		}
	}
	return f[l][r][t];
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();m=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1];
		if(a[i]=='?')s[i]++;
		q[i]=q[i-1];
		if(a[i]=='*')q[i]++;
	}
	for(int k=1;k<=n;k++){
		for(int j=k;j<=n;j++){
			if(calc(k,j)==jl(k,j) && calc(k,j)<=m){
				ng[k]=j;
			}
		}
	}
	memset(f,-1,sizeof(f));
	cout<<add(dp(1,n,0),dp(1,n,1));
	return 0;
}
/*
10 2
???(*??(?)
6 1
(??(??
7 3
(*??*??

*/
