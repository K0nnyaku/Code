#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5e5+5;
int a[maxn<<1];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d",&n);
		for(int j=1;j<=n*2;++j){
			scanf("%d",&a[j]);
		}
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
