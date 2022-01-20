#include<iostream>
#include<cstdio>
using namespace std;
const int N=5*1e5;
int n,a[2*N];
int T;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T==1){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			printf("L");
		}
	}
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		printf("-1\n");
	}
	return 0;
}
