#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
int n,T;
int num[500233];
bool flag;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=false;
		scanf("%d",&n);
		int QWQ=(n<<1);
		for(int i=1;i<=QWQ;++i){
			scanf("%d",&num[i]);
		}
		for(int i=1,j=QWQ;i<=j;++i,--j){
			if(num[i]!=num[j]){
				printf("-1\n");
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(register int i=1;i<=n;++i)
			printf("L");
		for(register int i=1;i<=n;++i)
			printf("R");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

