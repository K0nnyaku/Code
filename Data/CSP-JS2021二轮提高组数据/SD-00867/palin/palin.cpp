#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int a[1000001];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n;
	
	while(t--){
		scanf("%d",&n);
		int opt=2*n;
		for(int i=1;i<=opt;++i){
			scanf("%d",&a[i]);
		}
		int j=1;
		if(a[n]==a[n-1]){
			printf("-1");
			printf("\n");
			continue;
		}
		for(int i=1;i<=2*n;++i){
			
			if(a[i]==a[i-j]){
				printf("R");
				
			}
			else printf("L");
			j++;
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
