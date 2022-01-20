#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 500010
int T;
int n;
int a[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		printf("-1\n");
	}
	return 0;
} 

