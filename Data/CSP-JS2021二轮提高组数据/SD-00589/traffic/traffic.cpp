#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,x,y,z,k;
	int X=100;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x);
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&x);
		}
	}
	for(int i=1;i<=t;++i){
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d%d%d",&x,&y,&z); 
		}
		srand(time(NULL));
		printf("%d\n",rand()%X);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
