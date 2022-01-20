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
//#define int long long
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
int n,m,T,s,x[N],y[N],z[N],c[N*4],a[N][N],b[N][N],v[N][N][2],f[N][N];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<n;i++){
		for(int k=1;k<=m;k++){
			a[i][k]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<m;k++){
			b[i][k]=read();
		}
	}
	for(int i=1;i<=T;i++){
		s=read();
		memset(v,0,sizeof(v));
		for(int k=1;k<=s;k++){
			x[k]=read();y[k]=read();z[k]=read();
			if(y[k]<=m){
				v[1][y[k]][z[k]^1]=x[k];
			}
			else if(y[k]<=m+n){
				v[y[k]-m][m][z[k]^1]=x[k];
			}
			else if(y[k]<=2*m+n){
				v[n][m-(y[k]-m-n)+1][z[k]^1]=x[k];
			}
			else {
				v[n-(y[k]-2*m-n)+1][1][z[k]^1]=x[k];
			} 
		}
		int ans=1e9,tmp=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
				tmp=tmp+v[k][j][0];
			}
		}
		ans=min(ans,tmp);tmp=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
				tmp=tmp+v[k][j][1];
			}
		}
		ans=min(ans,tmp);
		if(n>5){
			for(int i=0;i<=1;i++){
				for(int k=0;k<=1;k++){
					for(int j=1;j<=n;j++){
						for(int l=1;l<=m;l++){
							f[j][l]=0;
						}
					}
					f[x[1]][y[1]]=i;
					f[x[2]][y[2]]=k;
					int tmp=0;
					for(int j=1;j<=n;j++){
						for(int l=1;l<=m;l++){
							tmp=tmp+v[j][l][f[j][l]];
							if(j<n && f[j+1][l]!=f[j][l])tmp=tmp+a[j][l];
							if(l<m && f[j][l]!=f[j][l+1])tmp=tmp+b[j][l];
						}
					}
					ans=min(ans,tmp);
					tmp=0;
					for(int j=1;j<=n;j++){
						for(int l=1;l<=m;l++){
							f[j][l]=1;
						}
					}
					f[x[1]][y[1]]=i;
					f[x[2]][y[2]]=k;
					tmp=0;
					for(int j=1;j<=n;j++){
						for(int l=1;l<=m;l++){
							tmp=tmp+v[j][l][f[j][l]];
							if(j<n && f[j+1][l]!=f[j][l])tmp=tmp+a[j][l];
							if(l<m && f[j][l]!=f[j][l+1])tmp=tmp+b[j][l];
						}
					}
					ans=min(ans,tmp);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(!ans){
			puts("0");
			continue;
		}
		for(int k=0;k<(1<<(n*m));k++){
			int tmp=0;
			for(int j=1;j<=n;j++){
				for(int l=1;l<=m;l++){
					int id=(j-1)*m+l;
					if(k&(1<<(id-1))){
						f[j][l]=1;
					} 
					else f[j][l]=0;
				}
			}
			for(int j=1;j<=n;j++){
				for(int l=1;l<=m;l++){
					tmp=tmp+v[j][l][f[j][l]];
					if(j<n && f[j+1][l]!=f[j][l])tmp=tmp+a[j][l];
					if(l<m && f[j][l]!=f[j][l+1])tmp=tmp+b[j][l];
				}
			}
			ans=min(ans,tmp);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
2 3 2
9 4 7
3 8
10 5
2
19 3 1
17 9 0
1
19 3 1
*/
