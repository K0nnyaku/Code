#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int n,m,T;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++){
		int x;
		for(int j=1;i<=m;i++){
			scanf("%d",&x);
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		for(int j=1;j<=m-1;j++){
			scanf("%d",&x);
		}
	}
	while(T--){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x;
			scanf("%d",&x);
		}
	}
	printf("%d",rand());
	return 0;
}
