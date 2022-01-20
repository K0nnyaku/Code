#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t,l;
int c1[1000010];

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf("%d",&t);
	if(t==1) printf("%d",-1);
	else{
		for(int i=0;i<t;i++){
			scanf("%d",&l);
			for(int j=0;j<2*l;j++){
				scanf("%d",&c1[j]);
			}
			for(int j=0;j<2*l;j++){
				printf("%c",'L');
			}
			printf("\n");
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
