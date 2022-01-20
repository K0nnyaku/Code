#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int T;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i){
			int tmp;
			scanf("%d",&tmp);
			printf("L");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
