#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int t,n; 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		int a;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a);
		}
		for(int i=1;i<=2*n;i++){
			printf("L");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

