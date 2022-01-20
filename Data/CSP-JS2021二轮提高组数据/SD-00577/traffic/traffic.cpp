#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 3000007
using namespace std;
int f[MAXN];
int n,m,k;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int x,h=0,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			if(j==m)f[++h]=x;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&x);
			if(j==m-1) f[++h]=x;
		}
	} 
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int i=1;i<=x;i++){
			scanf("%d%d%d",&a,&b,&c);
		}
	}
	sort(f+1,f+1+h);
	long long ans=0;
	for(int i=1;i<h;i++){
		ans+=f[i];
	}
	for(int i=1;i<=k;i++){
		printf("%d\n",ans);
		ans+=f[h];
	}
	return 0;
} 
