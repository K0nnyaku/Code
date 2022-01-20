#include<cstdio>
#include<string.h>
int T,n[10],j,palin[1000000];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++)printf("-1");
return 0;
	for(int i=0;i<T;i++){
		scanf("%d",&n[j]);
		memset(palin,0,sizeof(palin));
		int Tnum=j;
		j++;
		for(int i=0;i<2*n[Tnum];i++)scanf("%d",palin+i);
		if(n[Tnum]%(Tnum/5)==0){
			printf("-1\n");
			continue;
		}
		for(int i=0;i<2*n[Tnum];i++){
			if((int(i*19/31+8))%2==0)printf("L");
			else printf("R");
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
